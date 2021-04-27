/*
 * timers.c
 *
 *  Created on: Apr 26, 2021
 *      Author: Rafael Guevara
 */
#include "timers.h"

/* Static Functions */

static void executeTimerCallback(Timer timer){

    xTimers[timer].callback( timer, getTimerID(timer) );
}

static uint8_t isExpired(Timer timer){

    return (ticks % xTimers[timer].period  == 0);
}


void rtiNotification(uint32 notification)
{
/*  enter user code between the USER CODE BEGIN and USER CODE END. */

    //deal with overflow
    if(ticks + 1 == 100000)
        ticks = 0;


    //check timer expirations

    Timer timer;

    for(timer = 0; timer < NUM_TIMERS; timer++){

        if( isExpired(timer) && !isBlocked(timer) )

            executeTimerCallback(timer);
    }

    ticks++;

}

void timerInit(){

    rtiInit();

    rtiEnableNotification(rtiNOTIFICATION_COMPARE0);

    _enable_IRQ();
}

/* Getters */

uint8_t isBlocked(Timer timer){

    return (xTimers[timer].stop);
}

int getTimerID(Timer timer){

    return xTimers[timer].ID;
}

int getTimerPeriod(Timer timer){

    return xTimers[timer].period;
}


/* Setters */

void xTimerSet(Timer timer, Callbackfunc callback, int period,int ID){

    setTimerID(timer, ID);

    setTimerPeriod(timer, period);

    stopTimer(timer);

    xTimers[timer].callback = callback;
}

void startTimer(Timer timer){

    xTimers[timer].stop = false;
}

void stopTimer(Timer timer){

    xTimers[timer].stop = true;
}

void setTimerID(Timer timer,int ID){

    xTimers[timer].ID = ID;
}

void setTimerPeriod(Timer timer,int period){
    xTimers[timer].period = period;
}
