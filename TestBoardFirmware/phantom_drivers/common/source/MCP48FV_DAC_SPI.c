#include "MCP48FV_DAC_SPI.h"
#include "hwConfig.h"

#define DAC_LOWEST_VOLTAGE 0
#define DAC_HIGHEST_VOLTAGE 5

#define DAC0_REGISTER_ADDRESS 01
#define DAC1_REGISTER_ADDRESS 00
#define VREF_REGISTER_ADDRESS 08
#define POWER_DOWN_REGISTER 09
#define GAIN_STATUS_REGISTER 0x0A

#define DAC_READ_CMD 03 // equivalent to 0b11
#define DAC_WRITE_CMD 00

#define CMDERR 0

// Function responsible for initializing MiBspi
bool MCP48FV_Init(){
    mibspiInit();
    MCP48FV_Set_Value_Double(0, 0, 0xFF, 0);
    MCP48FV_Set_Value_Double(0, 0, 0xFF, 1);
    MCP48FV_Set_Value_Double(0, 0, 0x3ff, 2);
    return true;
}

/*  Main DAC controllers, configure to set output voltage(s) from 0-5VDC
 *  Example Use: targetVoltage = 500 for 5.00V, 251 = 2.51V
*/
bool MCP48FV_Set_Value_Double(uint16_t targetVoltage1, uint16_t targetVoltage2, uint16_t dac_size, uint32_t transfer_group){

    targetVoltage1 = (targetVoltage1>496) ? 496 : targetVoltage1;
    targetVoltage2 = (targetVoltage2>496) ? 496 : targetVoltage2;

    uint32_t enableBitPercent1= ((targetVoltage1)*1000)/(DAC_HIGHEST_VOLTAGE*100);
    uint32_t dacData1= (enableBitPercent1*dac_size)/1000;
    MCP48FV_Write(cmdCreator(DAC0_REGISTER_ADDRESS, DAC_WRITE_CMD, CMDERR, dacData1), transfer_group);

    uint32_t enableBitPercent2= ((targetVoltage2)*1000)/(DAC_HIGHEST_VOLTAGE*100);
    uint32_t dacData2= (enableBitPercent2*dac_size)/1000;
    MCP48FV_Write(cmdCreator(DAC1_REGISTER_ADDRESS, DAC_WRITE_CMD, CMDERR, dacData2), transfer_group);

    return true;
}

bool MCP48FV_Set_Value_Single(uint16_t targetVoltage, uint16_t dac_size, uint8_t dacVout, uint32_t transfer_group){

    targetVoltage = (targetVoltage>496) ? 496 : targetVoltage;

    uint32_t enableBitPercent= ((targetVoltage)*1000)/(DAC_HIGHEST_VOLTAGE*100);
    uint32_t dacData= (enableBitPercent*dac_size)/1000;

    MCP48FV_Write(cmdCreator(dacVout, DAC_WRITE_CMD, CMDERR, dacData), transfer_group);

    return true;
}

// creates the commands for the register inputs
uint32_t cmdCreator(uint8_t address, uint8_t cmdReadWrite, uint8_t cmderr, uint16_t dataBit){
    return ((address<<19) + (cmdReadWrite<<17) + (cmderr<<16) + (0<<12)+ dataBit);
}

// responsible for transmitting SPI command
bool MCP48FV_Write(uint32_t cmdString, uint32_t transfer_group){

    //uint8_t cmdSPI1= cmdString; // debug
    //uint8_t cmdSPI2= (cmdString>>8);
    //uint8_t cmdSPI3= (cmdString>>16);

    uint16_t txbuffer[]={(uint8_t) (cmdString>>16),(uint8_t) (cmdString>>8),(uint8_t) (cmdString>>0)};
    mibspiSetData(DAC_SPI_PORT, transfer_group,txbuffer);
    mibspiTransfer(DAC_SPI_PORT,transfer_group);
    while(!(mibspiIsTransferComplete(DAC_SPI_PORT,transfer_group))); // need a timeout
    // start a timer, don't use a while loop forever

    return true;
}

// return register data from specific register
uint16_t readRegister (uint8_t registerAddress, uint32_t transfer_group){

    MCP48FV_Write(cmdCreator(registerAddress,DAC_READ_CMD, CMDERR, 0), transfer_group);
    return  MCP48FV_Read(transfer_group) % (1<<12);
}

//receive data from MCP48FV
uint16_t MCP48FV_Read(uint32_t transfer_group){

    uint16_t rxBuffer[10]={0};
    mibspiGetData(DAC_SPI_PORT,transfer_group,rxBuffer);
    return (rxBuffer[2]<<8+rxBuffer[1]<<8+rxBuffer[0]);
}
