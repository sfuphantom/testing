/*
 * bms_slaves.c
 *
 *  Created on: Oct 25, 2020
 *      Author: Mahmoud Ahmed
 *      Further Development and Refactoring: Courtenay Huffman
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

#define VOLTAGE_STEP  0.04 
#define DEFAULT_VOLTAGE 840 //this should probably be the max? probably 72V
#define DEFAULT_TEMP 2064 // 23 degrees
#define NUMBER_OF_TEMPERATURE_READINGS 16 // represents 2 slaves

#define TRANSFER_GROUP 2

#define TEMP_MAX_VOLT  1106 // 55 degrees 
#define TEMP_MIN_VOLT  2705 // 0 degrees
#define VOLT_MIN  761 // this should probably be 48V
#define VOLT_MAX  999 // probably 84V

typedef struct {
    float bmsSlaveVoltage;
    float bmsSlaveTemperatures[NUMBER_OF_TEMPERATURE_READINGS];
} BMSSlave_t;

// Static Global Variables
static BMSSlave_t *bmsSlaveData;
static BMSSlave_t *bmsSlaveData_HIGH;
static BMSSlave_t *bmsSlaveData_LOW;

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

    bmsSlaveData->bmsSlaveVoltage =  DEFAULT_VOLTAGE;
    uint8_t i;
    for(i = 0; i < NUMBER_OF_TEMPERATURE_READINGS; i++) {
        bmsSlaveData->bmsSlaveTemperatures[i] = DEFAULT_TEMP; 
    }

    bmsSlaveData_HIGH->bmsSlaveVoltage =  VOLT_MAX; 
    for(i = 0; i < NUMBER_OF_TEMPERATURE_READINGS; i++) {
        bmsSlaveData_HIGH->bmsSlaveTemperatures[i] = TEMP_MAX_VOLT; 
    }

    bmsSlaveData_LOW->bmsSlaveVoltage =  VOLT_MIN; 
    for(i = 0; i < NUMBER_OF_TEMPERATURE_READINGS; i++) {
        bmsSlaveData_LOW->bmsSlaveTemperatures[i] = TEMP_MIN_VOLT;
    }

    //make these a normal bms values?
    set_voltage(0);
    set_temperature(0);

    UARTprintf("BMS Initialization Complete");
}

// Send a constant 3.8V
static void normal_bms_operation(){
    set_voltage(bmsSlaveData->bmsSlaveVoltage);
    set_temperature(bmsSlaveData->bmsSlaveTemperatures);

}

static void under_voltage_test() {
    set_voltage(bmsSlaveData_LOW->bmsSlaveVoltage);
    set_temperature(bmsSlaveData->bmsSlaveTemperatures);

}

static void over_voltage_test(){
    set_voltage(bmsSlaveData_HIGH->bmsSlaveVoltage);
    set_temperature(bmsSlaveData->bmsSlaveTemperatures);

}

static void under_temperature_test(){ 
    set_voltage(bmsSlaveData->bmsSlaveVoltage);
    set_temperature(bmsSlaveData_LOW->bmsSlaveTemperatures);

}

static void over_temperature_test(){
    set_voltage(bmsSlaveData->bmsSlaveVoltage);
    set_temperature(bmsSlaveData_HIGH->bmsSlaveTemperatures);

}

static void communication_loss_test(){
    set_voltage(0);
    set_temperature(0);

    return;
}

// internal BMS Slave functions
static void set_temperature(float temparray[]){ 
    uint8_t pinSelect = 0;
    for( ; pinSelect <= 00001111; pinSelect++){
        temperature_mux(pinSelect);
        MCP48FV_Set_Value_Single(temparray[pinSelect], DAC_SIZE_BMS, 1, TRANSFER_GROUP);
    }
}

static void set_voltage(float voltage){ 
    MCP48FV_Set_Value_Single(voltage, DAC_SIZE_BMS, 0, TRANSFER_GROUP);
}

static void temperature_mux(uint8_t pinSelect){
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
