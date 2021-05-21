/*
 * common.h
 *
 *  Created on: Nov 9, 2020
 *      Author: Mahmoud Ahmed
 */

#ifndef PHANTOM_DRIVERS_COMMON_INCLUDE_COMMON_H_
#define PHANTOM_DRIVERS_COMMON_INCLUDE_COMMON_H_

#include "stdint.h"

//Common defines
#define TIMER_DEBUG
#define SWEEP_STEP 25
#define SWEEP_PERIOD 500

typedef enum
{
  SUCCESS,
  FAIL
} Result_t;

typedef enum Peripheral
{
    //systems with timers
<<<<<<< HEAD
    TEST_COMPLETE = -1,
    APPS,
=======
    APPS = 0,
>>>>>>> master
    BSE,
    GPIO,

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
