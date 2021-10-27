/*
 * vcu_peripherals.c
 *
 *  Created on: Oct 18, 2021
 *      Author: Rafael
 */

#include "vcu_peripherals.h"

static uint16_t create_apps2_volt(uint16_t, float);
static uint16_t get_apps_voltage(uint16_t);

void sendAPPSVoltages(uint16_t apps1, uint16_t apps2){

    #ifndef DEV_ENV
    MCP48FV_Set_Value_Double(apps1_volt, apps2_volt, DAC_SIZE_APPS, 0);
    #endif

    #ifdef DEV_ENV
    printf(apps1, apps2, diff)
    #endif

}

void sendAPPSdiff(uint16_t apps1, float diff){

    sendAPPSVoltages(apps1, create_apps2_volt(apps1, diff) );

}
/* APPS HELPER FUNCTIONS */

// difference is the ratio difference between APPS values, 1 meaning 0% difference
static uint16_t create_apps2_volt(uint16_t apps1_volt, float difference){
    uint16_t apps2_volt = (difference*( (double)(apps1_volt-APPS1_MIN)/(APPS1_MAX-APPS1_MIN))*(APPS2_MAX-APPS2_MIN))+APPS2_MIN;
    return apps2_volt;
}

static uint16_t get_apps_voltage(uint16_t dac_val){
    return ((dac_val*500000)/(0xFF*1000));
}
