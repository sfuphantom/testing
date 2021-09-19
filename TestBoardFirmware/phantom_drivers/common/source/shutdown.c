/*
 * shutdown.c
 *
 *  Created on: Sep 18, 2021
 *      Author: Rafael Guevara
 */

#include "shutdown.h"

/* Shutdown Variables */

static uint8_t shutdown_timeout; // tells user if timeout has occurred

static uint8_t shutdown_pass; // indicates pass or fail w.r.t. the shutdown signal

static uint8_t shutdown_signal; // stores shutdown GPIO value

static uint8_t shutdown_expected; // indicates the expected result from shutdown; set by the user but defaulted to false

/* Static Functions */

static void readShutdownSignal(){

    shutdown_signal = gioGetBit( VCU_FLT_PORT, VCU_FLT_PIN );
}

static void resetShutdownVars(){

    readShutdownSignal();

    shutdown_pass     = false;

    shutdown_timeout  = false;

    shutdown_expected = false;
}

void initializeShutdownInterrupt(){

    hetInit();

    vimInit();

    gioInit();

    //Enable Interrupts
    edgeEnableNotification(VCU_FLT_REG, VCU_FLT_EDGE);

    _enable_IRQ();

    resetShutdownVars();
}


/* Getters and Setters */

// timeout     pass     result
//  0           0        false (either...interrupt was triggered and for some reason the result was unexpected -> test run is stopped OR nothing has happened yet so the test keeps waiting)
//  0           1        true  (interrupt was triggered as expected and test can move on)
//  1           0        test run is already stopped (validation stage will commence and check for timeout or pass)
//  1           1        test run is already stopped (validation stage will commence and check for timeout or pass)

uint8_t isShutdownPass(){

    return shutdown_pass;
}

uint8_t isShutdownTimeout(){

    return shutdown_timeout;
}

uint8_t getShutdownSignal(){

    return shutdown_signal;
}

uint8_t getExpectedShutdownResult(){

    return expected_shutdown;
}

/*
* Fn: setShutdownOccurence
* Purpose: Sets the expected result of shutdown and immediately starts a timeout
*/
void setShutdownOccurence(bool expected_result){


    resetShutdownVars();

    // Start shutdown timeout
    setTimerID(VALIDATION, 0);
    setTimerCallback(VALIDATION, shutdown_timeout_callback);
    startTimer(VALIDATION, SHUTDOWN_TIMEOUT_PERIOD);

    // set expected shutdown
    shutdown_expected = expected_result;
}

/* Callback Functions */

void shutdown_timeout_callback(int ID){

    shutdown_pass = false; // test has FAILED

    shutdown_timeout = true;

    UARTprintf("SHUTDOWN SIGNAL HAS TIMED OUT\r\n");

    readShutdownSignal();

    stopAllTimers(); // stop test run
}

void shutdown_callback(){

    readShutdownSignal();

    if( shutdown_expected == getShutdownSignal() ){

        //TODO: MAKE FUNCTION CALL TO INITIALIZE/RESET BMS AS WELL DEPENDING ON TEST BOARD MODE

        initializeVCU(); // this signal was expected; reset the VCU and continue with test run

        shutdown_pass = true; // test has PASSED

    }else{

        stopAllTimers(); // signal was unexpected; stop test run and fail test w.r.t. the shutdown signal

        shutdown_pass = false;
    }

    setShutdownOcurrence(false); // reset expected result to false state
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





