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
// #include "FreeRTOS.h"
// #include "os_timer.h"

// BMS Slave specific definitions, not accessed outside bms_slaves.c
#define VOLTAGE_STEP  0.04
#define DEFAULT_VOLTAGE 84
#define DEFAULT_TEMPERATURE 25
#define NUMBER_OF_TEMPERATURE_READINGS 16


enum
{
    NORMAL_BMS_OPERATION,
    MINOR_VOLTAGE_FAULT,
    MINOR_TEMPERATURE_FAULT,
    MAJOR_VOLTAGE_FAULT,
    MAJOR_TEMPERATURE_FAULT,
    WEIRD_SENSOR_READINGS_VOLTAGE,
    WEIRD_SENSOR_READINGS_TEMPERATURE,
    COMMUNICATION_LOSS_VOLTAGE,
    COMMUNICATION_LOSS_TEMPERATURE,
};

typedef struct {
    float bmsSlaveVoltage;
    float bmsSlaveTemperatures[NUMBER_OF_TEMPERATURE_READINGS];
} BMSSlave_t;

// Static Global Variables
static BMSSlave_t *bmsStruct;

// Static function definitions
static void normal_bms_operation();
static void minor_voltage_test();
static void minor_temperature_test();
static void major_voltage_test();
static void major_temperature_test();
static void weird_sensor_readings_voltage_test();
static void weird_sensor_readings_temperature_test();
static void communication_loss_voltage_test();
static void communication_loss_temperature_test();

Result_t bms_slaves_process(uint8_t state, TimerHandle_t *timerptr)
{

    bms_slaves_init();


    switch(state)
    {
        case NORMAL_BMS_OPERATION:
            normal_bms_operation();
            break;
        //case MINOR_FAULT:
        case MINOR_VOLTAGE_FAULT:
            minor_voltage_test();
            break;
       case MINOR_TEMPERATURE_FAULT:
            minor_temperature_test();
            break;
      //  case MAJOR_FAULT:
        case MAJOR_VOLTAGE_FAULT:
            major_voltage_test();
            break;
        case MAJOR_TEMPERATURE_FAULT:
            major_temperature_test();
            break;
        case WEIRD_SENSOR_READINGS_VOLTAGE:
            weird_sensor_readings_voltage_test();
            break;
        case WEIRD_SENSOR_READINGS_TEMPERATURE:
            weird_sensor_readings_temperature_test();
            break;
        case COMMUNICATION_LOSS_VOLTAGE:
            communication_loss_voltage_test();
            break;
        case COMMUNICATION_LOSS_TEMPERATURE:
            communication_loss_temperature_test();
            break;

    }

    return SUCCESS;
}

void bms_slaves_init()
{
    bmsStruct->bmsSlaveVoltage =  DEFAULT_VOLTAGE;
    uint8_t i;
    for(i = 0; i < NUMBER_OF_TEMPERATURE_READINGS; i++) {
        bmsStruct->bmsSlaveTemperatures[i] = DEFAULT_TEMPERATURE;
    }
}
#define VOLT_MAX = 420
#define VOLT_MIN = 320
#define DAC_SIZE = 1024
#define TRANSFER_GROUP = 2
// #define TEMP_MAX = 55 DEGREES C
// #define TEMP_MIN = 0 DEGREES C


// Send a constant 3.8V
static void normal_bms_operation()
{
    //set_bms_voltage
    UARTprintf("Normal BMS Operation\n\r");
    // voltage and temp at normal level
    MCP48FV_Set_Value_Double((VOLT_MAX + VOLT_MIN)*0.5, 0, DAC_SIZE, TRANSFER_GROUP); // 0 = TEMP FOR NOW 

}

static void minor_voltage_test()
{
//send a voltage over the opperating region (3.2-4.2)
//send 4.7V for less than 3 seconds
MCP48FV_Set_Value_Single(VOLT_MAX + 50, DAC_SIZE, 0, TRANSFER_GROUP);

//send a voltage under the opperating region (3.2-4.2)
//send 2.7V for less than 3 seconds
MCP48FV_Set_Value_Single(VOLT_MIN - 50, DAC_SIZE, 0, TRANSFER_GROUP);
}

static void minor_temperature_test()
{
//send a temperature voltage over the opperating region (55 degrees C)
//send 60 C for less than 3 seconds
}

static void major_voltage_test()
{
//send a voltage over the opperating region (3.2-4.2)
//send 4.7V for more than 3 seconds
MCP48FV_Set_Value_Single(VOLT_MAX + 50, DAC_SIZE, 0, TRANSFER_GROUP);

//send a voltage under the opperating region (3.2-4.2)
//send 2.7V for more than 3 seconds
MCP48FV_Set_Value_Single(VOLT_MIN - 50, DAC_SIZE, 0, TRANSFER_GROUP);
}

static void major_temperature_test()
{
//send a temperature voltage over the opperating region (55 degrees C)
//send 60 C for more than 3 seconds
}

static void communication_loss_voltage_test()
{ 
// send nothing 
// "what is timing out of messages"

MCP48FV_Set_Value_Single(0, DAC_SIZE, 0, TRANSFER_GROUP);
}
// static void communication_loss_temperature_test()

