/*
 * timers.h
 *
 *  Created on: Apr 26, 2021
 *      Author: Rafael Guevara
 */

//One RTI handles all software timers; each peripheral has at most one software timer with one
//callback function. Within the callback function, the peripheral decides which test case to run

//Halcogen Setup
// 1. Enable RTI driver
// 2. Enable appropriate VIM channel (ie look for compare block)
// 3. Set period of compare block

#ifndef TIMERS_TIMERS_H_
#define TIMERS_TIMERS_H_

#include "rti.h"
#include "common.h"

#define NUM_TIMERS 10 //each system gets one timer if needed. reduce number of timers later...

/* Variables */

// Timer List Enum
typedef enum{

    TEST_COMPLETE_TIMER = 0,


    SWEEP_TIMER, //general vcu timer

    //apps timers
    SHORT_TIMER,
    OPEN_TIMER,
    BSE_ACTIVATED_TIMER,

    //more timers here...

} Timer;

typedef void (*Callbackfunc)(Timer, int); //callback function signature; MUST return void and take Timer and int as parameters

// TimerHandle Struct
typedef struct{

    char* name;

    Callbackfunc callback; //function that executes when timer expires

    int ID; //timer ID; can be used to count cycles

    int period; //timer period in ms

    bool stop; //boolean to start/stop timer

    Timer timer;

} TimerHandle;


static unsigned long long int ticks; //number of times RTI has expired in ms

static TimerHandle xTimers[NUM_TIMERS]; //array of all timers

/* Function Declarations */

void timerInit();

/* Getters */

int getTimerID(Peripheral);

int getTimerPeriod(Peripheral);

uint8_t isBlocked(Peripheral);

/* Setters */

void xTimerSet(char*, Peripheral, Callbackfunc, int);

void startGlobalTimer();

void stopGlobalTimer();

void stopAllTimers();

void startTimer(Peripheral, Timer, int);

void stopTimer(Peripheral);

void setTimerID(Peripheral, int);

void setTimerPeriod(Peripheral, int);

#endif /* TIMERS_TIMERS_H_ */
