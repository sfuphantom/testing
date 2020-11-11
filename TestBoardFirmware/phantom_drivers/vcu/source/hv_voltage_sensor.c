/*
 * hv_voltage_sensor.c
 *
 *  Created on: Nov 10, 2020 
 *      Author: Sumreen Rattan
 */

#include "hv_voltage_sensor.h"

enum
{
    NORMAL_HV_VS_OPERATION
};

// Static function prototypes
static void normal_hv_vs_operation();

void hv_cs_process(uint8_t state)
{
    switch(state)
    {
        case NORMAL_HV_VS_OPERATION:
            normal_hv_vs_operation();
            break;
    }
}

static void normal_hv_vs_operation()
{

}
