/*
 * imd.c
 *
 *  Created on: Nov 10, 2020 
 *      Author: Sumreen Rattan
 */
#include "imd.h"

enum
{
    NORMAL_IMD_OPERATION
};

// Static function definitions
static void normal_imd_operation();

void imd_process(uint8_t state)
{
    switch(state)
    {
        case NORMAL_IMD_OPERATION:
            normal_imd_operation();
            break;
    }
}

static void normal_imd_operation()
{

}
