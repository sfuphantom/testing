/*
 * common.h
 *
 *  Created on: Nov 9, 2020
 *      Author: Mahmoud Ahmed
 */

#ifndef PHANTOM_DRIVERS_COMMON_INCLUDE_COMMON_H_
#define PHANTOM_DRIVERS_COMMON_INCLUDE_COMMON_H_

#include "stdint.h"



//Debug Modes
//#define GUI_MODE  //runs firmware with GUI. if not defined, firmware will run w/o the GUI
#define TIMER_DEBUG //print expirations of all active timers
//#define BMS_DEBUG   //print received signals from Device Under Test; print expected and actual results
//#define VCU_DEBUG   //print received signals from Device Under Test; print expected and actual results
//#define HV_VS_DEBUG //print calculated values being sent via SPI to the high voltage peripheral
#define SHUTDOWN_INTERRUPT_DEBUG

//#define SHUTDOWN_UNIT_TESTS


//Choose test cases to run, independent of the GUI
#ifndef GUI_MODE

    #define APPS_TEST      NORMAL_APPS_OFF
    #define BSE_TEST       BSE_OPEN_CIRCUIT

    #define HV_VS_TEST     0
    #define TSAL_TEST      0
    #define IMD_TEST       0
    #define LV_TEST        0
    #define VCU_COMMS_TEST 0
    #define SLAVES_TEST    0

#endif


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

#define NUM_PERIPHERALS 12

typedef enum Peripheral
{
    //systems with timers
    APPS = 0,
    BSE,
    GPIO,

    VALIDATION,


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
