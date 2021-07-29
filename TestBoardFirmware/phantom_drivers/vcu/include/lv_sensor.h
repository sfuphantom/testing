/*
 * lv_sensor.h
 *
 *  Created on: April 8, 2021
 *      Author: Vlad Bors
 */

#ifndef PHANTOM_DRIVERS_INCLUDE_LV_SENSOR_H_
#define PHANTOM_DRIVERS_INCLUDE_LV_SENSOR_H_

#include "stdint.h"

void lv_sensor_process(uint8_t state);

enum operation
{
    LV_POW_STD_OP, // standard operation, send 12v to power
    LV_POW_UV, // power undervoltage, send 9v to power
    LV_POW_OV, // power overvoltage, send 15v to power
    LV_POW_POWERDRAW, // power draw, send any signal to chip's shunt resistor
    LV_POW_OVERCURRENT, // overcurrent protection, short a sustained signal to shunt
};


#endif /* PHANTOM_DRIVERS_INCLUDE_LV_SENSOR_H_ */
