/*
 * timers.c
 *
 *  Created on: Apr 26, 2021
 *      Author: Rafael Guevara
 */
#include "timer.h"

/* Static Functions */

static void executeTimerCallback(Peripheral peripheral_timer){

    xTimers[peripheral_timer].callback( xTimers[peripheral_timer].timer, getTimerID(peripheral_timer) );
}

static uint8_t isExpired(Peripheral peripheral_timer){

    return (ticks % xTimers[peripheral_timer].period  == 0) && (ticks != 0);
}

void timerInit(){

    rtiInit();

    rtiEnableNotification(rtiNOTIFICATION_COMPARE0);

    _enable_IRQ();

    //initialize timers in blocked state

    Peripheral peripheral_timer;

    for(peripheral_timer = 0; peripheral_timer < NUM_TIMERS; peripheral_timer++)
           stopTimer(peripheral_timer);
}

void rtiNotification(uint32 notification)
{
/*  enter user code between the USER CODE BEGIN and USER CODE END. */

    //check timer expirations

    Peripheral peripheral_timer;

    for(peripheral_timer = 0; peripheral_timer < NUM_TIMERS; peripheral_timer++){

        if( isExpired(peripheral_timer) && !isBlocked(peripheral_timer) ){
            executeTimerCallback(peripheral_timer);
        }
    }

    ticks++;

    //deal with overflow
    if(ticks == 100001){
        ticks = 0;
    }


}

/* Getters */

uint8_t isBlocked(Peripheral peripheral_timer){

    return (xTimers[peripheral_timer].stop);
}

int getTimerID(Peripheral peripheral_timer){

    return xTimers[peripheral_timer].ID;
}

int getTimerPeriod(Peripheral peripheral_timer){

    return xTimers[peripheral_timer].period;
}


/* Setters */

void xTimerSet(char* name, Peripheral peripheral_timer, Callbackfunc callback, int ID){

    xTimers[peripheral_timer].name = name;

    setTimerID(peripheral_timer, ID);

    setTimerPeriod(peripheral_timer, 0);

    stopTimer(peripheral_timer);

    xTimers[peripheral_timer].callback = callback;

    xTimers[peripheral_timer].stop = true;

    xTimers[peripheral_timer].timer = 0; //default
}

void startGlobalTimer(){
    ticks = 0;
    rtiStartCounter(rtiCOUNTER_BLOCK0);
}

void stopGlobalTimer(){

    rtiStopCounter(rtiCOUNTER_BLOCK0);
}

void stopAllTimers(){

    Peripheral peripheral_timer;

    for(peripheral_timer = 0; peripheral_timer < NUM_TIMERS; peripheral_timer++){
        stopTimer(peripheral_timer);
    }
}

//end of test functions

void startTimer(Peripheral peripheral_timer, Timer timer, int period){

    xTimers[peripheral_timer].stop = false;

    xTimers[peripheral_timer].timer = timer;

    setTimerPeriod(peripheral_timer, period);
}

void stopTimer(Peripheral peripheral_timer){

    xTimers[peripheral_timer].stop = true;
}

void setTimerID(Peripheral peripheral_timer,int ID){

    xTimers[peripheral_timer].ID = ID;
}

void setTimerPeriod(Peripheral peripheral_timer,int period){
    xTimers[peripheral_timer].period = period;
}

