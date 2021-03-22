/*
 * apps.c
 *
 *  Created on: Nov 12, 2020 
 *      Author: Courtenay Huffman
 */

#include "apps.h"
#include "hwConfig.h"
#include "MCP48FV_DAC_SPI.c"
#include "stdlib.h"
#include "time.h"

#define APPS1_MAX 440
#define APPS1_MIN 150
#define APPS2_MAX 150
#define APPS2_MIN 50

enum
{
    NORMAL_APPS_OPERATION,
    APPS_IMPLAUSIBILITY,
    APPS_SHORT_CIRCUIT,
    APPS_OPEN_CIRCUIT,
    APPS_BSE_ACTIVATED, // APPS sensor indicates >25% activation while BSE applied
    APPS_BSE_DEACTIVATED, // after APPS & BSE applied, power returns after APPS registers <5% activation
    APPS_SWEEP
};

// Static function prototypes
static void normal_apps_operation();
static void apps_implausibility();
static void apps_open_circuit();
static void apps_short_circuit();
static void apps_bse_activated();
static void apps_bse_deactivated();
static void apps_sweep();

void apps_process(uint8_t state)
{
    switch(state)
    {
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
        case APPS_BSE_DEACTIVATED:
            apps_bse_deactivated();
            break;
        case APPS_SWEEP:
            apps_sweep();
            break;
        default: 
            normal_apps_operation();
            break;
    }
}

static void normal_apps_operation()
{
    // sets APPS values at midpoint of valid APPS range
    uint16_t apps1_volt = ((APPS1_MAX-APPS1_MIN)/2)+APPS1_MIN;
    uint16_t apps2_volt = ((APPS2_MAX-APPS2_MIN)/2)+APPS2_MIN; //how does the vcu calculate 10% tho

    MCP48FV_Set_Value(apps1_volt, apps2_volt, 8);
    return;
}

static void apps_implausibility()
{
    // both APPS sensors operate between X(MIN) and X(MAX) range
    // APPS sensors indicate >10% difference in values 

    return;
}

static void apps_short_circuit() 
{
    uint32_t srand(time());
    apps_select=rand()%3;
    switch(apps_select){
        case 0:
            MCP48FV_Set_Value(APPS1_MAX+5, APPS2_MAX-5, 8)
            break;
        case 1:
            MCP48FV_Set_Value(APPS1_MAX-5, APPS2_MAX+5, 8)
            break;
        case 2:
            MCP48FV_Set_Value(APPS1_MAX+5, APPS2_MAX+5, 8)
            break;
    }

    return;
}

static void apps_open_circuit()
{
    uint_32 srand(time());
    apps_select=rand()%3;
    switch(apps_select){
        case 0:
            MCP48FV_Set_Value(APPS1_MIN-5, APPS2_MIN+5, 8)
            break;
        case 1:
            MCP48FV_Set_Value(APPS1_MIN+5, APPS2_MIN-5, 8)
            break;
        case 2:
            MCP48FV_Set_Value(APPS1_MIN-5, APPS2_MIN-5, 8)
            break;
    }

    return;
}

static void apps_bse_activated() // how should this one be handled? involves BSE values
{
    // both APPS sensors indicate >25% activation
    // both APPS sensors operate between X(MIN) and X(MAX) range
    // both APPS sensor values within 10% of each other
    // BSE sensor activated

    return;
}

static void apps_bse_deactivated()
{
    // to be executed after apps_bse_activated()
    // both APPS sensors indicate <5% activation
    // both APPS sensors operate between X(MIN) and X(MAX) range
    // both APPS sensor values within 10% of each other

    return;
}

static void apps_sweep()
{
    for(uint16_t i=APPS1_MIN; i<=APPS1_MAX; i+=10){
        uint16_t apps2_volt = 0; //set to 10% of apps1
        MCP48FV_Set_Value(i, apps2_volt, 8);
        //delay of some sort
    }

    return;
}