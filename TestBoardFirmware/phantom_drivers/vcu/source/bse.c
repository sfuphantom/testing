/*
 * bse.c
 *
 *  Created on: Nov 12, 2020 
 *      Author: Courtenay Huffman
 */

#include "bse.h"

enum
{
    NORMAL_BSE_OPERATION
};

// Static function prototypes
static void normal_bse_operation();

void bse_process(uint8_t state)
{
    switch(state)
    {
        case NORMAL_BSE_OPERATION:
            normal_bse_operation();
            break;
    }
}

static void normal_bse_operation()
{

}
