///*
// * bms_slaves.c
// *
// *  Created on: Oct 25, 2020
// *      Author: Mahmoud Ahmed
// */
//#include "bms_slaves.h"
//#include "stdlib.h"
//#include "Phantom_sci.h"
//#include "common.h"
//#include "FreeRTOS.h"
//#include "os_timer.h"
//
//// BMS Slave specific definitions, not accessed outside bms_slaves.c
//#define VOLTAGE_STEP  0.04
//#define DEFAULT_VOLTAGE 84
//#define DEFAULT_TEMPERATURE 25
//#define NUMBER_OF_TEMPERATURE_READINGS 16
//
//
//enum
//{
//    NORMAL_BMS_OPERATION,
//    MINOR_VOLTAGE_FAULT,
//    MINOR_TEMPERATURE_FAULT
//};
//
//typedef struct {
//    float bmsSlaveVoltage;
//    float bmsSlaveTemperatures[NUMBER_OF_TEMPERATURE_READINGS];
//} BMSSlave_t;
//
//// Static Global Variables
//static BMSSlave_t *bmsStruct;
//
//// Static function definitions
//static void normal_bms_operation();
//static void minor_overvoltage_test();
//static void minor_undervoltage_test();
//
//Result_t bms_slaves_process(uint8_t state, TimerHandle_t *timerptr)
//{
//
//    bms_slaves_init();
//
//
//    switch(state)
//    {
//        case NORMAL_BMS_OPERATION:
//            normal_bms_operation();
//            break;
//    }
//
//    return SUCCESS;
//}
//
//void bms_slaves_init()
//{
//    bmsStruct->bmsSlaveVoltage =  DEFAULT_VOLTAGE;
//    uint8_t i;
//    for(i = 0; i < NUMBER_OF_TEMPERATURE_READINGS; i++) {
//        bmsStruct->bmsSlaveTemperatures[i] = DEFAULT_TEMPERATURE;
//    }
//}
//
//
//// Send a constant 3.8V
//static void normal_bms_operation()
//{
//    //set_bms_voltage
//    UARTprintf("Normal BMS Operation\n\r");
//}
//
//static void minor_overvoltage_test()
//{
//
//}
//
//static void minor_undervoltage_test()
//{
//
//}
//
