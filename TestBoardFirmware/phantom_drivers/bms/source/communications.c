/*
 * communications.c
 *
 *  Created on: Oct 25, 2020
 *      Author: Mahmoud Ahmed
 */

#include "communications.h"

enum
{
    NORMAL_COMMS_OPERATION,
    COMMS_LOST
};

// Static function prototypes
static void normal_comms_operation();

void communications_process(uint8_t state)
{
    switch(state)
    {
        case NORMAL_COMMS_OPERATION:
            normal_comms_operation();
            break;
    }
}

static void normal_comms_operation()
{

}

