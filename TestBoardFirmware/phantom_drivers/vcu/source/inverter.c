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
static float Inverter_analog = 0;

#define ADref_HI 5.25
#define ADref_LOW 0
#define max_res 1023


static unsigned int getInverterReading(){

    adcStartConversion(INVERTER_PORT, INVERTER_PIN);
    while (!adcIsConversionComplete(INVERTER_PORT, INVERTER_PIN));
    adcGetData(INVERTER_PORT, INVERTER_PIN, Inverter_data_ptr);

    return (unsigned int)Inverter_data_ptr->value;

}


//Receives raw ADC output from VCU throttle pin
//Returns 0-5V reading
static float getInverterSignal(){

    Inverter_signal = getInverterReading();

    //TODO: do some calculations...
    if (Inverter_signal == max_res){
        Inverter_analog = ADref_HI;
    }
    else if (Inverter_signal == ADref_LOW){
        Inverter_analog = ADref_LOW;
    }
    else {
        Inverter_analog = Inverter_signal/max_res*(ADref_HI-ADref_LOW)+ADref_LOW;
    }

    #ifdef VCU_DEBUG

    //TODO: print Inverter reading through UART
    //Printing upto 2nd decimal places of the inverter input voltage value
    unsigned int Inverter_input = Inverter_analog*100;
    int i;
    for (i=2;i>=0;i--){
        uint8 bit =(int) (Inverter_input % 10);
        if (bit == 0){
            UARTprintf("0");
        }
        if (i==0){
            UARTprintf(",");
        }
        sciSend(PC_UART,1,&bit);
    }
    UARTprintf("\n\r");

    #endif

    return Inverter_analog;

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

