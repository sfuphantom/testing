/*
 * apps.c
 *
 *  Created on: Nov 12, 2020 
 *      Author: Courtenay Huffman
 */

#include "apps.h"


//will use spi and possibly pins 35, 33, 32 and 11 to set vals
//apparently use halcogen to generate files?
//find examples how to use mibspi on tms570


//following values need to be set to proper value
#define DEFAULT_APPS_1 1 //VALUE WITH NORMAL APPS RANGE
#define DEFAULT_APPS_2 1 //VALUE WITH NORMAL APPS RANGE

enum
{
    NORMAL_APPS_OPERATION,
    APPS_IMPLAUSIBILITY,
    APPS_SHORT_CIRCUIT,
    APPS_OPEN_CIRCUIT,
    APPS_BSE_ACTIVATED, // APPS sensor indicates >25% activation while BSE applied
    APPS_BSE_DEACTIVATED, // after APPS & BSE applied, power returns after APPS registers <5% activation
    APPS_OUT_OF_RANGE, //values outside normal operating range, but not an open or short circuit, for more than 100ms
    APPS_SWEEP
};

// Static function prototypes
static void normal_apps_operation();

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
        case APPS_OUT_OF_RANGE:
            apps_out_of_range();
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
    // both APPS sensors operate between X(MIN) and X(MAX) range
    // both APPS sensor values within 10% of each other
}

static void apps_implausibility()
{
    // both APPS sensors operate between X(MIN) and X(MAX) range
    // APPS sensors indicate >10% difference in values 
}

static void apps_short_circuit()
{
    // one or both APPS sensors indicate short circuit (5V)
    // both APPS sensor values within 10% of each other
}

static void apps_open_circuit()
{
    // one or both APPS sensors indicate open circuit (0V)
    // both APPS sensor values within 10% of each other
}

static void apps_bse_activated() // how should this one be handled? involves BSE values
{
    // both APPS sensors indicate >25% activation
    // both APPS sensors operate between X(MIN) and X(MAX) range
    // both APPS sensor values within 10% of each other
    // BSE sensor activated
}

static void apps_bse_deactivated()
{
    // to be executed after apps_bse_activated()
    // both APPS sensors indicate <5% activation
    // both APPS sensors operate between X(MIN) and X(MAX) range
    // both APPS sensor values within 10% of each other
}
}

static void apps_out_of_range()
{
    // one or both APPS sensors indicate voltage outside normal operating range (X(MIN) - X(MAX))
    // both APPS sensor values within 10% of each other
}

static void apps_sweep()
{
    //sweep test, check range of values
}