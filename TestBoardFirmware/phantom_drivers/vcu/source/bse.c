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
    BSE_OUT_OF_RANGE // values outside normal operating range, but not open or short for more than 100ms
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
        case BSE_OUT_OF_RANGE:
            bse_out_of_range();
            break;
        default:
            normal_bse_operation();
            break;
    }
}

static void normal_bse_operation()
{
    // bse sensor reads values between X(MIN) and X(MAX)
}

static void bse_open_circuit()
{
    // bse sensor reads an open circuit (0V)
}

static void bse_short_circuit()
{
    // bse sensor reads a short circuit (5V)
}

static void bse_out_of_range()
{
    // bse sensor reads outside of normal operating range, but not a short or open circuit
}
