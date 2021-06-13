/*
 * hv_voltage_sensor.h
 *
 *  Created on: Nov 10, 2020 
 *      Author: Sumreen Rattan
 *      Modified by: Ryan Heo
 */

#ifndef PHANTOM_DRIVERS_INCLUDE_HV_VOLTAGE_SENSOR_H_
#define PHANTOM_DRIVERS_INCLUDE_HV_VOLTAGE_SENSOR_H_

#include "sys_common.h"
#include "stdint.h"
#include "mibspi.h"
#include "gio.h"
#include "sys_vim.h"
#include "sys_core.h"
#include "Phantom_sci.h"
#include "hwConfig.h"
#include "timer.h"

//#define HV_VS_DEBUG

typedef enum
{
    HV_VS_LOWER_BOUND,    //Expected VCU output/state: 125V/Running,Tractive on
    HV_VS_UPPER_BOUND,    //Expected VCU output/state: 168V/Running,Tractive on
    HV_VS_OUT_OF_LOWERBOUND, //Expected VCU output/state: 120V/Running -> Minor fault or Tractive on -> Minor fault
    HV_VS_OUT_OF_UPPERBOUND, //Expected VCU output/state: 168.3V/ Minor fault or Tractive on -> Minor fault
    HV_VS_AT_ZERO,           //Expected VCU output/state: 0v/Tractive off
    HV_VS_SWEEP              //Expected VCU output/state: 125V-168V with 1V increment/Running -> Tractive off -> Tractive on ->Running
} testcases_name;

//function prototypes
void hv_vs_timer(TestTimer_t test_timer, int ID);
void hv_vs_process(uint8_t state);
void adcSlaveDataSetup();


#endif /* PHANTOM_DRIVERS_INCLUDE_HV_VOLTAGE_SENSOR_H_ */
