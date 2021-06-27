/*
 * communications.c
 *
 *  Created on: Oct 25, 2020
 *      Author: Mahmoud Ahmed
 */

#include "communications.h"
#include "Phantom_sci.h"
#include "common.h"

enum
{
    NORMAL_COMMS_OPERATION,
    COMMS_LOST
};

// Static function prototypes
static void normal_comms_operation();

Result_t communications_process(uint8_t state)
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

