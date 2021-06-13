/*
 * inverter.c
 *
 *  Created on: Jun 3, 2021
 *      Author: Rafael
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



unsigned int getInverterSignal(){

    Inverter_signal = getInverterReading();

    //do some calculations...

    return 0;

}


