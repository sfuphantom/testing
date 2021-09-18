/*
 * validation.h
 *
 *  Created on: Jun 8, 2021
 *      Author: Rafael Guevara
 */

#ifndef PHANTOM_DRIVERS_COMMON_INCLUDE_VALIDATION_H_
#define PHANTOM_DRIVERS_COMMON_INCLUDE_VALIDATION_H_

#include "hwConfig.h"
#include "common.h"
#include "bms_slaves.h"
#include "Phantom_sci.h"

#include "inverter.h"

#include "apps.h"


uint8_t is_bms_slave_test_passed(uint8_t test_case);



bool validateThrottleControls(uint8_t, uint8_t);

uint8_t getShutdownSignal(); // getter for shutdown signal

void setShutdownOccurence(bool); // tells the validation module the type of shutdown signal to expect

bool getShutdownResult() // getter for shutdown_fail

void shutdown_timeout_callback(int);




#endif /* PHANTOM_DRIVERS_COMMON_INCLUDE_VALIDATION_H_ */
