//DAC init
#include "MCP48FV_DAC_SPI.h"

#include "hwConfig.h"   // contains hardware defines for specific board used (i.e. VCU or launchpad)

//#include "mibspi.h"

#define DAC_LOWEST_VOLTAGE 0
#define DAC_HIGHEST_VOLTAGE 5

#define DAC0_REGISTER_ADDRESS 00
#define DAC1_REGISTER_ADDRESS 01
#define VREF_REGISTER_ADDRESS 08
#define POWER_DOWN_REGISTER 09
#define GAIN_STATUS_REGISTER 0x0A

#define DAC_READ_CMD 03 //0b11
#define DAC_WRITE_CMD 00

// in some kind of definitions lib/file?
#define DAC_SIZE_8 0xFF
#define DAC_SIZE_10 0x3FF
#define DAC_SIZE_12 0xFFF

// transfer groups - add to hwConfig.h
#define TRANSFERGROUP_APPS 0
#define TRANSFERGROUP_BSE_HV 1
#define TRANSFERGROUP_BMS 2

// OLD: DAC_SPI_PORT NEW: NEED PORT DEFINITIONS FOR EACH DIFFERENT DAC, PASS INTO FUNCTIONS
#define APPS1_SPI_PORT "DAC 2 VOUT0"
#define APPS2_SPI_PORT "DAC 2 VOUT1"
#define BSE_SPI_PORT "DAC 1 VOUT1"
#define HV_CURR_SPI_PORT "DAC 1 VOUT0"
#define BMS_TEMP_SPI_PORT "DAC 3 VOUT1"
#define BMS_VOLT_SPI_PORT "DAC 3 VOUT0"

// init function, responsible for initializing MiBspi
bool MCP48FV_Init(){ 
    mibspiInit();
    MCP48FV_Set_Value(0);        //500 = 5.00V, 250 = 2.5V  Can set this value to any default. How to handle with new flexibility?
    return true;
}

/* Main DAC controller, configure to set both output voltages from 0-5VDC
 * use: targetVoltage= 500 = 5.00V, 251 = 2.51V
*/
bool MCP48FV_Set_Value(uint16_t targetVoltage1, uint16_t targetVoltage2, uint16_t DAC_SIZE, uint32_t transfer_group){ //pass in spi port somehow
    if(targetVoltage1>496) // why this value? why not 500 (equivalent to 5V)?
   {
       targetVoltage1 = 496;
   }
    if(targetVoltage2>496) // why this value? why not 500 (equivalent to 5V)?
   {
       targetVoltage2 = 496;
   }

    uint32_t enableBitPercent1= ((targetVoltage1)*1000)/(DAC_HIGHEST_VOLTAGE*100);
    uint32_t dacData1= (enableBitPercent1*DAC_SIZE)/1000; 
    MCP48FV_Write(cmdCreator(DAC0_REGISTER_ADDRESS, DAC_WRITE_CMD,0,dacData1)); 

    uint32_t enableBitPercent2= ((targetVoltage2)*1000)/(DAC_HIGHEST_VOLTAGE*100);
    uint32_t dacData2= (enableBitPercent2*DAC_SIZE)/1000; 
    MCP48FV_Write(cmdCreator(DAC1_REGISTER_ADDRESS, DAC_WRITE_CMD,0,dacData2)); 

    return true;
}

/* Main DAC controller, configure to set a single output voltage from 0-5VDC
 * use: targetVoltage= 500 = 5.00V, 251 = 2.51V
*/
bool MCP48FV_Set_Value(uint16_t targetVoltage, uint16_t DAC_SIZE, uint8_t dacVout, uint32_t transfer_group){

   if(targetVoltage>496) // why this value? why not 500 (equivalent to 5V)?
   {
       targetVoltage = 496;
   }
    uint32_t enableBitPercent= ((targetVoltage)*1000)/(DAC_HIGHEST_VOLTAGE*100);
    uint32_t dacData= (enableBitPercent*DAC_SIZE)/1000; 

   MCP48FV_Write(cmdCreator(dacVout, DAC_WRITE_CMD,0,dacData), transfer_group);

    return true;
}

//creates the commands from register inputs
uint32_t cmdCreator(uint8_t address, uint8_t cmdReadWrite, uint8_t cmderr, uint16_t dataBit){
    return ((address<<19) + (cmdReadWrite<<17) + (cmderr<<16) + (0<<12)+ dataBit);
}

// TO DO: ADAPT FOR ABILITY TO USE MULTIPLE DACS: (DAC_SPI_PORT WILL BE DIFFERENT HERE)
//responsible for transmitting SPI command
bool MCP48FV_Write(uint32_t cmdString, uint32_t transfer_group){ 

//    uint8_t cmdSPI1= cmdString; // debug
//    uint8_t cmdSPI2= (cmdString>>8);
//    uint8_t cmdSPI3= (cmdString>>16);

//
    uint16_t txbuffer[]={(uint8_t) (cmdString>>16),(uint8_t) (cmdString>>8),(uint8_t) (cmdString>>0)};
    mibspiSetData(DAC_SPI_PORT, transfer_group,txbuffer); // CHANGE SO THAT PORT CAN BE ADAPTED FOR MULTIPLE PORTS
    mibspiTransfer(DAC_SPI_PORT,transfer_group);
    while(!(mibspiIsTransferComplete(DAC_SPI_PORT,transfer_group))); // need a timeout
    // start a timer, don't use a while loop forever

    return true;

}

//return register data from specific register
uint16_t readRegister (uint8_t registerAddress, uint32_t transfer_group){

    MCP48FV_Write(cmdCreator(registerAddress,DAC_READ_CMD,0,0), uint32_t transfer_group);
    return  MCP48FV_Read(transfer_group) % (1<<12);
}

//receive data from MCP48FV
uint16_t MCP48FV_Read(uint32_t transfer_group){

    uint16_t rxBuffer[10]={0};
    mibspiGetData(DAC_SPI_PORT,transfer_group,rxBuffer); // NEED TO CHANGE DAC_SPI_PORT
    return (rxBuffer[2]<<8+rxBuffer[1]<<8+rxBuffer[0]);
}