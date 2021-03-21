/*
 * bse.c
 *
 *  Created on: Nov 12, 2020 
 *      Author: Courtenay Huffman
 */

#include "bse.h"
#include "hwConfig.h"

enum
{
    NORMAL_BSE_OPERATION,
    BSE_OPEN_CIRCUIT,
    BSE_SHORT_CIRCUIT,
    BSE_OUT_OF_RANGE, // values outside normal operating range, but not open or short for more than 100ms
    APPS_BSE_ACTIVATED, // APPS sensor indicates >25% activation while BSE applied
    APPS_BSE_DEACTIVATED, // after APPS & BSE applied, power returns after APPS registers <5% activation
    BSE_SWEEP
};

// Static function prototypes
static void normal_bse_operation();
static void bse_open_circuit();
static void bse_short_circuit();
static void bse_out_of_range();
static void apps_bse_activated();
static void apps_bse_deactivated();
static void bse_sweep();

void bse_process(uint8_t state){
    switch(state)
    {
        case BSE_OPEN_CIRCUIT:
            bse_open_circuit();
            break;
        case BSE_SHORT_CIRCUIT:
            bse_short_circuit();
            break;
        case BSE_OUT_OF_RANGE:
            bse_out_of_range();
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
            normal_bse_operation();
            break;
    }
}

static void normal_bse_operation(){
    // bse sensor reads values between X(MIN) and X(MAX)
}

static void bse_open_circuit(){
    // bse sensor reads an open circuit (0V)
}

static void bse_short_circuit(){
    // bse sensor reads a short circuit (5V)
}

static void bse_out_of_range(){
    // bse sensor reads outside of normal operating range, but not a short or open circuit
}

static void bse_sweep(){

}

static void apps_bse_activated(){

}

static void apps_bse_deactivated(){
    
}
