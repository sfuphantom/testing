/*
 * timers.h
 *
 *  Created on: Apr 26, 2021
 *      Author: Rafael Guevara
 */

#ifndef TIMERS_TIMERS_H_
#define TIMERS_TIMERS_H_

#include "rti.h"

#define NUM_TIMERS 2 //define more timers here...


/* Variables */

// Timer List Enum
// Indexes of all timers in xTimers array
typedef enum{

    LED1,
    LED2

    //more timers here...

} Timer;

typedef void (*Callbackfunc)(Timer, int); //callback function signature; MUST return void and take Timer and int as parameters

// TimerHandle Struct
typedef struct{

    Callbackfunc callback; //function that executes when timer expires

    int ID; //timer ID; can be used to count cycles

    int period; //timer period in ms

    bool stop; //boolean to start/stop timer

} TimerHandle;

static unsigned long long int ticks; //number of times RTI has expired in ms

static TimerHandle xTimers[NUM_TIMERS]; //array of all timers

/* Function Declarations */

void timerInit();

/* Getters */

int getTimerID(Timer);

int getTimerPeriod(Timer);

uint8_t isBlocked(Timer);

/* Setters */

void xTimerSet(Timer, Callbackfunc, int, int);

void startTimer(Timer);

void stopTimer(Timer);

void setTimerID(Timer, int);

void setTimerPeriod(Timer, int);





































//// get member of a specific timer
//
///* Fn: getTimerID
//* Purpose: Gets ID of a timer based on the *timer* index given
//* Parameters: timer
//* */
//int getTimerID(Timer);
//
//
//
//
//
///* Fn: xTimerSet
//* Purpose: Sets all members of a timer based on the *timer* index given
//* Parameters: timer, callback, period, ID
//* */
//void xTimerSet(Timer, Callbackfunc, int, int);
//
//
//
///* Fn: setTimerID
//* Purpose: Sets ID of a timer based on the *timer* index given
//* Parameters: timer, ID
//* */
//
//void setTimerID(Timer, int);
//
//
//
///* Fn: startTimer
//* Purpose: Sets stop member of a given timer to false
//* Parameters: timer
//* */
//void startTimer(Timer);
//
//
//
///* Fn: stopTimer
//* Purpose: Sets stop member of a given timer to true
//* Parameters: timer
//* */
//void stopTimer(Timer);


#endif /* TIMERS_TIMERS_H_ */
