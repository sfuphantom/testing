/*
 * bms_slaves.c
 *
 *  Created on: Oct 25, 2020
 *      Author: Mahmoud Ahmed
 */
#include "bms_slaves.h"
#include "stdlib.h"
#include "Phantom_sci.h"
#include "common.h"
#include "MCP48FV_DAC_SPI.h"
#include "hwConfig.h"
#include "timer.h" 
#include "gio.h"
#include "het.h"

// #include "FreeRTOS.h"
// #include "os_timer.h"

// BMS Slave specific definitions, not accessed outside bms_slaves.c
#define VOLTAGE_STEP  0.04
#define DEFAULT_VOLTAGE 840
#define DEFAULT_TEMPERATURE 250
#define NUMBER_OF_TEMPERATURE_READINGS 160

#define TRANSFER_GROUP 2

// THESE VALUES NEED TO BE CHECKED - all must be an INT
#define TEMP_MAX_VOLT  1131 // 1.131 == 55 degrees
#define TEMP_MIN_VOLT  2682 // 2.682 = 0 degrees
#define TEMP_HIGH_VOLT  668 //66.83 // 0.6683 = 76 degrees
#define TEMP_LOW_VOLT 2700 // 2.70 = 0 degrees
#define VOLT_MIN  761 // 0.7608 * 100
#define VOLT_MAX  999 // 0.9985 * 100

// CHANGE THIS VALUE TO
#define VOLT_TEST 0 //102 = 84.5

//const uint8_t[] BMS_FAULT_LUT = {   }


typedef struct {
    float bmsSlaveVoltage;
    float bmsSlaveTemperatures[NUMBER_OF_TEMPERATURE_READINGS];
} BMSSlave_t; // BMSSlave_t is like double or int

// Static Global Variables
static BMSSlave_t *bmsStruct;
static BMSSlave_t *bmsTempHigh;
static BMSSlave_t *bmsTempLow;

// Static function definitions
static void normal_bms_operation();
static void over_voltage_test();
static void under_voltage_test();
static void over_temperature_test();
static void under_temperature_test();
//static void weird_sensor_readings_voltage_test();
//static void weird_sensor_readings_temperature_test();
static void communication_loss_test();
static void temperature_mux(uint8_t pinSelect);

Result_t bms_slaves_process(uint8_t state)
{

    bms_slaves_init();

    switch(state)
    {
        case NORMAL_BMS_OPERATION:
            normal_bms_operation();
            break;
        case OVER_VOLTAGE_FAULT:
            over_voltage_test();
            break;
        case UNDER_VOLTAGE_FAULT:
            under_voltage_test();
            break;
        case OVER_TEMPERATURE_FAULT:
            over_temperature_test();
            break;
        case UNDER_TEMPERATURE_FAULT:
            under_temperature_test();
            break;
        case WEIRD_SENSOR_READINGS_VOLTAGE:
            //weird_sensor_readings_voltage_test();
            break;
        case WEIRD_SENSOR_READINGS_TEMPERATURE:
            //weird_sensor_readings_temperature_test();
            break;
        case COMMUNICATION_LOSS:
            communication_loss_test();
            break;
    }

    return SUCCESS;
}

void bms_slaves_init(){

    gioSetBit(HV_ACTIVE_PORT, HV_ACTIVE_PIN, 1);

    bmsStruct->bmsSlaveVoltage =  DEFAULT_VOLTAGE;
    uint8_t i;
    for(i = 0; i < NUMBER_OF_TEMPERATURE_READINGS; i++) {
        bmsStruct->bmsSlaveTemperatures[i] = (TEMP_MAX_VOLT + TEMP_MIN_VOLT)*0.5;
    }

    bmsTempHigh->bmsSlaveVoltage = DEFAULT_VOLTAGE;
    uint8_t j;
    for(j=0; j < NUMBER_OF_TEMPERATURE_READINGS; j++) {
        bmsTempHigh->bmsSlaveTemperatures[j] = (TEMP_MAX_VOLT + TEMP_MIN_VOLT)*0.5;
    }
    bmsTempHigh->bmsSlaveTemperatures[0] = TEMP_MAX_VOLT*1.5;
    
    bmsTempLow->bmsSlaveVoltage = DEFAULT_VOLTAGE;
    uint8_t k;
    for(k = 0; j < NUMBER_OF_TEMPERATURE_READINGS; j++) {
        bmsTempLow->bmsSlaveTemperatures[j] =(TEMP_MAX_VOLT + TEMP_MIN_VOLT)*0.5;
    }
    bmsTempLow->bmsSlaveTemperatures[0] = 0;
    UARTprintf("BMS Initialization Complete");

}

// Send a constant 3.8V
static void normal_bms_operation(){

    // set_bms_voltage and temp at normal levels
    UARTprintf("Normal BMS Operation\n\r");

    MCP48FV_Set_Value_Single(VOLT_TEST, DAC_SIZE_BMS, 0, 2);

    uint8_t pinSelect = 0;
    //setting temp on each of the 16 pins
    for( ; pinSelect <= 00001111; pinSelect++){
        temperature_mux(pinSelect); 
        MCP48FV_Set_Value_Single(bmsStruct->bmsSlaveTemperatures[pinSelect], DAC_SIZE_BMS, 1, TRANSFER_GROUP);
    }
}

