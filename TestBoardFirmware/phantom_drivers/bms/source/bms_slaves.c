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
#define DEFAULT_VOLTAGE 84
#define DEFAULT_TEMPERATURE 25
#define NUMBER_OF_TEMPERATURE_READINGS 16

#define TRANSFER_GROUP 2

// THESE VALUES NEED TO BE CHECKED - all must be an INT
#define TEMP_MAX_VOLT  113 // 1.131 == 55 degrees
#define TEMP_MIN_VOLT  268 // 2.682 = 0 degrees
#define TEMP_HIGH_VOLT  67 //66.83 // 0.6683 = 76 degrees
#define TEMP_LOW_VOLT 270 // 2.70 = 0 degrees
#define VOLT_MIN  76 // 0.7608 * 100
#define VOLT_MAX  100 // 0.9985 * 100

enum
{
    NORMAL_BMS_OPERATION,
    VOLTAGE_FAULT,
    TEMPERATURE_FAULT,
    WEIRD_SENSOR_READINGS_VOLTAGE,
    WEIRD_SENSOR_READINGS_TEMPERATURE,
    COMMUNICATION_LOSS,
};

typedef struct {
    float bmsSlaveVoltage;
    float bmsSlaveTemperatures[NUMBER_OF_TEMPERATURE_READINGS];
} BMSSlave_t; // BMSSlave_t is like double or int

// Static Global Variables
static BMSSlave_t *bmsStruct;
static BMSSlave_t *bmsTempFault;

// Static function definitions
static void normal_bms_operation();
static void voltage_test();
static void temperature_test();
static void weird_sensor_readings_voltage_test();
static void weird_sensor_readings_temperature_test();
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

        case VOLTAGE_FAULT:
            voltage_test();
            break;
        case TEMPERATURE_FAULT:
            temperature_test();
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
        bmsStruct->bmsSlaveTemperatures[i] = DEFAULT_TEMPERATURE;
    }
    bmsTempFault->bmsSlaveVoltage = DEFAULT_VOLTAGE;
    uint8_t j = 0;
    for(i = j; j < NUMBER_OF_TEMPERATURE_READINGS; j++) {
        bmsTempFault->bmsSlaveTemperatures[j] = DEFAULT_TEMPERATURE;
    }
    bmsTempFault->bmsSlaveTemperatures[0] = DEFAULT_TEMPERATURE*2;
    UARTprintf("BMS Initialization Complete");
}

// Send a constant 3.8V
static void normal_bms_operation(){

    // set_bms_voltage and temp at normal levels
    UARTprintf("Normal BMS Operation\n\r");

    MCP48FV_Set_Value_Single(TEMP_HIGH_VOLT, DAC_SIZE_BMS, 0, 2);

    uint8_t pinSelect = 0;
    //setting temp on each of the 16 pins
    for( ; pinSelect <= 00001111; pinSelect++){
        temperature_mux(pinSelect); 
        MCP48FV_Set_Value_Single(bmsStruct->bmsSlaveTemperatures[pinSelect], DAC_SIZE_BMS, 1, TRANSFER_GROUP);
    }
}

static void voltage_test(){

    //send a voltage over the opperating region (3.2-4.2)
    //send 4.7V for more than 3 seconds
    MCP48FV_Set_Value_Single(VOLT_MAX, DAC_SIZE_BMS, 0, TRANSFER_GROUP);

    //send a voltage under the opperating region (3.2-4.2)
    //send 2.7V for more than 3 seconds
    //MCP48FV_Set_Value_Single(VOLT_MIN, DAC_SIZE_BMS, 0, TRANSFER_GROUP);

    uint8_t pinSelect = 0;
    for( ; pinSelect <= 00001111; pinSelect++){// for loop - iterate over each pin
        temperature_mux(pinSelect);
        // set the DAC
        MCP48FV_Set_Value_Single(bmsStruct->bmsSlaveTemperatures[pinSelect], DAC_SIZE_BMS, 1, TRANSFER_GROUP);
    } 
}

static void temperature_test(){

    //send a temperature voltage over the opperating region (55 degrees C)
    //send 60 C for more than 3 seconds

    MCP48FV_Set_Value_Single((VOLT_MAX + VOLT_MIN)*0.5, DAC_SIZE_BMS, 0, TRANSFER_GROUP);

    uint8_t pinSelect = 0;
    for( ; pinSelect <= 0b00001111; pinSelect++){// for loop - iterate over each pin
        temperature_mux(pinSelect); 
        // set the DAC
        MCP48FV_Set_Value_Single(bmsTempFault->bmsSlaveTemperatures[pinSelect], DAC_SIZE_BMS, 1, TRANSFER_GROUP); 
    }
}

static void communication_loss_test(){

    // send nothing 
    // "what is timing out of messages"

    // MCP48FV_Set_Value_Single(0, DAC_SIZE, 0, TRANSFER_GROUP);

    // for(uint8_t pinSelect = 0b00000000; pinSelect <= 00001111; pinSelect++){// for loop - iterate over each pin
    //     temperature_mux(pinSelect) 
    //     // set the DAC
    //     MCP48FV_Set_Value_Single(bmsStruct->bmsSlaveTemperatures[pinSelect], DAC_SIZE, 1, TRANSFER_GROUP);
    // }
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

    return 0;
 }
