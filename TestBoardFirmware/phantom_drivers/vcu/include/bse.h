/*
 * bse.h
 *
 *  Created on: Nov 12, 2020 
 *      Author: Courtenay Huffman
 */

#ifndef PHANTOM_DRIVERS_INCLUDE_BSE_H_
#define PHANTOM_DRIVERS_INCLUDE_BSE_H_

#include "stdint.h"

void bse_process(uint8_t state);


enum
{
    NORMAL_BSE_OFF,
    NORMAL_BSE_ON,
    BSE_OPEN_CIRCUIT, //0V reading
    BSE_SHORT_CIRCUIT, //5V reading
    APPS_BSE_ACTIVATED, // APPS sensor indicates >25% activation while BSE applied
    BSE_SWEEP
};



#endif /* PHANTOM_DRIVERS_INCLUDE_BSE_H_ */
