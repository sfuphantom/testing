///*
// * imd.c
// *
// *  Created on: Nov 10, 2020
// *      Author: Sumreen Rattan
// */
//#include "imd.h"
//
//typedef enum operation
//{
//    NORMAL_IMD_OPERATION, // When Duty Cycle 5-10%
//    ISOLATION_FAILURE, //When Duty Cycle is 90-95%
//    DEVICE_FAILURE, // 50% Duty Cycle, 40hz Frequency
//    OUT_OF_RANGE, // Duty Cycle is outside of range (below 5% or above 95%)
//    DEVICE_SWEEP, // 0-50hz Frequency, Expected corresponding duty cycle
//    ISOLATION_SWEEP, //10hz Frequency, 5-95% duty cycle
//}operation;
//
//// Static function definitions
//static void normal_imd_operation();
//
//void imd_process(uint8_t state)
//{
//    switch(state)
//    {
//        case NORMAL_IMD_OPERATION:
//            normal_imd_operation();
//            break;
//    }
//}
//
//static void normal_imd_operation()
//{
//
//    return;
//    // initalize + configure pin
//    // set duty cycle and freq
//    // output values to pin
//}
//
///*
//* Fn: isolation_failure
//* Purpose: Sends a square wave to the VCU that indicates HV isolation failure
//* 92% Duty cycle, 10hz Frequency
//*/
//static void isolation_failure()
//{
//    // initalize + configure pin
//    // set duty cycle and freq
//    // output values to pin
//
//}
//
///*
//* Fn: device_failure
//* Purpose: Sends a square wave to the VCU that indicates the IMD device is not working
//* 50% Duty Cycle, 40hz Frequency
//*/
//static void device_failure()
//{
//    // initalize + configure pin
//    // set duty cycle and freq
//    // output values to pin
//}
//
//
///*
//* Fn: out_of_range
//* Purpose: Sends a square wave to the VCU that is not consistent with expected values
//* ex. Above 95% or below 5% Duty Cycle, Above 50hz Frequency
//* 97% Duty Cycle, 60hz Frequency
//*/
//static void out_of_range()
//{
//    // initalize + configure pin
//    // set duty cycle and freq
//    // output values
//}
//
///*
//* Fn: device_sweep
//* Purpose: Sends a square wave to the VCU that goes through all possible Device States
//* Sweeps through different frequencies
//* ex. Send 0-50hz Frequency & the expected corresponding duty cycle for that frequency
//*/
//static void device_sweep()
//{
//    // initalize + configure pin
//
//    // initialize timer
//    // use timer to cycle through different frequencies
//    // output values to pin
//
//}
//
///*
//* Fn: isolation_sweep
//* Purpose: Sends a square wave to the VCU that goes through all possible Isolation States
//* ex. 10hz Frequency, 5-95% duty cycle
//*/
//static void isolation_sweep()
//{
//
//}
//
///*
//* Fn: set_freq
//* Purpose: to be able to send any freq
//* ex. 10hz Frequency, 5-95% duty cycle
//*/
//static float set_freq()
//{
//    // initalize + configure pin
//    // set duty cycle and freq
//    // output values
//
//}
//
///*
//* Fn: set_duty
//* Purpose: to be able to send any duty cycle
//* ex. 10hz Frequency, 5-95% duty cycle
//*/
//static float set_duty()
//{
//    // initalize + configure pin
//    // set duty cycle and freq
//    // output values
//}
//
///*
//* Fn: initalize_IMD
//* Purpose: to initalize IMD pin
//*/
//static void initalize_IMD()
//{
//    // initalize + configure pin
//}
//
//
///*
//* Fn: serialSendData
//* Purpose: prints the current Frequency and Duty Cycle
//*/
//void serialSendData() {
//	 // adding this 0.5 and then typecasting to an int (truncating all decimals)
//    // basically acts as rounding the float to the nearest integer
//
//    return;
//
////    freq_value = (unsigned int) (frequency + 0.5);
////    duty_value = (unsigned int) (duty_cycle*100.0 + 0.5);
////
////    NumberofCharsFreq = ltoa(freq_value, (char*) freq_data);
////    NumberofCharsDuty = ltoa(duty_value, (char*) duty_data);
////
////    sciSend(scilinREG, NumberofCharsFreq, freq_data);
////    sciSend(scilinREG, 4, (unsigned char*)" Hz ");
////
////    sciSend(scilinREG, NumberofCharsDuty, duty_data);
////    sciSend(scilinREG, 4, (unsigned char*)" %\r\n");
//}
