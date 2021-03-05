/*
 * communications.c
 *
 *  Created on: Oct 25, 2020
 *      Author: Mahmoud Ahmed
 */

#include "communications.h"
#include "Phantom_sci.h"
#include "common.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "os_task.h"
#include "os_timer.h"

enum
{
    NORMAL_COMMS_OPERATION,
    COMMS_LOST
};

// Static function prototypes
static void normal_comms_operation();

Result_t communications_process(uint8_t state, TimerHandle_t *timerptr)
{
    switch(state)
    {
        case NORMAL_COMMS_OPERATION:
            normal_comms_operation();
            break;
    }

    return SUCCESS;
}

static void normal_comms_operation()
{
    UARTprintf("Normal Comms Operation\n\r");
}

