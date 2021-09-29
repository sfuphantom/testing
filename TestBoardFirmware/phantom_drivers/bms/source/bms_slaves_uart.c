/* 
*
*       bms_slaves_uart.c
*
*
*       Written by: Courtenay Huffman
*       Created: September 23rd 2021
*
*/

#include "bms_slaves_uart.h"

typedef unsigned char BYTE;

static void slaves_uart_init();
static void normal_slaves_uart();
static void slaves_uart_undervoltage();
static void slaves_uart_overvoltage();
static void slaves_uart_undertemperature();
static void slaves_uart_overtemperature();
static void slaves_uart_no_comms();
static void slaves_uart_comms_error();
static BYTE cmd_creator();

//configure these in halcogen, some defined in hwConfig.h already
#define BMS_UART 0 //define which register to communicate with BMS
#define BMS_FAULT_PORT gioPORTA 
#define BMS_FAULT_PIN         7 
#define BMS_TOTAL_TEMP_READINGS 10
#define UART_TX_PORT hetPORT1
#define UART_TX_PIN 13
#define UART_RX_PORT hetPORT1
#define UART_RX_PIN 6
#define BMS_VIO 0 //define pin for VIO - is this necessary?
#define BMS_SLAVE_WAKE 0 //define pin for bms slaves wake
#define BMSByteArraySize 43


typedef struct {
    uint8_t voltage;
    uint8_t temperature[BMS_TOTAL_TEMP_READINGS];
} BMSSlaveUART_t;

static BMSSlaveUART_t *BMSSlave_normal;
static BMSSlaveUART_t *BMSSlave_high;
static BMSSlaveUART_t *BMSSlave_low;

static void slaves_uart_init(){
    // initialize data structures that will be used to set values 
    BMSSlave_normal->voltage = 72;
    for (int i=0; i<BMS_TOTAL_TEMP_READINGS; i++){
        BMSSlave_normal->temperature[i] = 25;
    }

    BMSSlave_high->voltage = 120;
    for (int i=0; i<BMS_TOTAL_TEMP_READINGS; i++){
        BMSSlave_high->temperature[i] = 61;
    }

    BMSSlave_low->voltage = 34;
    for (int i=0; i<BMS_TOTAL_TEMP_READINGS; i++){
        BMSSlave_low->temperature[i] = 0;
    }

}

Result_t bms_slaves_uart_process(uint8_t state){

    switch (state)
    {
    case NORMAL_BMS_SLAVES_UART:
        normal_slaves_uart();
        break;
    case BMS_SLAVES_UART_UNDERVOLTAGE:
        slaves_uart_undervoltage();
        break;
    case BMS_SLAVES_UART_OVERVOLTAGE:
        slaves_uart_overvoltage();
        break;
    case BMS_SLAVES_UART_OVERTEMP:
        slaves_uart_overtemperature();
        break;
    case BMS_SLAVES_UART_UNDERTEMP:
        slaves_uart_undertemperature();
        break;
    case BMS_SLAVES_UART_NO_COMMS:
        slaves_uart_no_comms();
        break;
    case BMS_SLAVES_UART_COMMS_ERROR:
        slaves_uart_comms_error();
        break;
}

    return SUCCESS;
}

static void normal_slaves_uart(){
    // response message with all values in normal operating range
}

static void slaves_uart_undervoltage(){
    // response message with a low voltage value(s), other data normal range
}

static void slaves_uart_overvoltage(){
    // response message with high voltage value(s), other data normal range
}

static void slaves_uart_undertemperature(){
    // response message with low temperature value(s), other data normal range
}

static void slaves_uart_overtemperature(){
    // response message with high temperature value(s), other data normal range
}

static void slaves_uart_no_comms(){
    // no response message - do nothing
    return;
}

static void slaves_uart_comms_error(){
    // response message with error in communication protocol - bad CRC, invalid message length, etc
}

static BYTE cmd_creator(){
    BYTE cmdarray[BMSByteArraySize]; // 43 is size for a single slave reading
    //  creates string of bits to be sent to the BMS
    //  length in bytes: 43*1, where data is stored: MultipleSlaveReading data: 1 header, 32x2 cells, 2x16 AUX, 4 dig die, 4 ana die, 2 CRC
    return cmdarray;
}
