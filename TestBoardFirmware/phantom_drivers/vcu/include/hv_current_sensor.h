/*
 * hv_current_sensor.h
 *
 *  Created on: Nov 10, 2020 
 *      Author: Sumreen Rattan
 */

#ifndef PHANTOM_DRIVERS_INCLUDE_HV_CURRENT_SENSOR_H_
#define PHANTOM_DRIVERS_INCLUDE_HV_CURRENT_SENSOR_H_

#include "stdint.h"

#include "Phantom_sci.h"

#include "hwConfig.h"
#include "MCP48FV_DAC_SPI.h"

#include "timer.h"

#include "apps.h"

void hv_cs_process(uint8_t state);

//Timer Callback Functions
void hvct_timer(TestTimer_t, int);

enum{
    NORMAL_HVCT,
    SWEEP_HV_CT_RANGE, //goes through entire -300A to 300A range
    OFFLINE_HV_CT, //sends 0V
    PROPORTIONAL_APPS, //sends correct hvct and apps readings
    LOW_APPS, //sends apps lower than hvct
    HIGH_APPS //sends apps higher than hvct
};



#endif /* PHANTOM_DRIVERS_INCLUDE_HV_CURRENT_SENSOR_H_ */
