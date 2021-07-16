/*
 * bms_slaves.h
 *
 *  Created on: Oct 25, 2020
 *      Author: Mahmoud Ahmed
 */

#ifndef PHANTOM_DRIVERS_INCLUDE_BMS_SLAVES_H_
#define PHANTOM_DRIVERS_INCLUDE_BMS_SLAVES_H_

#include "stdint.h"
#include "common.h"

Result_t bms_slaves_process(uint8_t state);
void bms_slaves_init();

enum
{
    NORMAL_BMS_OPERATION = 0, //only not fault condition should be zero on shutdown pin
    OVER_VOLTAGE_FAULT,
    UNDER_VOLTAGE_FAULT,
    OVER_TEMPERATURE_FAULT,
    UNDER_TEMPERATURE_FAULT,
    WEIRD_SENSOR_READINGS_VOLTAGE,
    WEIRD_SENSOR_READINGS_TEMPERATURE,
    COMMUNICATION_LOSS,
};


#endif /* PHANTOM_DRIVERS_INCLUDE_BMS_SLAVES_H_ */
