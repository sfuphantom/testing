//DAC init
#include "MCP48FV_DAC_SPI.h"
/* SET UP FOR TEST BOARD FILE
#include "board_hardware.h"   // contains hardware defines for specific board used (i.e. VCU or launchpad)
*/
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

// init function, responsible for initializing MiBspi
bool MCP48FV_Init(){
    mibspiInit();
    MCP48FV_Set_Value(0);        //500 = 5.00V, 250 = 2.5V  Can set this value to any default
    return true;
}


// TO DO: CONFIGURE FOR DUAL VALUE ENTRY & DIFFERENT REGISTER SIZES
// FIX PARAMETES, OVERLOAD FUNCTION
/*Main DAC controller, configure to set the output voltage from 0-5VDC
 * use: targetVoltage= 500 = 5.00V, 251 = 2.51V
*/
bool MCP48FV_Set_Value(uint16_t targetVoltage, uint16_t DAC_SIZE){

   if(targetVoltage>496) // why this value? why not 500 (equivalent to 5V)?
   {
       targetVoltage = 496;
   }
    uint32_t enableBitPercent= ((targetVoltage)*1000)/(DAC_HIGHEST_VOLTAGE*100);
    uint32_t dacRegister= (enableBitPercent*DAC_SIZE)/1000; 

   MCP48FV_Write(cmdCreator(DAC0_REGISTER_ADDRESS, DAC_WRITE_CMD,0,dacRegister)); // CHANGE TO ACCESS BOTH OUTPUTS

    return true;
}

// TO DO: ADAPT FOR DIFFERENT REGISTER SIZES
//creates the commands from register inputs
uint32_t cmdCreator(uint8_t address, uint8_t cmdReadWrite, uint8_t cmderr, uint16_t dataBit){
    return ((address<<19) + (cmdReadWrite<<17) + (cmderr<<16) + (0<<12)+ dataBit);
}

// TO DO: ADAPT FOR ABILITY TO USE MULTIPLE DACS (DAC_SPI_PORT WILL BE DIFFERENT HERE)
//responsible for transmitting SPI command
bool MCP48FV_Write(uint32_t cmdString){

//    uint8_t cmdSPI1= cmdString; // debug
//    uint8_t cmdSPI2= (cmdString>>8);
//    uint8_t cmdSPI3= (cmdString>>16);

//
    uint16_t txbuffer[]={(uint8_t) (cmdString>>16),(uint8_t) (cmdString>>8),(uint8_t) (cmdString>>0)};
    mibspiSetData(DAC_SPI_PORT,0,txbuffer); // CHANGE SO THAT PORT CAN BE ADAPTED FOR MULTIPLE PORTS
    mibspiTransfer(DAC_SPI_PORT,0);
    while(!(mibspiIsTransferComplete(DAC_SPI_PORT,0))); // need a timeout
    // start a timer, don't use a while loop forever

    return true;

}

//return register data from specific register
uint16_t readRegister (uint8_t registerAddress){

    MCP48FV_Write(cmdCreator(registerAddress,DAC_READ_CMD,0,0));
    return  MCP48FV_Read() % (1<<12);
}

//receive data from MCP48FV
uint16_t MCP48FV_Read(){

    uint16_t rxBuffer[10]={0};
    mibspiGetData(DAC_SPI_PORT,0,rxBuffer);
    return (rxBuffer[2]<<8+rxBuffer[1]<<8+rxBuffer[0]);
}