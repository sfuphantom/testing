/*

 * gpio_tests.c
 *
 *  Created on: Apr 1, 2021
 *      Author: Rafael Guevara
 */

//Pins (from hwConfig.h)
// #define SHUTDOWN_CIRCUIT_PORT gioPORTA (DONE)
// #define BMS_FAULT_PIN         7 
// #define IMD_FAULT_PIN         6 

// #define BSPD_PORT             hetPORT1
// #define BSPD_FAULT_PIN        9 

// #define RESET_PORT            hetPORT1
// #define RESET_PIN             26

// #define READY_TO_DRIVE_PORT   gioPORTA (DONE)
// #define READY_TO_DRIVE_PIN    2

//TODO: Setup in halcogen
		// - RTD signal (DONE)/buzzer
		// - Shutdown GPIOs/HETs: IMD,BMS,BSPD

//Figure out how to use TSAL and BSE drivers here 

//Add Shutdown Tests...and other GPIOs
#include "gpio_tests.h"

// Static function definitions
static void rtd_normal_procedure();
static void rtd_latch_test();
static void rtd_inorder_test();
//Shutdown

static void shutdown_latch_test();



void gpio_init(){

	// initalize + configure pins

    gioInit();

}

void gpio_process(uint8_t testcase)
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

    gioSetBit(TSAL_PORT, TSAL_ACTIVE_PIN, 1);

	//delay?
    delayms(500);

	//send bse signal ON
    bse_process(NORMAL_BSE_ON);

	//delay?
    delayms(500);

	//finally, send RTD signal 
    gioSetBit(READY_TO_DRIVE_PORT, READY_TO_DRIVE_PIN, 1);

}

/*
* Fn: rtd_latch_test
* Purpose: Simulates RTD procedure then turns off RTD to check if VCU latches signal (shouldn't)
* Resulting State: TS_ON
*/
static void rtd_latch_test()
{ 

	//RTD procedure 
    rtd_normal_procedure();

	//delay?
    delayms(1000);


	//turn off RTD signal 
    gioSetBit(READY_TO_DRIVE_PORT, READY_TO_DRIVE_PIN, 0);

}

/*
* Fn: rtd_inorder_test
* Purpose: Reverse RTD procedure ie Sends and holds GPIO signal '1' to RTD then to BSE then to TSAL *may need timer/delays?*
* Resulting State: !RUNNING   
*/
static void rtd_inorder_test()
{

    //reset and turn off everything

    gioSetBit(READY_TO_DRIVE_PORT, READY_TO_DRIVE_PIN, 0);

    gioSetBit(TSAL_PORT, TSAL_ACTIVE_PIN, 0);

    bse_process(NORMAL_BSE_OFF);

    //delay?
    delayms(500);


	//send RTD signal 
    gioSetBit(READY_TO_DRIVE_PORT, READY_TO_DRIVE_PIN, 1);

	//delay?
    delayms(500);


	//send bse signal ON
    bse_process(NORMAL_BSE_ON);

	//delay?
    delayms(500);


	//finally, turn on TSAL
    gioSetBit(TSAL_PORT, TSAL_ACTIVE_PIN, 1);


}

static void shutdown_latch_test(){

    gioSetBit(SHUTDOWN_CIRCUIT_PORT, IMD_FAULT_PIN, 1);

    //delay?
    delayms(500);

    gioSetBit(SHUTDOWN_CIRCUIT_PORT, IMD_FAULT_PIN, 0);

    apps_process(NORMAL_APPS_ON); //zero motor output

}





























