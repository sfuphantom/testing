/*
 * common.h
 *
 *  Created on: Nov 9, 2020
 *      Author: Mahmoud Ahmed
 */

#ifndef PHANTOM_DRIVERS_COMMON_INCLUDE_COMMON_H_
#define PHANTOM_DRIVERS_COMMON_INCLUDE_COMMON_H_

#include "stdint.h"

typedef enum
{
  SUCCESS,
  FAIL
} Result_t;

#define TIMER_DEBUG

#define SWEEP_STEP 50

#define SWEEP_PERIOD 500

typedef enum Peripheral
{
    //systems with timers
    TEST_COMPLETE = 0,
    APPS,
    BSE,

    TSAL,
    IMD,
    LV,
    VCU_COMMUNICATIONS,
    BMS_SLAVES,
    THERMISTOR_EXPANSION,
    BMS_COMMUNICATIONS
} Peripheral;




void delayms(uint16_t ms);

#endif /* PHANTOM_DRIVERS_COMMON_INCLUDE_COMMON_H_ */
