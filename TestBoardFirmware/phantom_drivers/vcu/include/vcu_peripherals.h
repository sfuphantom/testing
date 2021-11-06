/*
 * vcu_peripherals.h
 *
 *  Created on: Oct 18, 2021
 *      Author: Rafael
 */

#ifndef PHANTOM_DRIVERS_VCU_INCLUDE_VCU_PERIPHERALS_H_
#define PHANTOM_DRIVERS_VCU_INCLUDE_VCU_PERIPHERALS_H_


#include "hwConfig.h"
#include "MCP48FV_DAC_SPI.h"

#define APPS1_MAX 440
#define APPS1_MIN 150
#define APPS2_MAX 150
#define APPS2_MIN 50

#define DAC_SIZE_APPS 0xFF

void sendAPPSVoltages(uint16_t, uint16_t);

void sendAPPSdiff(uint16_t, float);




#endif /* PHANTOM_DRIVERS_VCU_INCLUDE_VCU_PERIPHERALS_H_ */
