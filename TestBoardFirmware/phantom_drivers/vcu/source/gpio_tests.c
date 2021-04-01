/*

 * gpio_tests.c
 *
 *  Created on: Apr 1, 2021
 *      Author: Rafael Guevara
 */

//Pins
// #define SHUTDOWN_CIRCUIT_PORT gioPORTA
// #define BMS_FAULT_PIN         7 
// #define IMD_FAULT_PIN         6 

// #define BSPD_PORT             hetPORT1
// #define BSPD_FAULT_PIN        9 

// #define RESET_PORT            hetPORT1
// #define RESET_PIN             26

// #define READY_TO_DRIVE_PORT   gioPORTA
// #define READY_TO_DRIVE_PIN    2

// #include "hwConfig.h"
#include "gpio_tests.h"


enum operation 
{
    RTD_NORMAL_PROCEDURE //Get VCU to state RUNNING
    RTD_LATCH,  //Simulate RTD procedure -> turn off RTD
    RTD_INORDER, //Reverse order of RTD procedure
};

// Static function definitions
static void rtd_normal_procedure();
static void rtd_latch_test();
static void rtd_inorder_test();

void gpio_init(){

	// initalize + configure pins

}

void gpio_process(uint8_t state)
{
    switch(state)
    {
        case NORMAL_HV_VS_OPERATION:
            
            rtd_normal_procedure();

            break;

        case RTD_LATCH:


        	rtd_latch_test();

        	break;

        case RTD_INORDER:

        	rtd_inorder_test();

        	break;
    }
}

/*
* Fn: normal_imd_operation
* Purpose: Sends and holds GPIO signal '1' to TSAL then to BSE then to RTD *may need timer/delays?*
* Resulting State: RUNNING   
*/
static void rtd_normal_procedure()
{
        
}

/*
* Fn: rtd_latch_test
* Purpose: Simulates RTD procedure then turns off RTD to check if VCU latches signal (shouldn't)
* Resulting State: TS_ON/OFF   
*/
static void rtd_latch_test()
{ 

	
}

/*
* Fn: rtd_inorder_test
* Purpose: Reverse RTD procedure ie Sends and holds GPIO signal '1' to RTD then to BSE then to TSAL *may need timer/delays?*
* Resulting State: !RUNNING   
*/
static void rtd_inorder_test()
{
    
}
