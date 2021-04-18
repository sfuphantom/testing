/*
 * bse.c
 *
 *  Created on: Nov 12, 2020 
 *      Author: Courtenay Huffman
 */

#include "bse.h"
#include "hwConfig.h"
#include "MCP48FV_DAC_SPI.h"

#define BSE_MAX 43
#define BSE_MIN 15
#define BSE_OPEN 0
#define BSE_SHORT 500
#define VOUT1 1
#define DAC_SIZE_BSE 0xFF

enum
{
    NORMAL_BSE_OFF,
    NORMAL_BSE_ON,
    BSE_OPEN_CIRCUIT, //0V reading
    BSE_SHORT_CIRCUIT, //5V reading
    APPS_BSE_ACTIVATED, // APPS sensor indicates >25% activation while BSE applied
    APPS_BSE_DEACTIVATED, // after APPS & BSE applied, power returns after APPS registers <5% activation
    BSE_SWEEP
};

// Static function prototypes
static void normal_bse_off();
static void normal_bse_on();
static void bse_open_circuit();
static void bse_short_circuit();
static void apps_bse_activated();
static void apps_bse_deactivated();
static void bse_sweep();
uint16_t get_apps_voltage(uint16_t dac_val);

void bse_process(uint8_t state){
    switch(state)
    {
        case NORMAL_BSE_ON:
            normal_bse_on();
            break;
        case BSE_OPEN_CIRCUIT:
            bse_open_circuit();
            break;
        case BSE_SHORT_CIRCUIT:
            bse_short_circuit();
            break;
        case BSE_SWEEP:
            bse_sweep();
            break;
        case APPS_BSE_ACTIVATED:
            apps_bse_activated();
            break;
        case APPS_BSE_DEACTIVATED:
            apps_bse_deactivated();
            break;
        default:
            normal_bse_off();
            break;
    }
}

static void normal_bse_off(){
    //sets BSE value at minimum of its range as though the pedal is not being pressed
    MCP48FV_Set_Value_Single(BSE_MIN, DAC_SIZE_BSE, VOUT1, 1);
    return;
}

static void normal_bse_on(){
    // sets BSE value at midpoint of operating range
    uint16_t bse_volt = ((BSE_MAX-BSE_MIN)/2)+BSE_MIN;
    MCP48FV_Set_Value_Single(bse_volt, DAC_SIZE_BSE, VOUT1, 1);
    return;
}

static void bse_open_circuit(){
    // bse sensor reads an open circuit (0V)
    MCP48FV_Set_Value_Single(BSE_OPEN, DAC_SIZE_BSE, VOUT1, 1);
    return;
}

static void bse_short_circuit(){
    // bse sensor reads a short circuit (5V)
    MCP48FV_Set_Value_Single(BSE_SHORT, DAC_SIZE_BSE, VOUT1, 1);
    return;
}

/* TESTS THE NEED TIMERS BEGIN HERE */

static void bse_sweep(){
    // loops through values within a normal range
    // make sure it stops when it reaches the max voltage
    int prev_voltage = get_apps_voltage(readRegister(VOUT1, 1));
    MCP48FV_Set_Value_Single(prev_voltage+50, DAC_SIZE_BSE, VOUT1, 1);

    return;
}

static void apps_bse_activated(){
    normal_bse_on();
    return;
}

static void apps_bse_deactivated(){
    normal_bse_on();
    return;
}

/* TESTS THAT NEED TIMERS END HERE */

uint16_t get_apps_voltage(uint16_t dac_val){
    return ((dac_val*500000)/(0xFF*1000));
}
