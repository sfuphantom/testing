/*
 * inverter.c
 *
 *  Created on: Jun 3, 2021
 *      Author: Rafael Guevara
 */
#include "inverter.h"

static adcData_t Inverter_data;

static adcData_t* Inverter_data_ptr = &Inverter_data;

static unsigned int Inverter_signal = 0;

static unsigned int getInverterReading(){

    adcStartConversion(INVERTER_PORT, INVERTER_PIN);
    while (!adcIsConversionComplete(INVERTER_PORT, INVERTER_PIN));
    adcGetData(INVERTER_PORT, INVERTER_PIN, Inverter_data_ptr);

    return (unsigned int)Inverter_data_ptr->value;

}


//Receives raw ADC output from VCU throttle pin
//Returns 0-5V reading
unsigned int getInverterSignal(){

    Inverter_signal = getInverterReading();

    //TODO: do some calculations...

    #ifdef VCU_DEBUG

    //TODO: print Inverter reading through UART

    #endif


    return 1;

}

//Receives 0-5V reading
//Returns corresponding AC output
unsigned int getInverterOutput(){



    #ifdef VCU_DEBUG

    //TODO: print Inverter output through UART

    #endif

//    getInverterSignal();

    return 0;
}

