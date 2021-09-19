/*
 * validation.c
 *
 *  Created on: Jun 8, 2021
 *      Author: Rafael Guevara
 */

#include "validation.h"

//index values for range of LUTs
#define LOW_BOUND 0
#define UP_BOUND 1

//Lookup tables for expected results from the VCU

//TODO: Fill out ranges for expected results ie { MIN, MAX } -> { 10, 20 } =  10 <= expected result <= 20

//reference equation from throttle task 390 * apps_percent_avg + 60
//#define APPS1_MAX 440
//#define APPS1_MIN 150
//#define APPS2_MAX 150
//#define APPS2_MIN 50

static const unsigned int APPS_RESULTS_LUT[][2] = { { 245, 265 }, //NORMAL_APPS_ON expected result 255 (apps_percent = 0.5) +/- 10

                                                   { 50, 70 }, //NORMAL_APPS_OFF expected result 60 (apps_percent = 0) +/- 10

                                                   { 0, 0 }, //APPS_IMPLAUSIBILITY...

                                                   { 0, 0 }, //APPS_SHORT_CIRCUIT...

                                                   { 0, 0 }, //APPS_OPEN_CIRCUIT...

                                                   { 0, 0 }, //APPS_BSE_ACTIVATED...

                                                   { 440, 460 } //APPS_SWEEP expected (END) result 450 (apps_percent = 100) +/- 10

                                                };

static const unsigned int BSE_RESULTS_LUT[][2]  = {  { 0, 20 }, //NORMAL_BSE_OFF result (whatever apps is sending)

                                                   { 0, 0 }, //NORMAL_BSE_ON...

                                                   { 0, 0 }, //BSE_OPEN_CIRCUIT...

                                                   { 0, 0 }, //BSE_SHORT_CIRCUIT...

                                                   { LOW_BOUND, UP_BOUND }, //BSE_APPS_ACTIVATED (previously the implausibility) ...

                                                   { LOW_BOUND, UP_BOUND } //BSE_SWEEP...

                                                };

//static const uint8_t[] GPIO_RESULTS_LUT = { /* RUNNING */ 0 , /* TS_OFF */0, 0 /* !RUNNING */, /* ZERO THROTTLE */ 0}; //wait for CAN driver...

static bool validateAPPS(uint8_t, unsigned int);

static bool validateBSE(uint8_t testcase, unsigned int);


uint8_t is_bms_slave_test_passed(uint8_t test_case){

    #ifdef BMS_DEBUG

    UARTprintf( (test_case != NORMAL_BMS_OPERATION) ? "Expected Result: BMS FAULTED\r\n" : "Expected Result: BMS NORMAL\r\n" );

    UARTprintf( gioGetBit( BMS_SHUTDOWN_PORT, BMS_SHUTDOWN_PIN ) ? "Received Result: BMS FAULTED\r\n" : "Expected Result: BMS NORMAL\r\n" );

    UARTprintf( (test_case != NORMAL_BMS_OPERATION) ==  gioGetBit( BMS_SHUTDOWN_PORT, BMS_SHUTDOWN_PIN ) ? "PASSED\r\n" : "FAILED\r\n" );

    #endif


    //expected result; normal operation should be zero
    return ( (test_case != NORMAL_BMS_OPERATION) ==  gioGetBit( BMS_SHUTDOWN_PORT, BMS_SHUTDOWN_PIN ) ); /* read shutdown pin */     //expected state
}


bool validateThrottleControls(uint8_t apps_test, uint8_t bse_test){

    //grab inverter signal and apps/bse test cases

    unsigned int inverter_sig = getInverterSignal();

    return ( validateAPPS(apps_test, inverter_sig) && validateBSE(bse_test, inverter_sig) );
}

static bool validateAPPS(uint8_t testcase, unsigned int inverter_sig){


    #ifdef VCU_DEBUG

    UARTprintf( (APPS_RESULTS_LUT[testcase][LOW_BOUND] <= inverter_sig) && (inverter_sig <= APPS_RESULTS_LUT[testcase][UP_BOUND]) ? "APPS Result: TEST PASSED\r\n" : "APPS Result: TEST FAILED\r\n" );

    #endif

    //check if received value is within range of result

    return ( (APPS_RESULTS_LUT[testcase][LOW_BOUND] <= inverter_sig) && (inverter_sig <= APPS_RESULTS_LUT[testcase][UP_BOUND]) );

}

static bool validateBSE(uint8_t testcase, unsigned int inverter_sig){


    #ifdef VCU_DEBUG

    UARTprintf( (BSE_RESULTS_LUT[testcase][LOW_BOUND] <= inverter_sig) && (inverter_sig <= BSE_RESULTS_LUT[testcase][UP_BOUND]) ? "BSE Result: TEST PASSED\r\n" : "BSE Result: TEST FAILED\r\n" );

    #endif

    //check if received value is within range of result

    return ( (BSE_RESULTS_LUT[testcase][LOW_BOUND] <= inverter_sig) && (inverter_sig <= BSE_RESULTS_LUT[testcase][UP_BOUND]) );

}



