/*
 * lv_sensor.c
 *
 *  Created on: April 1, 2021
 *      Author: Vlad Bors
 */
​
#include "lv_sensor.h"
#include "hwConfig.h"
#include "i2c.h"
#include "sys_common.h"
#include <iostream>

//configure in halcogen
#define LV_MONITOR_I2C_PORT

//Register
//#define LV_configuration_register 0x00
//#define LV_Shunt_register 0x01
#define LV_bus_voltage_register 0x02
//#define LV_calibration_register 0x05
#define LV_current_register 0x04
//#define LV_power_register 0x03

enum operation
{
    LV_POW_STD_OP, // standard operation, send 12v to power
    LV_POW_UV, // power undervoltage, send 9v to power
    LV_POW_OV, // power overvoltage, send 15v to power
    LV_POW_POWERDRAW, // power draw, send any signal to chip's shunt resistor
    LV_POW_OVERCURRENT, // overcurrent protection, short a sustained signal to shunt
};

// static function definitions
static void lv_pow_std_op();
static void lv_pow_uv();
static void lv_pow_ov();
static void lv_pow_powerdraw();
static void lv_pow_overcurrent();
​
void lv_sensor_process(uint8_t state){
    switch (state)
    {
        case LV_POW_UV:
            lv_pow_uv();
            break;
        case LV_POW_OV:
            lv_pow_ov();
            break;
        case LV_POW_POWERDRAW:
            lv_pow_powerdraw();
            break;
        case LV_POW_OVERCURRENT:
            lv_pow_overcurrent();
            break;
        default:
            lv_pow_std_op();
            break;
    }
}



/*
static int twosComplement(int negative_output){
    negative_output=negative_output*(-1);
    int carry = 1;
    int binary[]={1,0,0,0,0,0,0,0,0,0,0,0};
    int twoscomplement=0;
    int i;

    // converting to a binary value in ones complement form
    for (i=11;negative_output>0;i--){
        binary[i]=negative_output%2;
        negative_output=negative_output/2;
    }

    // converting to ones'complement
    for (i=1;i<=11;i++){
        if (binary[i]==0){
            binary[i]=1;
        }
        else if(binary[i]==1){
            binary[i]=0;
        }
    }

    // converting to twos'complement
    for (i=11;i>0;i--){
        if(binary[i] == 1 && carry == 1){
            binary[i] = 0;
        }
        else if(binary[i] == 0 && carry == 1){
            binary[i] = 1;
            carry = 0;
        }
        else{
            binary[i] = binary[i];
        }
    }

    // converting back to an unsigned decimal
    for (i=11;i>=0;i--){
        int exp =0;
        twoscomplement = twoscomplement+binary[i]*pow(2,exp);
        exp +=1;
    }
    return twoscomplement;
}

// decimal number to binary number
 
#include <iostream>
using namespace std;
 
// function to convert decimal to binary
void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
 
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}
 
// Driver program to test above function
int main()
{
    int n = 17;
    decToBinary(n);
    return 0;
}
*/


//uint8 LV_Calibration[2] = {0x14,0x00}; //this is a calculated value 5120->0x1400



