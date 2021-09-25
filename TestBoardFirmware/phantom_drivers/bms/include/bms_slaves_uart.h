/* 
*
*       bms_slaves_uart.h
*
*
*       Written by: Courtenay Huffman
*       Created: September 23rd 2021
*
*/

#ifndef PHANTOM_DRIVERS_INCLUDE_BMS_SLAVES_UART_H_
#define PHANTOM_DRIVERS_INCLUDE_BMS_SLAVES_H_

#include "stdint.h"
#include "common.h"

Result_t bms_slaves_uart_process(uint8_t state);

enum{
    NORMAL_BMS_SLAVES_UART,
    BMS_SLAVES_UART_UNDERVOLTAGE,
    BMS_SLAVES_UART_OVERVOLTAGE,
    BMS_SLAVES_UART_OVERTEMP,
    BMS_SLAVES_UART_UNDERTEMP,
    BMS_SLAVES_UART_NO_COMMS,
    BMS_SLAVES_UART_COMMS_ERROR,
};

#endif 