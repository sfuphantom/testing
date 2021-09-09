/*
 * common.h
 *
 *  Created on: Nov 9, 2020
 *      Author: Mahmoud Ahmed
 */

#ifndef PHANTOM_DRIVERS_COMMON_INCLUDE_COMMON_H_
#define PHANTOM_DRIVERS_COMMON_INCLUDE_COMMON_H_

#include "stdint.h"


#define TIMER_DEBUG //print expirations of all active timers
#define BMS_DEBUG //print received signals from Device Under Test; print expected and actual results
#define VCU_DEBUG //print received signals from Device Under Test; print expected and actual results
//#define GUI_MODE //runs firmware with GUI. if not defined, firmware can run w/o the GUI


//Common defines
#define TIMER_DEBUG
//#define HV_VS_DEBUG
#define SWEEP_STEP 250
#define SWEEP_PERIOD 500



typedef enum
{
  SUCCESS,
  FAIL
} Result_t;

typedef enum Peripheral
{
    //systems with timers
    APPS = 0,
    BSE,
    GPIO,

    TSAL,
    IMD,
    LV,
    HV_VS,
    VCU_COMMUNICATIONS,
    BMS_SLAVES,
    THERMISTOR_EXPANSION,
    BMS_COMMUNICATIONS
} Peripheral;

void delayms(uint16_t ms);

#endif /* PHANTOM_DRIVERS_COMMON_INCLUDE_COMMON_H_ */
