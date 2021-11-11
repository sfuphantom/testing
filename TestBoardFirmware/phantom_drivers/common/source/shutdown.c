/*
 * shutdown.c
 *
 *  Created on: Sep 18, 2021
 *      Author: Rafael Guevara
 */

#include "shutdown.h"

/* Shutdown Variables */

typedef struct{

    uint8_t timeout; // tells user if timeout has occurred

    uint8_t pass; // indicates pass or fail w.r.t. the shutdown signal

    uint8_t signal; // stores shutdown GPIO value

    uint8_t expected; // indicates the expected result from shutdown; set by the user but defaulted to false

    uint8_t result_ready; // result is valid

}shutdown_vars;

static shutdown_vars shutdown;
static shutdown_vars* shutdown_ptr = &shutdown;

/* Static Functions */

static void readShutdownSignal(){

    #ifdef SHUTDOWN_INTERRUPT_DEBUG
    UARTprintf("Reading shutdown signal...\r\n");
    #endif

    shutdown_ptr->signal = gioGetBit( VCU_FLT_PORT, VCU_FLT_PIN );
}

static void resetShutdownVars(){

    #ifdef SHUTDOWN_INTERRUPT_DEBUG
    UARTprintf("Resetting shutdown variables...\r\n");
    #endif

    shutdown_ptr->pass         = false;

    shutdown_ptr->timeout      = false;

    shutdown_ptr->expected     = false;

    shutdown_ptr->result_ready = false;
}

void initializeShutdownInterrupt(){

    hetInit();

    vimInit();

    gioInit();

    //Enable Interrupts
    edgeEnableNotification(VCU_FLT_REG, VCU_FLT_EDGE);

//    _enable_IRQ();

    resetShutdownVars();
}


/* Getters and Setters */

// result_ready     pass     result
//  0               0        -1
//  0               1        -1
//  1               0        pass(var)
//  1               1        pass(var)
int8_t isShutdownPass(){

    #ifdef SHUTDOWN_INTERRUPT_DEBUG
//    UARTprintf( shutdown_pass ? "Test has passed w.r.t. the shutdown signal!\r\n" : "Shutdown signal is currently stale...\r\n" );
    #endif

    return shutdown_ptr->result_ready ? shutdown_ptr->pass : -1;
}

uint8_t isShutdownTimeout(){

    return shutdown_ptr->timeout;
}

uint8_t getShutdownSignal(){

    uint8_t ret = shutdown_ptr->signal;

    return SHUTDOWN_ACTIVE_LOW ? ret : !ret; // flip the logic if it turns out shutdown signal is active low instead
}

uint8_t getExpectedShutdownResult(){

    return shutdown_ptr->expected;
}

/*
* Fn: setShutdownOccurence
* Purpose: Sets the expected result of shutdown and immediately starts a timeout
*/
void setShutdownOccurence(bool expected_result){

    #ifdef SHUTDOWN_INTERRUPT_DEBUG
    UARTprintf( expected_result ? "Now expecting a shutdown to occur...\r\n" : "Now expecting no shutdown to occur...\r\n" );
    #endif

    resetShutdownVars();

    // set expected shutdown
    shutdown_ptr->expected = expected_result;

    // Start shutdown timeout
    setTimerID(VALIDATION, 0);
    setTimerCallback(VALIDATION, shutdown_timeout_callback);
    startTimer(VALIDATION, SHUTDOWN_TIMEOUT_PERIOD, true);
}

/* Callback Functions */

void shutdown_timeout_callback(int ID){

    #ifdef SHUTDOWN_INTERRUPT_DEBUG
    UARTprintf("SHUTDOWN SIGNAL HAS TIMED OUT\r\n\n");
    #endif

    // test has FAILED via timeout
    shutdown_ptr->pass         = false;
    shutdown_ptr->result_ready = true;
    shutdown_ptr->timeout      = true;

    readShutdownSignal();
    stopTimer(VALIDATION);
}

