/*
 * gpio_tests.h
 *
 *  Created on: Apr 1, 2021
 *      Author: Rafael Guevara
 */


#ifndef PHANTOM_DRIVERS_INCLUDE_GPIOTESTS_H_
#define PHANTOM_DRIVERS_INCLUDE_GPIOTESTS_H_

#include "stdint.h"
#include "hwConfig.h"
#include "timer.h"
#include "common.h"

void gpio_init();

void gpio_process(uint8_t state);

enum
{
    RTD_NORMAL_PROCEDURE = 0, //Get VCU to state RUNNING
    RTD_LATCH,  //Simulate RTD procedure -> turn off RTD
    RTD_INORDER, //Reverse order of RTD procedure
};

const uint8_t GPIO_RESULTS_LUT[] = { /* RUNNING */ , /* TS_OFF */, /* !RUNNING */}


#endif /* PHANTOM_DRIVERS_INCLUDE_GPIOTESTS_H_ */
