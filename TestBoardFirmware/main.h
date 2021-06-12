/*
 * main.h
 *
 *  Created on: Oct 25, 2020
 *      Author: Mahmoud Ahmed
 */

#ifndef PHANTOM_DRIVERS_INCLUDE_MAIN_H_
#define PHANTOM_DRIVERS_INCLUDE_MAIN_H_

#include "bms_slaves.h"
#include "thermistor_expansion.h"
#include "communications.h"

#include "common.h"

typedef enum
{
    IDLE,
    BMS_MODE,
    VCU_MODE
} TestBoardModes_t;

//enum VCUPeripheralPosition
//{
//    APPS,
//    BSE,
//    TSAL,
//    IMD,
//    LV,
//    VCU_COMMUNICATIONS,
//};
//
//enum BMSPeripheralPosition
//{
//    BMS_SLAVES,
//    THERMISTOR_EXPANSION,
//    BMS_COMMUNICATIONS
//};



typedef struct
{
  TestBoardModes_t testMode; //BMS/VCU mode
  uint8_t peripheralStateArray[10]; //holds test to run
} TestBoardState_t;


#endif /* PHANTOM_DRIVERS_INCLUDE_MAIN_H_ */
