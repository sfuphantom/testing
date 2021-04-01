/*

 * gpio_tests.c
 *
 *  Created on: Apr 1, 2021
 *      Author: Rafael Guevara
 */


#include "gpio_tests.h"


enum operation 
{
    RTD_NORMAL_PROCEDURE //Get VCU to state RUNNING
    RTD_LATCH,  //Simulate RTD procedure -> turn off RTD
    RTD_INORDER, //Reverse order of RTD procedure
};


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