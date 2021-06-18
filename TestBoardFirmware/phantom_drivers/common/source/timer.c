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

void rtiNotification(uint32 notification)
{

//    UARTprintf("Global timer expired!\r\n");


    //check timer expirations

    Peripheral peripheral_timer;

    for(peripheral_timer = 0; peripheral_timer < NUM_TIMERS; peripheral_timer++){

        if( isExpired(peripheral_timer) && !isBlocked(peripheral_timer) ){
            executeTimerCallback(peripheral_timer);
        }
    }

    ticks++; //will overflow after ~ 49 days...
}

void timerInit(){

    rtiInit();

    rtiEnableNotification(rtiNOTIFICATION_COMPARE0);

    _enable_IRQ();

    //initialize timers to blocked state

    Peripheral peripheral_timer;

    for(peripheral_timer = 0; peripheral_timer < NUM_TIMERS; peripheral_timer++)
           stopTimer(peripheral_timer);
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

bool timers_complete(){

    bool timers_complete = true;

    //check all status of all timers
    Peripheral peripheral_timer;

   for(peripheral_timer = 0; peripheral_timer < NUM_TIMERS; peripheral_timer++){

       if( !isBlocked(peripheral_timer) )
           timers_complete = false;

   }//loop through all peripheral timers


    #ifdef TIMER_DEBUG
    if(timers_complete) UARTprintf("Tests Completed!\r\n\n");
    #endif

   return timers_complete;

}


/* Setters */

void xTimerSet(char* name, Peripheral peripheral_timer, Callbackfunc callback, int ID){

    setTimerID(peripheral_timer, ID);

    setTimerPeriod(peripheral_timer, 0);

    stopTimer(peripheral_timer);

    xTimers[peripheral_timer].name = name;

    xTimers[peripheral_timer].callback = callback;

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

void startTimer(Peripheral peripheral_timer, TestTimer_t timer, int period){

    xTimers[peripheral_timer].timer = timer;

    setTimerPeriod(peripheral_timer, period);

    xTimers[peripheral_timer].stop = false;
}

void stopTimer(Peripheral peripheral_timer){


    #ifdef TIMER_DEBUG

    switch(peripheral_timer){

        case APPS:

            UARTprintf("APPS TEST FINISHED!...\r\n\n");

            break;

        case BSE:

            UARTprintf("BSE TEST FINISHED!...\r\n\n");

            break;

        case HVCT:

            UARTprintf("HVCT TEST FINISHED!...\r\n\n");

            break;


        //add more peripherals for debugging here...

        default:

            UARTprintf("SOME TEST FINSIHED!...\r\n\n");

            break;

    }//switch case statement

    #endif

    xTimers[peripheral_timer].stop = true;
}

void setTimerID(Peripheral peripheral_timer, int ID){

    xTimers[peripheral_timer].ID = ID;
}

void setTimerPeriod(Peripheral peripheral_timer,int period){

    xTimers[peripheral_timer].period = period;
}