void shutdown_callback(){

    readShutdownSignal();

    // prevent overwriting a test result
    if(shutdown_ptr->result_ready){
        return;
    }

    //shutdown signal is active low
    if( shutdown_ptr->expected != getShutdownSignal() ){ //don't overwrite failed result with passed result

        #ifdef SHUTDOWN_INTERRUPT_DEBUG
        UARTprintf("Shutdown signal has arrived as expected! Test has passed w.r.t. the shutdown\r\n");
        #endif

        //TODO: MAKE FUNCTION CALL TO INITIALIZE/RESET BMS AS WELL DEPENDING ON TEST BOARD MODE


        // this signal was expected; reset the VCU and continue with test run

        /***************** INTIIALIZE VCU ****************/

//        // reset VCU state
//        gioSetBit(RESET_PORT, RESET_PIN, 1);
//
//        delayms(500);
//
//        gioSetBit(RESET_PORT, RESET_PIN, 0);
//
//        // put VCU into state running
//        gpio_process(RTD_NORMAL_PROCEDURE);

        // test has PASSED via an expected signal
        shutdown_ptr->pass = true;
        shutdown_ptr->result_ready = true;

        stopTimer(VALIDATION);

    // shutdown signal is active low; if expected (true for shutdown, false for no shutdown) equals the gpio signal test fails
    }else if( shutdown_ptr->expected == getShutdownSignal() ){

        #ifdef SHUTDOWN_INTERRUPT_DEBUG
        UARTprintf("An unexpected shutdown signal has been received. Test has now failed w.r.t. the shutdown\r\n");
        #endif

        // test has FAILED via unexpected signal
        shutdown_ptr->pass         = false;
        shutdown_ptr->result_ready = true;

        stopTimer(VALIDATION);
    }

    shutdown_ptr->expected = false; // reset expected result to false state
}

void edgeNotification(hetBASE_t * hetREG,uint32 edge)
{
/*  enter user code between the USER CODE BEGIN and USER CODE END. */
/* USER CODE BEGIN (37) */

    if(hetREG == VCU_FLT_REG && edge == VCU_FLT_EDGE){

        shutdown_callback();
    }

/* USER CODE END */
}


/* Quick Unit Tests */
#ifdef SHUTDOWN_UNIT_TESTS

/* Test Procedure: Don't do anything */

void shutdownStaleTest(){

    UARTprintf("\n\n****** Performing Shutdown Stale Unit Test ******\r\n\n");


    uint32_t eta;
    // do some test

    setShutdownOccurence(true);


    while(isShutdownPass() == SHUTDOWN_RESULT_INVALID){

        eta = getTimerETA(VALIDATION); // wait for result
    }

    // Timer should timeout

    delayms(2000);

    uint8_t result = (isShutdownTimeout() && !isShutdownPass());

    if(result == false){

        UARTprintf("Stale test failed...\r\n");

    }else{

        UARTprintf("Stale test passed!\r\n");
    }


    delayms(5000);
}

/* Test Procedure: Send a rising edge but set shutdown occurrence to true, should return a fail */

void shutdownUnexpectedTest(){

    uint32_t eta;
    UARTprintf("\n\n****** Performing Shutdown Unexpected Unit Test ******\r\n\n");

    // do some test

    setShutdownOccurence(true);


    while(isShutdownPass() == SHUTDOWN_RESULT_INVALID){

        eta = getTimerETA(VALIDATION); // wait for result
    }

    // Timer should not timeout

    delayms(2000);

    uint8_t result = !isShutdownPass();

    if(result == false){

        UARTprintf("Unexpected test failed...\r\n");
    }else{

        UARTprintf("Unexpected test passed!\r\n");
    }


    delayms(5000);

}

/* Test Procedure: Send a falling edge, but set shutdown occurrence to true, should return a true

*/
void shutdownExpectedTest(){


    uint32_t eta;

    UARTprintf("****** Performing Shutdown Expected Unit Test ******\r\n\n");

    // do some test

    setShutdownOccurence(true);

    while(isShutdownPass() == SHUTDOWN_RESULT_INVALID){

        eta = getTimerETA(VALIDATION); // wait for result
    }

    // Timer should not timeout

    delayms(2000);

    uint8_t result = isShutdownPass();


    if(result == false){

        UARTprintf("Expected test failed...\r\n");
    }else{

        UARTprintf("Expected test passed!\r\n");
    }

    delayms(5000);
}

void timeout_test(){

    uint32_t eta;

    setShutdownOccurence(true);


    while(true){

        if(isShutdownTimeout()){

            setShutdownOccurence(true);
        }

        eta = getTimerETA(VALIDATION);
    }
}

#endif





