/*
 * inverter.h
 *
 *  Created on: Jun 3, 2021
 *      Author: Rafael Guevara
 */

#ifndef PHANTOM_DRIVERS_VCU_INCLUDE_INVERTER_H_
#define PHANTOM_DRIVERS_VCU_INCLUDE_INVERTER_H_


#include "hwConfig.h"
#include "common.h"
#include "Phantom_sci.h"
#include "adc.h" //configure in halcogen


unsigned int getInverterReadings();
float getInverterSignal();
unsigned int getInverterOutput();







#endif /* PHANTOM_DRIVERS_VCU_INCLUDE_INVERTER_H_ */
