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
//#include "FreeRTOS.h"
//#include "FreeRTOSConfig.h"
//#include "os_task.h"
//#include "os_timer.h"

Result_t bms_slaves_process(uint8_t state);
void bms_slaves_init();


#endif /* PHANTOM_DRIVERS_INCLUDE_BMS_SLAVES_H_ */
