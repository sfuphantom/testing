/*
 * bse.c
 *
 *  Created on: Nov 12, 2020 
 *      Author: Courtenay Huffman
 */

#include "bse.h"

enum
{
    NORMAL_BSE_OPERATION,
    BSE_OPEN_CIRCUIT,
    BSE_SHORT_CIRCUIT,
    BSE_IMPLAUSIBILITY
};

// Static function prototypes
static void normal_bse_operation();

void bse_process(uint8_t state)
{
    switch(state)
    {
        case BSE_OPEN_CIRCUIT:
            bse_open_circuit();
            break;
        case BSE_SHORT_CIRCUIT:
            bse_short_circuit();
            break;
        case BSE_IMPLAUSIBILITY:
            bse_implausibility();
            break;
        default:
            normal_bse_operation();
            break;
    }
}

static void normal_bse_operation()
{

}

static void bse_open_circuit(){

}

static void bse_short_circuit(){

}

static void bse_implausibility(){

}
