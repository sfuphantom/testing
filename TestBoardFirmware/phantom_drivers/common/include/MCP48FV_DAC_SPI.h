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

#include "mibspi.h"
#include "stdbool.h"

bool MCP48FV_Init();

bool MCP48FV_Set_Value_Single(uint16_t targetVoltage, uint16_t DAC_SIZE, uint8_t dacVout, uint32_t transfer_group);
bool MCP48FV_Write(uint32_t cmdString, uint32_t transfer_group);
bool MCP48FV_Set_Value_Double(uint16_t targetVoltage1, uint16_t targetVoltage2, uint16_t DAC_SIZE, uint32_t transfer_group);
uint32_t cmdCreator(uint8_t address, uint8_t cmdReadWrite, uint8_t cmderr, uint16_t dataBit);
uint16_t readRegister (uint8_t registerAddress, uint32_t transfer_group);
uint16_t MCP48FV_Read();
#endif /* INCLUDE_DAC_SPI_MCP48FV_DAC_SPI_H_ */
