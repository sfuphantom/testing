/*
 * thermistor_expansion.h
 *
 *  Created on: Oct 25, 2020
 *      Author: Mahmoud Ahmed
 */

#ifndef PHANTOM_DRIVERS_INCLUDE_THERMISTOR_EXPANSION_H_
#define PHANTOM_DRIVERS_INCLUDE_THERMISTOR_EXPANSION_H_

typedef enum
{
    NORMAL_THERMISTOR_OPERATION,
    TEMPERATURE_FAULT
} ThermistorTestState_t;

void thermistor_process(ThermistorTestState_t state);



#endif /* PHANTOM_DRIVERS_INCLUDE_THERMISTOR_EXPANSION_H_ */
