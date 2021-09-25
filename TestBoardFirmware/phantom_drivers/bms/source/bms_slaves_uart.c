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

static void normal_slaves_uart();
static void slaves_uart_undervoltage();
static void slaves_uart_overvoltage();
static void slaves_uart_undertemperature();
static void slaves_uart_overtemperature();
static void slaves_uart_no_comms();
static void slaves_uart_comms_error();

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

}

static void slaves_uart_undervoltage(){

}

static void slaves_uart_overvoltage(){

}

static void slaves_uart_undertemperature(){

}

static void slaves_uart_overtemperature(){

}

static void slaves_uart_no_comms(){

}

static void slaves_uart_comms_error(){
    
}
