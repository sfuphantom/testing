/*
 * bse.h
 *
 *  Created on: Nov 12, 2020 
 *      Author: Courtenay Huffman
 */

#ifndef PHANTOM_DRIVERS_INCLUDE_BSE_H_
#define PHANTOM_DRIVERS_INCLUDE_BSE_H_

#include "stdint.h"

#include "Phantom_sci.h"

#include "hwConfig.h"
#include "MCP48FV_DAC_SPI.h"

#include "timer.h"

//FreeRTOS files
//#include "FreeRTOS.h"
//#include "FreeRTOSConfig.h"
//#include "os_task.h"
//#include "os_timer.h"

#include "common.h"

void bse_process(uint8_t state);

//Timer Callback Functions
void bse_sweep_timer(int);


enum
{
    NORMAL_BSE_OFF,
    NORMAL_BSE_ON,
    BSE_OPEN_CIRCUIT, //0V reading
    BSE_SHORT_CIRCUIT, //5V reading
    BSE_APPS_ACTIVATED, // APPS sensor indicates >25% activation while BSE applied
    BSE_SWEEP
};



#endif /* PHANTOM_DRIVERS_INCLUDE_BSE_H_ */
