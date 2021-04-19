/*
 * apps.c
 *
 *  Created on: Nov 12, 2020 
 *      Author: Courtenay Huffman
 */

#include "apps.h"
#include "hwConfig.h"
#include "MCP48FV_DAC_SPI.h"

#define APPS1_MAX 440
#define APPS1_MIN 150
#define APPS2_MAX 150
#define APPS2_MIN 50
#define DAC_SIZE_APPS 0xFF

enum
{
    NORMAL_APPS_ON,
    NORMAL_APPS_OFF,
    APPS_IMPLAUSIBILITY,
    APPS_SHORT_CIRCUIT,
    APPS_OPEN_CIRCUIT,
    APPS_BSE_ACTIVATED, // APPS sensor indicates >25% activation while BSE applied
    APPS_SWEEP
};

// Static function prototypes
static void normal_apps_on();
static void normal_apps_off();
static void apps_implausibility();
static void apps_open_circuit();
static void apps_short_circuit();
static void apps_bse_activated();
static void apps_sweep();
uint16_t create_apps2_volt(uint16_t apps1_volt, float difference);
uint16_t get_apps_voltage(uint16_t dac_val);

void apps_process(uint8_t state)
{
    switch(state)
    {
        case NORMAL_APPS_ON:
            normal_apps_on();
            break;
        case APPS_IMPLAUSIBILITY:
            apps_implausibility();
            break;
        case APPS_SHORT_CIRCUIT:
            apps_short_circuit();
            break;
        case APPS_OPEN_CIRCUIT:
            apps_open_circuit();
            break;
        case APPS_BSE_ACTIVATED:
            apps_bse_activated();
            break;
        case APPS_SWEEP:
            apps_sweep();
            break;
        default: 
            normal_apps_off();
            break;
    }
}

static void normal_apps_off(){
    MCP48FV_Set_Value_Double(APPS1_MIN, APPS2_MIN, DAC_SIZE_APPS, 0);
    return;
}

static void normal_apps_on()
{
    // sets APPS values at midpoint of valid APPS range
    uint16_t apps1_volt = ((APPS1_MAX-APPS1_MIN)/2)+APPS1_MIN;
    uint16_t apps2_volt = create_apps2_volt(apps1_volt, 1.0);

    MCP48FV_Set_Value_Double(apps1_volt, apps2_volt, DAC_SIZE_APPS, 0);
    return;
}

static void apps_implausibility()
{
    uint16_t apps1_volt = ((APPS1_MAX-APPS1_MIN)/2)+APPS1_MIN;
    uint16_t apps2_volt = create_apps2_volt(apps1_volt, 1.15);

    MCP48FV_Set_Value_Double(apps1_volt, apps2_volt, DAC_SIZE_APPS, 0);

    return;
}

/* TESTS NEEDING TIMERS BEGIN HERE */

static void apps_short_circuit() 
{
    uint16_t prev = get_apps_voltage(readRegister(0, 0));
    if (prev == APPS1_MIN) MCP48FV_Set_Value_Double(APPS1_MAX+20, APPS2_MAX, DAC_SIZE_APPS, 0);
    if (prev == APPS1_MAX+20) MCP48FV_Set_Value_Double(APPS1_MAX, APPS2_MAX+20, DAC_SIZE_APPS, 0);
    if (prev == APPS2_MAX+20) MCP48FV_Set_Value_Double(APPS1_MAX+20, APPS2_MAX+20, DAC_SIZE_APPS, 0);

    return;
}

static void apps_open_circuit()
{
    uint16_t prev = get_apps_voltage(readRegister(0, 0));
    if (prev == APPS1_MIN) MCP48FV_Set_Value_Double(APPS1_MIN-20, APPS2_MIN, DAC_SIZE_APPS, 0);
    if (prev == APPS1_MIN-20) MCP48FV_Set_Value_Double(APPS1_MIN, APPS2_MIN-20, DAC_SIZE_APPS, 0);
    if (prev == APPS2_MIN-20) MCP48FV_Set_Value_Double(APPS1_MIN-20, APPS2_MIN-20, DAC_SIZE_APPS, 0);

    return;
}

static void apps_bse_activated()
{
    // sets APPS values at midpoint of valid APPS range
    // BSE activated within bse.c
    uint16_t apps1_volt, apps2_volt;
    if (get_apps_voltage(readRegister(0, 0)) == APPS1_MIN){ 
        apps1_volt = ((APPS1_MAX-APPS1_MIN)/2)+APPS1_MIN;
        apps2_volt = create_apps2_volt(apps1_volt, 1.0);
        MCP48FV_Set_Value_Double(apps1_volt, apps2_volt, DAC_SIZE_APPS, 0);
    } else 
        // to be executed after apps_bse_activated()
        // APPS sensors indicate <5% activation, regardless if BSE is still activated
        MCP48FV_Set_Value_Double(APPS1_MIN+10, create_apps2_volt(APPS1_MIN+10, 1.00), DAC_SIZE_APPS, 0);

    return;
}

static void apps_sweep()
{
    // make sure it doesnt go over voltage - stop it somehow
    int prev_voltage = get_apps_voltage(readRegister(0, 0)); 
    MCP48FV_Set_Value_Double(prev_voltage+50, create_apps2_volt(prev_voltage+50, 1.00), DAC_SIZE_APPS, 0);
    return;
}

/* TESTS NEEDING TIMERS END HERE */

// difference is the ratio difference between APPS values, 1 meaning 0% difference
uint16_t create_apps2_volt(uint16_t apps1_volt, float difference){
    uint16_t apps2_volt = (difference*((apps1_volt-APPS1_MIN)/(APPS1_MAX-APPS1_MIN))*(APPS2_MAX-APPS2_MIN))+APPS2_MIN;
    return apps2_volt;
}

uint16_t get_apps_voltage(uint16_t dac_val){
    return ((dac_val*500000)/(0xFF*1000));
}