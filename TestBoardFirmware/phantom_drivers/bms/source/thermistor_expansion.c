/*
 * thermistor_expansion.c
 *
 *  Created on: Oct 25, 2020
 *      Author: Mahmoud Ahmed
 */

#include "thermistor_expansion.h"
#include "Phantom_sci.h"
#include "common.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "os_task.h"
#include "os_timer.h"

enum
{
    NORMAL_THERMISTOR_OPERATION,
    TEMPERATURE_FAULT
};

// Static function prototypes
static void normal_thermistor_operation();

Result_t thermistor_process(uint8_t state, TimerHandle_t *timerptr)
{
    switch(state)
    {
        case NORMAL_THERMISTOR_OPERATION:
            normal_thermistor_operation();
            break;
    }

    return SUCCESS;
}

static void normal_thermistor_operation()
{
    UARTprintf("Normal Thermistor Operation\n\r");
}


