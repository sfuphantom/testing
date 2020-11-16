/*
 * apps.c
 *
 *  Created on: Nov 12, 2020 
 *      Author: Courtenay Huffman
 */

#include "apps.h"

enum
{
    NORMAL_APPS_OPERATION,
    APPS_IMPLAUSIBILITY,
    APPS_SHORT_CIRCUIT,
    APPS_OPEN_CIRCUIT,
    APPS_BSE_ACTIVATED,
    //APPS_BSE_DEACTIVATED ????
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
        default: 
            normal_apps_operation();
            break;
    }
}

static void normal_apps_operation()
{

}

static void apps_implausibility()
{

}

static void apps_short_circuit()
{

}

static void apps_open_circuit()
{

}

static void apps_bse_activated()
{

}