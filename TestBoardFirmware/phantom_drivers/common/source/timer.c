/*
 * timers.c
 *
 *  Created on: Apr 26, 2021
 *      Author: Rafael Guevara
 */
#include "timer.h"

/* Static Functions */

static void executeTimerCallback(Peripheral peripheral_timer){

    xTimers[peripheral_timer].callback( getTimerID(peripheral_timer) );
}

static uint8_t isExpired(Peripheral peripheral_timer){

    return (ticks % xTimers[peripheral_timer].period  == 0) && (ticks != 0);
}

void softwareTimerCallback(){

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

    #ifndef DEV_ENV
    rtiInit();
    rtiEnableNotification(rtiNOTIFICATION_COMPARE0);
    _enable_IRQ();
    #endif

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

void startTimer(Peripheral peripheral_timer, int period){

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


void setTimerCallback(Peripheral peripheral_timer, Callbackfunc timer_callback){

    if(timer_callback == NULL){

        UARTprintf("Cannot pass null as a timer callback.\r\n");
    }

    xTimers[peripheral_timer].callback = timer_callback;
}

unsigned int update_value(Peripheral peripheral, int MIN, int MAX, int STEP, int ID, bool is_ceil){

    bool is_neg = (STEP < 0);

    unsigned int ret = ( (MAX * is_neg) + (MIN * !is_neg) ) + ( STEP * ID ) ;

    //check ceiling and floor respectively
    if(ret > MAX && is_ceil){

        stopTimer(peripheral);

        ret = MAX;

    }else if(ret < MIN && !is_ceil){

        stopTimer(peripheral);

        ret = MIN;
    }

    setTimerID(peripheral, ++ID);

    return ret;

}

void defaultCallback(int ID){
    return;
}

void initializeTimers(){

    xTimerSet(
                "BSE", // name

                BSE, // peripheral

                defaultCallback, // callback function

                0 // ID
             );

    xTimerSet(
                "APPS", // name

                APPS, // peripheral

                defaultCallback, // callback function

                0 // ID
             );

    xTimerSet(
                 "HV_VS", // name

                 HV_VS, // peripheral

                 defaultCallback, // callback function

                 0 // ID
             );



    //add more peripheral timers here...


}

#ifdef DEV_ENV
// Hardware Functions

void rtiNotification(uint32 notification)
{

    // should probably add a check to see if the right timer was called but test board only has one active hardware timer atm
    softwareTimerCallback();

}
#endif


