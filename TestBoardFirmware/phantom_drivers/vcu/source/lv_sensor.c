<<<<<<< HEAD
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

//configure in halcogen
#define LV_MONITOR_I2C_PORT   i2cREG1 
#define LVP_SDA //pin59
#define LVP_SCL //pin 58

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





​/*
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

















static int getVoltage(double battery_voltage)
{
   int output_voltage;
    output_voltage = (battery_voltage+0.25); // battery_voltage is operating voltage (around 13.2v)
    return output_voltage;
}

static int getCurrent(double current)
 {
     int output_current;
    output_current = ((5120*0.25)/2048);
    return output_current;
 }







void lv_pow_std_op() {
    ​//send 13.2v to power
     voltage_output = (uint16)getVoltage(13.2);
     // "Normal operation of low voltage system of 12V.\n\r"
     // (lv_output);   //??​
}

void v_pow_uv() {
    ​//send 9v to power
     voltage_output = (uint16)getVoltage(9);
     // "Low voltage system under voltage.\n\r"
     // (lv_output);   //??​​
}

void lv_pow_ov() {
    ​//send 15v to power
     voltage_output = (uint16)getVoltage(15);
     // "Low voltage system over voltage.\n\r"
     // (lv_output);   //??​
}

void lv_pow_powerdraw() {
    ​//send any signal to chip's shunt resistor, might need a timer for this
        ​
}

void lv_pow_overcurrent() {
    // overcurrent protection, short a sustained signal to shunt
     current_output = (uint16)getCurrent(13.2);​
}
=======
///*
// * lv_power_sensor_test.c
// *
// *  Created on: Jan 23, 2021
// *      Author: andrei
// */
//
//#include "lv_sensor.h"
//typedef enum operation
//{
//    NORMAL_LV_POWER_SENSOR_OPERATION
//}; operation
//
//void lv_pow_std_op();
//void lv_pow_uv();
//void lv_pow_ov();
//void lv_pow_powerdraw();
//void lv_pow_current_short();
//void lv_pow_current_sustained();
//void hv_cs_process(uint8_t state)
//{
//    switch(state)
//    {
//        case NORMAL_LV_POWER_SENSOR_OPERATION:
//            lv_pow_std_op();        break;
//            lv_pow_uv();            break;
//            lv_pow_ov();            break;
//            lv_pow_powerdraw();     break;
//            lv_pow_current_short(); break;
//            lv_pow_std_op();        break;
//            lv_pow_current_sust();  break;
//            default;    break;
//    }
//}
//
//void lv_pow_std_op(){
//    uint16_t mode;
//}
>>>>>>> master
