/*
 * bms_slaves.c
 *
 *  Created on: Oct 25, 2020
 *      Author: Mahmoud Ahmed
 */
#include "bms_slaves.h"

enum
{
    NORMAL_BMS_OPERATION,
    MINOR_VOLTAGE_FAULT,
    MINOR_TEMPERATURE_FAULT
};

// Static function definitions
static void normal_bms_operation();

void bms_slaves_process(uint8_t state)
{
    switch(state)
    {
        case NORMAL_BMS_OPERATION:
            normal_bms_operation();
            break;
    }
}

static void normal_bms_operation()
{

}
