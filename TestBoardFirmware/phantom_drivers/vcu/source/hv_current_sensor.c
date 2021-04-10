/*
 * hv_current_sensor.c
 *
 *  Created on: Nov 10, 2020 
 *      Author: Sumreen Rattan
 */

#include "hv_current_sensor.h"

typedef enum operation
{
    NORMAL_HV_CS_OPERATION,
    ZERO_CURRENT, // 0 Amps 
    MAX_CURRENT, //5V or 300Amps 
    SWEEP,
    CURRENT_WITHOUT_APPS
}operation;

// Static function prototypes
static void normal_hv_cs_operation();
static float send_current(int CURRENT_VALUE);

void hv_cs_process(uint8_t state)
{
    switch(state)
    {
        case NORMAL_HV_CS_OPERATION:
            normal_hv_cs_operation();
            break;
    }
}


/*
* Fn: normal_hv_cs_operation
* Purpose:   
*/
static void normal_hv_cs_operation()
{

}

/*
* Fn: send_current
* Purpose: helper function, user defines the current and this function converts to an voltage output  
*/
static float send_current(int CURRENT_VALUE)
{
    return 0;
}
