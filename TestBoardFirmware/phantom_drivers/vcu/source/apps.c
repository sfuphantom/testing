/*
 * apps.c
 *
 *  Created on: Nov 12, 2020 
 *      Author: Courtenay Huffman
 */

#include "apps.h"

enum
{
    NORMAL_APPS_OPERATION
};

// Static function prototypes
static void normal_apps_operation();

void apps_process(uint8_t state)
{
    switch(state)
    {
        case NORMAL_APPS_OPERATION:
            normal_apps_operation();
            break;
    }
}

static void normal_apps_operation()
{

}