int main() {

//decimal to binary
void dec2bin(double c)
{
   int i = 0;
   for(i = 31; i >= 0; i--){
     if((c & (1 << i)) != 0){
       printf("1");
     }else{
       printf("0");
     } 
   }
}


//voltage calculation and decimal --> binary
double getVoltage(double battery_voltage)
{
   double output_voltage;
    getVoltage = (battery_voltage+0.25); // battery_voltage is operating voltage (around 13.2v)
    output_voltage = dec2bin(getVoltage)

}

//current calculation and decimal --> binary
double getCurrent = ((5120*0.25)/2048);
output_current = dec2bin(getCurrent);





/*
//i2c functions
void i2cInit (void) //Initializes the i2c Driver.
void i2cSetOwnAdd (i2cBASE_t *i2c, uint32 oadd) //Set I2C Own Address.
void i2cSetSlaveAdd (i2cBASE_t *i2c, uint32 sadd) //Set Port Direction.
void i2cSetBaudrate (i2cBASE_t *i2c, uint32 baud) //Change baudrate at runtime.
uint32 i2cIsTxReady (i2cBASE_t *i2c) //Check if Tx buffer empty.
void i2cSendByte (i2cBASE_t *i2c, uint8 byte) //Send Byte.
void i2cSend (i2cBASE_t *i2c, uint32 length, uint8 *data) //Send Data.
uint32 i2cIsRxReady (i2cBASE_t *i2c) //Check if Rx buffer full.
uint32 i2cIsStopDetected (i2cBASE_t *i2c) //Check if Stop Condition Detected.
void i2cClearSCD (i2cBASE_t *i2c) //Clears the Stop condition detect flags.
uint32 i2cRxError (i2cBASE_t *i2c) //Return Rx Error flags.
uint8 i2cReceiveByte (i2cBASE_t *i2c) //Receive Byte.
void i2cReceive (i2cBASE_t *i2c, uint32 length, uint8 *data) //Receive Data.
void i2cEnableNotification (i2cBASE_t *i2c, uint32 flags) //Enable interrupts.
void i2cDisableNotification (i2cBASE_t *i2c, uint32 flags) //Disable interrupts.
void i2cSetStart (i2cBASE_t *i2c) //Set i2c start condition.
void i2cSetStop (i2cBASE_t *i2c) //Set i2c stop condition.
void i2cSetCount (i2cBASE_t *i2c, uint32 cnt) //Set i2c data count.
void i2cEnableLoopback (i2cBASE_t *i2c) //Enable Loopback mode for self test.
void i2cDisableLoopback (i2cBASE_t *i2c) //Enable Loopback mode for self test.
void i2cSetMode (i2cBASE_t *i2c, uint32 mode) //Sets Master or Slave mode.
void i2cGetConfigValue (i2c_config_reg_t *config_reg, config_value_type_t type) //Get the initial or current values of the I2C configuration registers.
void i2cSetDirection (i2cBASE_t *i2c, uint32 dir) //Sets I2C as transmitter or receiver.
bool i2cIsMasterReady (i2cBASE_t *i2c) //Indicates whether MST bit is set or cleared to indicate that stop condition was generated. This API should be called after Master Tx or Rx to check if the transaction is complete.
bool i2cIsBusBusy (i2cBASE_t *i2c) //Returns the state of the bus busy flag. True if it is set and false otherwise.
void i2cNotification (i2cBASE_t *i2c, uint32 flags) //Interrupt callback.
*/

/*
//example
i2cSetMode(i2cREG1, I2C_MASTER);

    /* Set direction to receiver 
    i2cSetDirection(i2cREG1, I2C_TRANSMITTER);

    i2cSetStart(i2cREG1); //start bit

    i2cSetSlaveAdd(i2cREG1, 0b1001000); //address of temp sensor
    while(i2cIsTxReady(i2cREG1)){}; //wait until flag is clear
    i2cSendByte(i2cREG1, 0b00000000); //register to read from 

    i2cSetStart(i2cREG1); 
    i2cSendByte(i2cREG1, 0b10010001); //read from sensor

    i2cSetDirection(i2cREG1, I2C_RECEIVER);
    while(i2cIsRxReady(i2cREG1)){};
    data = i2cReceiveByte(i2cREG1); //read data

    i2cSetStop(i2cREG1); //stop bit

*/



void lv_pow_std_op() {
    double v=13.2; //send 13.2v to power
    double output_voltage;
    output_voltage = getVoltage(v);

    i2cInit(); //initializes i2c driver
    i2cSetMode(i2cREG1, I2C_MASTER); //variables?
    i2cSetSlaveAdd(i2cREG1, 0b1001000); //address of voltage bus
    i2cSetBaudrate(LV_MONITOR_I2C_PORT, 100); // change baudrate at runtime
    i2cSetDirection(i2cREG1, I2C_TRANSMITTER);
    i2cSetStart(LV_MONITOR_I2C_PORT); // initializes transmission 
     
     while(i2cIsTxReady(i2cREG1)){}; //Check if Tx buffer empty.
    i2cSendByte(i2cREG1, output_voltage); //send bytes

     i2cSetDirection(i2cREG1, I2C_RECEIVER);
    while(i2cIsRxReady(i2cREG1)){};
    data = i2cReceiveByte(i2cREG1); //read data

    i2cSetStop(LV_MONITOR_I2C_PORT);
    printf("NORMAL_OPERATION");
    return;
}


void v_pow_uv() {
    double ​v=9; //send 9v to power
    double output_voltage;
    output_voltage = getVoltage(v);

    i2cInit(); //initializes i2c driver
    i2cSetMode(i2cREG1, I2C_MASTER); //variables?
    i2cSetSlaveAdd(i2cREG1, 0b1001000); //address of voltage bus
    i2cSetBaudrate(LV_MONITOR_I2C_PORT, 100); // change baudrate at runtime
    i2cSetDirection(i2cREG1, I2C_TRANSMITTER);
    i2cSetStart(LV_MONITOR_I2C_PORT); // initializes transmission 
     
     while(i2cIsTxReady(i2cREG1)){}; //Check if Tx buffer empty.
    i2cSendByte(i2cREG1, output_voltage); //send bytes

     i2cSetDirection(i2cREG1, I2C_RECEIVER);
    while(i2cIsRxReady(i2cREG1)){};
    data = i2cReceiveByte(i2cREG1); //read data

    i2cSetStop(LV_MONITOR_I2C_PORT);
    printf("LV_VOLTAGE_OUT_OF_RANGE");
    return;

 /*   i2cInit(); //initializes i2c driver
    i2cSetBaudrate(LV_MONITOR_I2C_PORT, 100); // change baudrate at runtime
    i2cIsTxReady(LV_MONITOR_I2C_PORT); // Check if Tx buffer empty.
    i2cSetStart(LV_MONITOR_I2C_PORT); // initializes transmission 
    i2cSendByte(LV_MONITOR_I2C_PORT,output_voltage); //send byte
    i2cSetStop(LV_MONITOR_I2C_PORT);
    printf("LV_VOLTAGE_OUT_OF_RANGE");
    
    return;
    */

}

void lv_pow_ov() {​
    double ​v=15; //send 15v to power
    double output_voltage;
    output_voltage = getVoltage(v);

     i2cInit(); //initializes i2c driver
    i2cSetMode(i2cREG1, I2C_MASTER); //variables?
    i2cSetSlaveAdd(i2cREG1, 0b1001000); //address of voltage bus
    i2cSetBaudrate(LV_MONITOR_I2C_PORT, 100); // change baudrate at runtime
    i2cSetDirection(i2cREG1, I2C_TRANSMITTER);
    i2cSetStart(LV_MONITOR_I2C_PORT); // initializes transmission 
     
     while(i2cIsTxReady(i2cREG1)){}; //Check if Tx buffer empty.
    i2cSendByte(i2cREG1, output_voltage); //send bytes

     i2cSetDirection(i2cREG1, I2C_RECEIVER);
    while(i2cIsRxReady(i2cREG1)){};
    data = i2cReceiveByte(i2cREG1); //read data

    i2cSetStop(LV_MONITOR_I2C_PORT);
    printf("LV_VOLTAGE_OUT_OF_RANGE");
    return;
}

void lv_pow_powerdraw() {
    ​//send any signal to chip's shunt resistor, might need a timer for this
        ​
}

void lv_pow_overcurrent() {
    // overcurrent protection, short a sustained signal to shunt
    double getCurrent = ((5120*0.25)/2048);
    output_current = dec2bin(getCurrent);
    
    i2cInit(); //initializes i2c driver
    i2cSetMode(i2cREG1, I2C_MASTER); //variables?
    i2cSetSlaveAdd(i2cREG1, 0x04); //address of voltage bus
    i2cSetBaudrate(LV_MONITOR_I2C_PORT, 100); // change baudrate at runtime
    i2cSetDirection(i2cREG1, I2C_TRANSMITTER);
    i2cSetStart(LV_MONITOR_I2C_PORT); // initializes transmission 
     
     while(i2cIsTxReady(i2cREG1)){}; //Check if Tx buffer empty.
    i2cSendByte(i2cREG1, output_current); //send bytes

     i2cSetDirection(i2cREG1, I2C_RECEIVER);
    while(i2cIsRxReady(i2cREG1)){};
    data = i2cReceiveByte(i2cREG1); //read data

    i2cSetStop(LV_MONITOR_I2C_PORT);
    printf("LV_CURRENT_OUT_OF_RANGE");
    return;​
}
}