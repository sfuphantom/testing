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
#include "Phantom_sci.h"


#define NUM_TIMERS NUM_PERIPHERALS //each system gets one timer if needed. reduce number of timers later...


/* Variables */

typedef void (*Callbackfunc)(int); //callback function signature; MUST return void and take Timer and int as parameters

// TimerHandle_t Struct
typedef struct{

    char* name; //used to identify peripheral when debugging

    Callbackfunc callback; //function that executes when peripheral timer expires

    int ID; //peripheral timer ID; can be used to count cycles

    int period; //peripheral timer period in ms

    bool stop; //boolean to start/stop peripheral timer

} TimerHandle_t;


static uint32_t ticks; //number of times RTI has expired in ms (will not overflow for ~ 49 days)

static TimerHandle_t xTimers[NUM_TIMERS]; //array of all peripheral software timers

/* Function Declarations */

void timerInit();

/* Getters */

int getTimerID(Peripheral);

int getTimerPeriod(Peripheral);

uint8_t isBlocked(Peripheral);

bool timers_complete();

/* Setters */

void xTimerSet(char*, Peripheral, Callbackfunc, int);

void startGlobalTimer();

void stopGlobalTimer();

void stopAllTimers();

void startTimer(Peripheral, int);

void stopTimer(Peripheral);

void setTimerID(Peripheral, int);

void setTimerPeriod(Peripheral, int);

unsigned int update_value(Peripheral, int, int, int, int, bool);

void setTimerCallback(Peripheral, Callbackfunc);

#endif /* TIMERS_TIMERS_H_ */
