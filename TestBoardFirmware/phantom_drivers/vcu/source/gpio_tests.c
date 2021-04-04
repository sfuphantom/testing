/*

 * gpio_tests.c
 *
 *  Created on: Apr 1, 2021
 *      Author: Rafael Guevara
 */

//Pins (from hwConfig.h)
// #define SHUTDOWN_CIRCUIT_PORT gioPORTA
// #define BMS_FAULT_PIN         7 
// #define IMD_FAULT_PIN         6 

// #define BSPD_PORT             hetPORT1
// #define BSPD_FAULT_PIN        9 

// #define RESET_PORT            hetPORT1
// #define RESET_PIN             26

// #define READY_TO_DRIVE_PORT   gioPORTA
// #define READY_TO_DRIVE_PIN    2

//TODO: Setup in halcogen
		// - RTD signal/buzzer
		// - Shutdown GPIOs/HETs: IMD,BMS,BSPD

//Figure out how to use TSAL and BSE drivers here 

//Add Shutdown Tests...and other GPIOs


// #include "hwConfig.h" (merge with hwConfig branch first)
#include "gpio_tests.h"

typedef enum operation
{
    RTD_NORMAL_PROCEDURE //Get VCU to state RUNNING
    RTD_LATCH,  //Simulate RTD procedure -> turn off RTD
    RTD_INORDER, //Reverse order of RTD procedure
}operation;

// Static function definitions
static void rtd_normal_procedure();
static void rtd_latch_test();
static void rtd_inorder_test();

void gpio_init(){

	// initalize + configure pins

}

void gpio_process(operation testcase)
{
    switch(testcase)
    {
        case RTD_NORMAL_PROCEDURE:
            
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
* Fn: rtd_normal_procedure
* Purpose: Sends and holds GPIO signal '1' to TSAL then to BSE then to RTD *may need timer/delays?*
* Resulting State: RUNNING, Expect RTD buzzer HIGH   
*/
static void rtd_normal_procedure()
{
 	//turn TSAL ON 

	//delay?

	//send bse signal ON

	//delay?

	//finally, send RTD signal 


}

/*
* Fn: rtd_latch_test
* Purpose: Simulates RTD procedure then turns off RTD to check if VCU latches signal (shouldn't)
* Resulting State: TS_ON/OFF   
*/
static void rtd_latch_test()
{ 

	//RTD procedure 

	//delay?

	//turn off RTD signal 

}

/*
* Fn: rtd_inorder_test
* Purpose: Reverse RTD procedure ie Sends and holds GPIO signal '1' to RTD then to BSE then to TSAL *may need timer/delays?*
* Resulting State: !RUNNING   
*/
static void rtd_inorder_test()
{

	//send RTD signal 

	//delay?

	//send bse signal ON

	//delay?

	//finally, turn on TSAL

}

