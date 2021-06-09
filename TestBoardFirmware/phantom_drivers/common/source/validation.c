/*
 * validation.c
 *
 *  Created on: Jun 8, 2021
 *      Author: Rafael Guevara
 */

#include "validation.h"




uint8_t is_bms_slave_test_passed(uint8_t test_case){

    #ifdef VALID_DEBUG

    UARTprintf( (test_case != NORMAL_BMS_OPERATION) ? "Expected Result: BMS FAULTED\r\n" : "Expected Result: BMS NORMAL\r\n" );

    UARTprintf( gioGetBit( BMS_SHUTDOWN_PORT, BMS_SHUTDOWN_PIN ) ? "Received Result: BMS FAULTED\r\n" : "Expected Result: BMS NORMAL\r\n" );

    UARTprintf( (test_case != NORMAL_BMS_OPERATION) ==  gioGetBit( BMS_SHUTDOWN_PORT, BMS_SHUTDOWN_PIN ) ? "PASSED\r\n" : "FAILED\r\n" );

    #endif


    //expected result; normal operation should be zero
    return ( (test_case != NORMAL_BMS_OPERATION) ==  gioGetBit( BMS_SHUTDOWN_PORT, BMS_SHUTDOWN_PIN ) ); /* read shutdown pin */     //expected state
}


