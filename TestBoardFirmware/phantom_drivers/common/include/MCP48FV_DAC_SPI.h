/*
 * MCP48FV_DAC_SPI.h
 *
 *  Adapted for the testboard March 19, 2021
 *  Modifications by Courtenay Huffman
 *
 *  Original from vcu-fw by:
 *  Created on: Oct 12, 2019
 *      Author: PTL
 */

#ifndef INCLUDE_DAC_SPI_MCP48FV_DAC_SPI_H_
#define INCLUDE_DAC_SPI_MCP48FV_DAC_SPI_H_

#include <halcogen_vcu/include/mibspi.h> // CHANGE PATH FOR TEST BOARD
#include "stdbool.h"

// INCLUDE OVERLOADED FUNCTION HEADERS, AND ANY EXTRA FUNCTIONS, THERES 2 WRITE DECLARATIONS
// FIX PARAMETERS FOR DIFFERENT SIZES OF DAC
bool MCP48FV_Init();

bool MCP48FV_Set_Value(uint16_t targetVoltage, uint16_t DAC_SIZE);
bool MCP48FV_Write(uint32_t cmdString);
uint32_t cmdCreator(uint8_t address, uint8_t cmdReadWrite, uint8_t cmderr, uint16_t dataBit);
bool MCP48FV_Write(uint32_t cmdString);
uint16_t readRegister (uint8_t registerAddress);
uint16_t MCP48FV_Read();
#endif /* INCLUDE_DAC_SPI_MCP48FV_DAC_SPI_H_ */