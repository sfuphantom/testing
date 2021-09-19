/*
 * shutdown.c
 *
 *  Created on: Sep 18, 2021
 *      Author: Rafael Guevara
 */

#include "shutdown.h"

/* Shutdown Variables */

static shutdown_fail;

static shutdown_signal;

static shutdown_expected;

/* Shutdown Interrupts */

void initializeShutdownInterrupt(){

    hetInit();

    vimInit();

    //Enable Interrupts
    edgeEnableNotification(VCU_FLT_REG, VCU_FLT_EDGE);

    _enable_IRQ();

}

static void readShutdownSignal(){

    shutdown_signal = gioGetBit( VCU_FLT_PORT, VCU_FLT_PIN );
}


void shutdown_timeout_callback(int ID){

    shutdown_fail = true;

    UARTprintf("SHUTDOWN SIGNAL HAS TIMED OUT\r\n");

    stopAllTimers();

}

void shutdown_callback(){

    if( shutdown_expected == getShutdownSignal() ){

        initializeVCU();


    }else{

        stopAllTimers();

        shutdown_fail = true;

    }

}


uint8_t getShutdownSignal(){

    return shutdown_signal;
}

void setShutdownOccurence(bool expected_result){

    setTimerID(VALIDATION, 0)

    setTimerCallback(VALIDATION, shutdown_timeout_callback);

    startTimer(VALIDATION, SHUTDOWN_TIMEOUT_PERIOD);

    shutdown_expected = expected_result;
}

bool getShutdownResult(){

    return shutdown_fail;
}

void edgeNotification(hetBASE_t * hetREG,uint32 edge)
{
/*  enter user code between the USER CODE BEGIN and USER CODE END. */
/* USER CODE BEGIN (37) */

    if(hetREG == VCU_FLT_REG && edge == VCU_FLT_EDGE){

        readShutdownSignal();

        shutdown_callback();
    }



/* USER CODE END */
}





