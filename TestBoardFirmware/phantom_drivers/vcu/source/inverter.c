/*
 * inverter.c
 *
 *  Created on: Jun 3, 2021
 *      Author: Rafael Guevara
 */
#include "inverter.h"

static adcData_t Inverter_data;

static adcData_t* Inverter_data_ptr = &Inverter_data;

static float Inverter_signal;
static float Inverter_analog;

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
float getInverterSignal(){

    Inverter_signal = getInverterReading();
    Inverter_analog = Inverter_signal/max_res*(ADref_HI-ADref_LOW)+ADref_LOW;

    #ifdef VCU_DEBUG

    //TODO: print Inverter reading through UART
    //Printing upto 2nd decimal places of the inverter input voltage value
    UARTprintf("Throttle Input Voltage Value: \n\r");
    unsigned int Inverter_input = (int) (Inverter_analog);
    int i,j;
    for (i=2;i>=0;i--){
        uint8 bit =(int) (Inverter_input % 10);
        for (j=3;j>=0;j--){
            uint8 t=(int) ((bit >> j) & 1);
            if (t == 0){
                UARTprintf("0");
            }
            sciSend(PC_UART,1,&t);
        }
        if(i==2){
            UARTprintf(".");
            Inverter_input = (int) (Inverter_analog*10);
        }
        if(i==1){
            UARTprintf(" ");
            Inverter_input = (int) (Inverter_analog*100);
        }
    }
    UARTprintf("\n\n\r");

    #endif

    return Inverter_analog;

}
