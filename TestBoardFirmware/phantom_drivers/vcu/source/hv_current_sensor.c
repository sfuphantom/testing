/*
 * hv_current_sensor.c
 *
 *  Created on: Nov 10, 2020 
 *      Author: Sumreen Rattan
 */

#include "hv_current_sensor.h"

enum
{
    NORMAL_HV_CS_OPERATION
};

// Static function prototypes
static void normal_hv_cs_operation();

void hv_cs_process(uint8_t state)
{
    switch(state)
    {
        case NORMAL_HV_CS_OPERATION:
            normal_hv_cs_operation();
            break;
    }
}

static void normal_hv_cs_operation()
{

}


