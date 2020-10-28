/*
 * thermistor_expansion.c
 *
 *  Created on: Oct 25, 2020
 *      Author: Mahmoud Ahmed
 */

#include "thermistor_expansion.h"

enum
{
    NORMAL_THERMISTOR_OPERATION,
    TEMPERATURE_FAULT
};

// Static function prototypes
static void normal_thermistor_operation();

void thermistor_process(uint8_t state)
{
    switch(state)
    {
        case NORMAL_THERMISTOR_OPERATION:
            normal_thermistor_operation();
            break;
    }
}

static void normal_thermistor_operation()
{

}


