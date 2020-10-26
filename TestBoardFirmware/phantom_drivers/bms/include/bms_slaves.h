/*
 * bms_slaves.h
 *
 *  Created on: Oct 25, 2020
 *      Author: Mahmoud Ahmed
 */

#ifndef PHANTOM_DRIVERS_INCLUDE_BMS_SLAVES_H_
#define PHANTOM_DRIVERS_INCLUDE_BMS_SLAVES_H_

typedef enum
{
    NORMAL_BMS_OPERATION,
    MINOR_VOLTAGE_FAULT,
    MINOR_TEMPERATURE_FAULT
} BMSTestState_t;

void bms_slaves_process(BMSTestState_t state);



#endif /* PHANTOM_DRIVERS_INCLUDE_BMS_SLAVES_H_ */