static void under_voltage_test() {
   
    //send a voltage under the opperating region (3.2-4.2)
    //send 2.7V for more than 3 seconds
    MCP48FV_Set_Value_Single(VOLT_MIN, DAC_SIZE_BMS, 0, TRANSFER_GROUP);

    uint8_t pinSelect = 0;
    for( ; pinSelect <= 00001111; pinSelect++){// for loop - iterate over each pin
        temperature_mux(pinSelect);
        // set the DAC
        MCP48FV_Set_Value_Single(bmsStruct->bmsSlaveTemperatures[pinSelect], DAC_SIZE_BMS, 1, TRANSFER_GROUP);
    }
}

static void over_voltage_test(){

    //send a voltage over the opperating region (3.2-4.2)
    //send 4.7V for more than 3 seconds
    MCP48FV_Set_Value_Single(VOLT_MAX, DAC_SIZE_BMS, 0, TRANSFER_GROUP);

    uint8_t pinSelect = 0;
    for( ; pinSelect <= 00001111; pinSelect++){// for loop - iterate over each pin
        temperature_mux(pinSelect);
        // set the DAC
        MCP48FV_Set_Value_Single(bmsStruct->bmsSlaveTemperatures[pinSelect], DAC_SIZE_BMS, 1, TRANSFER_GROUP);
    } 
}

static void under_temperature_test(){ 

    //send a temperature voltage over the opperating region (55 degrees C)
    //send 60 C for more than 3 seconds

    MCP48FV_Set_Value_Single((VOLT_MAX + VOLT_MIN)*0.5, DAC_SIZE_BMS, 0, TRANSFER_GROUP);

    uint8_t pinSelect = 0;
    for( ; pinSelect <= 0b00001111; pinSelect++){// for loop - iterate over each pin
        temperature_mux(pinSelect); 
        // set the DAC
        MCP48FV_Set_Value_Single(bmsTempLow->bmsSlaveTemperatures[pinSelect], DAC_SIZE_BMS, 1, TRANSFER_GROUP); 
    }
}

static void over_temperature_test(){

    //send a temperature voltage over the opperating region (55 degrees C)
    //send 60 C for more than 3 seconds

    MCP48FV_Set_Value_Single((VOLT_MAX + VOLT_MIN)*0.5, DAC_SIZE_BMS, 0, TRANSFER_GROUP);

    uint8_t pinSelect = 0;
    for( ; pinSelect <= 0b00001111; pinSelect++){// for loop - iterate over each pin
        temperature_mux(pinSelect); 
        // set the DAC
        MCP48FV_Set_Value_Single(bmsTempHigh->bmsSlaveTemperatures[pinSelect], DAC_SIZE_BMS, 1, TRANSFER_GROUP); 
    }
}

static void communication_loss_test(){

    // send nothing 
    // "what is timing out of messages"

    MCP48FV_Set_Value_Single(0, DAC_SIZE_BMS, 0, TRANSFER_GROUP);

    uint8_t pinSelect = 0;
     for( ; pinSelect <= 00001111; pinSelect++){// for loop - iterate over each pin
         temperature_mux(pinSelect);
         // set the DAC
       MCP48FV_Set_Value_Single(0, DAC_SIZE_BMS, 1, TRANSFER_GROUP);
     }
    return;
}

// *****temperature mux function (loop)*****
static void temperature_mux(uint8_t pinSelect){

     // set the different mux pins
    if (0b00000001 & pinSelect){ 
        gioSetBit(THERMISTOR_MUX_HET_PORT, THERMISTOR_MUX_PIN_0, 1);
    } else {
        gioSetBit(THERMISTOR_MUX_HET_PORT, THERMISTOR_MUX_PIN_0, 0);
    }
    if ((0b000010 & pinSelect) >> 1){ 
        gioSetBit(THERMISTOR_MUX_HET_PORT, THERMISTOR_MUX_PIN_1, 1);
    } else {
        gioSetBit(THERMISTOR_MUX_HET_PORT, THERMISTOR_MUX_PIN_1, 0);
    }
    if ((0b000100 & pinSelect) >> 2){ 
        gioSetBit(THERMISTOR_MUX_GIO_PORT, THERMISTOR_MUX_PIN_2, 1);
    } else {
        gioSetBit(THERMISTOR_MUX_GIO_PORT, THERMISTOR_MUX_PIN_2, 0);
    }
    if ((0b001000 & pinSelect) >> 3){ 
        gioSetBit(THERMISTOR_MUX_HET_PORT, THERMISTOR_MUX_PIN_3, 1);
    } else {
        gioSetBit(THERMISTOR_MUX_HET_PORT, THERMISTOR_MUX_PIN_3, 0);
    }

    return;
 }
