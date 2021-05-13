/*
 * apps.h
 *
 *  Created on: Nov 12, 2020 
 *      Author: Courtenay Huffman
 */

#ifndef PHANTOM_DRIVERS_INCLUDE_APPS_H_
#define PHANTOM_DRIVERS_INCLUDE_APPS_H_

#include "stdint.h"

#include "timer.h"

#include "common.h"

#include "Phantom_sci.h"

void apps_process(uint8_t state);

//Timer Callback Functions
void apps_short_timer(Timer, int);

void apps_open_timer(Timer, int);

void apps_bse_activated_timer(Timer, int);

void apps_sweep_timer(Timer, int);

enum
{
    NORMAL_APPS_ON,
    NORMAL_APPS_OFF,
    APPS_IMPLAUSIBILITY,
    APPS_SHORT_CIRCUIT,
    APPS_OPEN_CIRCUIT,
    APPS_BSE_ACTIVATED, // APPS sensor indicates >25% activation while BSE applied
    APPS_SWEEP
};

#endif /* PHANTOM_DRIVERS_INCLUDE_APPS_H_ */
