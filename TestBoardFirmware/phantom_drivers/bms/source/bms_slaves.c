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

// #include "FreeRTOS.h"
// #include "os_timer.h"

// BMS Slave specific definitions, not accessed outside bms_slaves.c
#define VOLTAGE_STEP  0.04
#define DEFAULT_VOLTAGE 84
#define DEFAULT_TEMPERATURE 25
#define NUMBER_OF_TEMPERATURE_READINGS 16
#define DAC_SIZE = 1024
#define TRANSFER_GROUP = 2
#define TEMP_MAX = 54 // TEMP MAX = 55 DEGREES
#define TEMP_MAX_VOLT = 113.1 // 1.131 
#define TEMP_MIN = 1 // TEMP MIN = 0 DEGREES
#define TEMP_MIN_VOLT = 268.2 // 2.682
#define TEMP_MIDDLE = 26
#define TEMP_MIDDLE_VOLT = 196.9 // 1.969
#define TEMP_HIGH = 76
#define TEMP_HIGH_VOLT = 66.83 // 0.6683
#define TEMP_LOW = 0
#define TEMP_LOW_VOLT = 270 // 2.70
#define VOLT_MIN = 76.08 // 0.7608 * 100
#define VOLT_MAX = 99.85 // 0.9985 * 100

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
} BMSSlave_t; // BMSSlave_t is like double or int

// Static Global Variables
static BMSSlave_t *bmsStruct;
static BMSSlave_t *bmsTempFault;

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
static void temperature_mux(uint8_t pinSelect);

Result_t bms_slaves_process(uint8_t state)
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
    bmsTempFault->bmsSlaveTemperatures = DEFAULT_TEMPERATURE;
    uint8_t j;
    for(i = j; j < NUMBER_OF_TEMPERATURE_READINGS; j++) {
        bmsTempFault->bmsSlaveTemperatures[j] = DEFAULT_TEMPERATURE;
    }
    bmsTempFault->bmsSlaveTemperatures[0] = DEFAULT_TEMPERATURE*3;
}

// Send a constant 3.8V
static void normal_bms_operation()
{
    // set_bms_voltage
    UARTprintf("Normal BMS Operation\n\r");
    // voltage and temp at normal level

    MCP48FV_Set_Value_Single((VOLT_MAX + VOLT_MIN)*0.5, DAC_SIZE, 0, TRANSFER_GROUP);

    //setting temp on each of the 16 pins
    for(uint8_t pinSelect = 0b00000000; pinSelect <= 00001111; pinSelect++)// for loop - iterate over each pin
    {
        temperature_mux(pinSelect) 
        // set the DAC
        MCP48FV_Set_Value_Single(250, DAC_SIZE, 1, TRANSFER_GROUP); //voltage = 2.5V (unsure) * 100
    }
}

static void minor_voltage_test()
{
    //send a voltage over the opperating region (3.2-4.2)
    //send 4.7V for less than 3 seconds
    MCP48FV_Set_Value_Single(VOLT_MAX, DAC_SIZE, 0, TRANSFER_GROUP);

    //send a voltage under the opperating region (3.2-4.2)
    //send 2.7V for less than 3 seconds
    MCP48FV_Set_Value_Single(VOLT_MIN, DAC_SIZE, 0, TRANSFER_GROUP);

    for(uint8_t pinSelect = 0b00000000; pinSelect <= 00001111; pinSelect++){// for loop - iterate over each pin
        temperature_mux(pinSelect) 
        // set the DAC
        MCP48FV_Set_Value_Single( bmsStruct->bmsSlaveTemperatures[pinSelect], DAC_SIZE, 1, TRANSFER_GROUP);
    }
}

static void minor_temperature_test()
{
    //send a temperature voltage over the opperating region (55 degrees C)
    //send 60 C for less than 3 seconds

    MCP48FV_Set_Value_Single((VOLT_MAX + VOLT_MIN)*0.5, DAC_SIZE, 0, TRANSFER_GROUP);

    for(uint8_t pinSelect = 0b00000000; pinSelect <= 00001111; pinSelect++){// for loop - iterate over each pin
        temperature_mux(pinSelect) 
        // set the DAC
        MCP48FV_Set_Value_Single(bmsTempFault->bmsSlaveTemperatures[pinSelect], DAC_SIZE, 1, TRANSFER_GROUP);
    }
}

static void major_voltage_test()
{
    //send a voltage over the opperating region (3.2-4.2)
    //send 4.7V for more than 3 seconds
    MCP48FV_Set_Value_Single(VOLT_MAX, DAC_SIZE, 0, TRANSFER_GROUP);

    //send a voltage under the opperating region (3.2-4.2)
    //send 2.7V for more than 3 seconds
    MCP48FV_Set_Value_Single(VOLT_MIN, DAC_SIZE, 0, TRANSFER_GROUP);

    for(uint8_t pinSelect = 0b00000000; pinSelect <= 00001111; pinSelect++){// for loop - iterate over each pin
        temperature_mux(pinSelect)  
        // set the DAC
        MCP48FV_Set_Value_Single(bmsStruct->bmsSlaveTemperatures[pinSelect], DAC_SIZE, 1, TRANSFER_GROUP);
    } 
}

static void major_temperature_test()
{
    //send a temperature voltage over the opperating region (55 degrees C)
    //send 60 C for more than 3 seconds

    MCP48FV_Set_Value_Single((VOLT_MAX + VOLT_MIN)*0.5, DAC_SIZE, 0, TRANSFER_GROUP);

    for(uint8_t pinSelect = 0b00000000; pinSelect <= 00001111; pinSelect++){// for loop - iterate over each pin
        temperature_mux(pinSelect)  
        // set the DAC
        MCP48FV_Set_Value_Single(bmsTempFault->bmsSlaveTemperatures[pinSelect], DAC_SIZE, 1, TRANSFER_GROUP); 
    }
}

/*static void communication_loss_voltage_test()
{ 
    // send nothing 
    // "what is timing out of messages"

    MCP48FV_Set_Value_Single(0, DAC_SIZE, 0, TRANSFER_GROUP);

    for(uint8_t pinSelect = 0b00000000; pinSelect <= 00001111; pinSelect++){// for loop - iterate over each pin
        temperature_mux(pinSelect) 
        // set the DAC
        MCP48FV_Set_Value_Single(bmsStruct->bmsSlaveTemperatures[pinSelect], DAC_SIZE, 1, TRANSFER_GROUP);
    }
}*/

// static void communication_loss_temperature_test()


// *****temperature mux function (loop)*****
static void temperature_mux(uint8_t pinSelect)
{ 
     // set the different mux pins
    if (0b00000001 & pinSelect){ 
        gioToggleBit(TEMP_MUX_PORT, TEMP_MUX_PIN_0);
    }
    if ((0b000010 & pinSelect) >> 1){ 
         gioToggleBit(TEMP_MUX_PORT, TEMP_MUX_PIN_1);
    } 
    if ((0b000100 & pinSelect) >> 2){ 
        gioToggleBit(TEMP_MUX_PORT, TEMP_MUX_PIN_2);
    } 
    if ((0b001000 & pinSelect) >> 3){ 
        gioToggleBit(TEMP_MUX_PORT, TEMP_MUX_PIN_3);
    } 

 return 0;
}
