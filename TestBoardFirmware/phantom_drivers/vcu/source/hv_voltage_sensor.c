/*
 * hv_voltage_sensor.c
 *
 *  Created on: Mar 16, 2021
 *      Author: Ryan Heo
 */

#include "sys_common.h"
#include "hv_voltage_sensor.h"
#include "mibspi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TransferGroup0 0
#define TransferGroup1 1
#define min_voltage 125

uint16 ADC_output;

/* Transfer Group 0 */
/* Initial data to be sent the very first time on power up to the ADC
 * NOTE: May or may not need to be changed
 *
 */
uint16 TX_Data_Master[1] = {0xAAAA};
uint16 TX_Data_Slave[1]  = {0};
uint16 RX_Data_Master[1] = {0};
uint16 RX_Data_Slave[1]  = {0};

uint16 RX_Yash_Master[1]   = {0};
uint16 RX_ADS7044_Slave[1] = {0};

bool TX_AVAILABLE = false;  // flags to only transfer mibspi data from slave when current transfer has finished
bool tx_master = false;     // flags to only transfer mibspi data from master when current transfer has finished

//#define hv_vs_timer_PERIOD 500;

void hv_vs_process(uint8_t state)
{
    switch(state)
    {
        case HV_VS_LOWER_BOUND:
            hv_vs_lower_bound();
            break;
        case HV_VS_UPPER_BOUND:
            hv_vs_upper_bound();
            break;
        case HV_VS_OUT_OF_LOWERBOUND:
            hv_vs_out_of_lowerBound();
            break;
        case HV_VS_OUT_OF_UPPERBOUND:
            hv_vs_out_of_upperBound();
            break;
        case HV_VS_AT_ZERO:
            hv_vs_at_zero();
            break;
        case HV_VS_SWEEP:
            hv_vs_sweep();
            break;
    }
}

static int twosComplement(int negative_output){
    negative_output=negative_output*(-1);
    int carry = 1;
    int i;
    int binary[12] ={};
    binary[0] =1;

    // converting to a binary value in ones complement form
    for (i=11;negative_output>0;i--){
        binary[i]=negative_output%2;
        uint8 v = binary[i];
        negative_output=negative_output/2;

        if (v == 0){
            UARTprintf("0");
        }
        sciSend(PC_UART,1,&v);
    }
    UARTprintf("\n\r");

    // converting to ones'complement
    for (i=1;i<=11;i++){
        if (binary[i]==0){
            binary[i]=1;
        }
        else if(binary[i]==1){
            binary[i]=0;
        }
        uint8 v = binary[i];
        if (v == 0){
                    UARTprintf("0");
                }
                sciSend(PC_UART,1,&v);
            }
        UARTprintf("\n\r");

    // converting to twos'complement
    for (i=11;i>=0;i--){
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
        uint8 v = binary[i];
        if (v == 0){
                UARTprintf("0");
                            }
            sciSend(PC_UART,1,&v);
    }
    UARTprintf("\n\r");

    // converting back to an unsigned decimal
    int t = (binary[0]*pow(2,11)+binary[1]*pow(2,10)+binary[2]*pow(2,9)+binary[3]*pow(2,8)+binary[4]*pow(2,7)
            +binary[5]*pow(2,6)+binary[6]*pow(2,5)+binary[7]*pow(2,4)+binary[8]*pow(2,3)+binary[9]*pow(2,2)+
            binary[10]*pow(2,1)+binary[11]*pow(2,0));

    for (i=11;i>=0;i--){
               uint8 v=(int) ((t >> i) & 1);
               if (v == 0){
                   UARTprintf("0");
               }
               sciSend(PC_UART,1,&v);
            }
            UARTprintf("\n\r");

    return t;
    }

static int getADCdigital(int battery_voltage)
{
   int output_voltage;
   // convert accumulator voltage to ADC output in integer form
   if (battery_voltage >144){
       output_voltage = (int)(((battery_voltage *(4.99/479.99))-1.5)*8.2/2.0475*2047);
   }
   else{
       output_voltage = (int)((1.5-(battery_voltage *(4.99/479.99)))*8.2/(-2.0475)*2047);
       if(output_voltage<0){
           output_voltage = twosComplement(output_voltage);
       }
   }
   return output_voltage;
}

static void hv_vs_lower_bound()
{
    //sending lower bound voltage of 125
    //should send -1643 to SPI
    ADC_output = (uint16)getADCdigital(125);
    spiSetup(ADC_output);
    UARTprintf("Minimum operating battery voltage level \n\r");
        int i;
        for (i=15;i>=0;i--){
           uint8 v=(int) ((ADC_output >> i) & 1);
           if (v == 0){
               UARTprintf("0");
           }
           sciSend(PC_UART,1,&v);
        }
        UARTprintf("\n\r");
}

static void hv_vs_upper_bound(){
    //sending upper bound voltage of 168
    //should send value of 2021 to SPI
    ADC_output = (uint16_t)getADCdigital(168);
    spiSetup(ADC_output);
    UARTprintf("Maximum operating battery voltage level \n\r");
    int i;
    for (i=15;i>=0;i--){
       uint8 v=(int) ((ADC_output >> i) & 1);
       if (v == 0){
           UARTprintf("0");
       }
       sciSend(PC_UART,1,&v);
    }
    UARTprintf("\n\r");
}

static void hv_vs_out_of_lowerBound()
{
    // HV_VS doesn't operate outside normal operating range between 125V and 168V
    //sending ADC output voltage below the lower bound voltage of 125V
    ADC_output = (uint16)getADCdigital(120);
    spiSetup(ADC_output);
    UARTprintf("120V voltage level \n\r");
        int i;
        for (i=15;i>=0;i--){
           uint8 v=(int) ((ADC_output >> i) & 1);
           if (v == 0){
               UARTprintf("0");
           }
           sciSend(PC_UART,1,&v);
        }
        UARTprintf("\n\r");
}

static void hv_vs_out_of_upperBound()
{
    //sending ADC output voltage above the upper bound voltage of 168V
    //should send value of 2191 to SPI
    ADC_output = (uint16)getADCdigital(170);
    spiSetup(ADC_output);
    UARTprintf("170V voltage level \n\r");
            int i;
            for (i=15;i>=0;i--){
               uint8 v=(int) ((ADC_output >> i) & 1);
               if (v == 0){
                   UARTprintf("0");
               }
               sciSend(PC_UART,1,&v);
            }
            UARTprintf("\n\r");
}

static void hv_vs_at_zero()
{
    // HV_VS indicate 0 voltage
    // sending ADC output voltage of 0
    ADC_output = (uint16)0;
    spiSetup(ADC_output);
    UARTprintf("0V voltage level \n\r");
               int i;
               for (i=15;i>=0;i--){
                  uint8 v=(int) ((ADC_output >> i) & 1);
                  if (v == 0){
                      UARTprintf("0");
                  }
                  sciSend(PC_UART,1,&v);
               }
               UARTprintf("\n\r");
}

/* Sweep test with a timer */

static void hv_vs_sweep()
{
    //reset timer ID (counts # of cycles)
    setTimerID(HV_VS, 0);

    //start timer
    startTimer(HV_VS, SWEEP_TIMER, SWEEP_PERIOD);
}

void hv_vs_timer(TestTimer_t test_timer, int ID){

    #ifdef TIMER_DEBUG
    UARTprintf("hv_vs sweep timer expired.\n\n\r");
    #endif

    int input_voltage = min_voltage + ID;
    ADC_output = (uint16)getADCdigital(input_voltage);
    spiSetup(ADC_output);
    int i;
    for (i=15;i>=0;i--){
        uint8 v=(int) ((ADC_output >> i) & 1);
        if (v == 0){
            UARTprintf("0");
        }
        sciSend(PC_UART,1,&v);
    }
    UARTprintf("\n\r");

    //Stop condition
    if(input_voltage >=168){
        stopTimer(HV_VS);
    }

    //increment cycle
    setTimerID(HV_VS, ++ID);
}

static void spiSetup(uint16 voltage)
{
    mibspiSetData(mibspiREG3, TransferGroup1, &voltage);
    mibspiEnableGroupNotification(mibspiREG3, TransferGroup1, 0);
    mibspiTransfer(mibspiREG3,TransferGroup1);
}

void mibspiGroupNotification(mibspiBASE_t *mibspi, uint32 group)
{

    if (mibspi == mibspiREG1 && group == TransferGroup0)
     {
         mibspiDisableGroupNotification(mibspiREG1, TransferGroup0);
         mibspiGetData(mibspi, group, RX_Data_Master);
         tx_master = true;
     }

    if (mibspi == mibspiREG1 && group == TransferGroup1)
    {
        mibspiDisableGroupNotification(mibspiREG1, TransferGroup1);
        mibspiGetData(mibspi, group, RX_Yash_Master);
        tx_master = true;
    }

    /**********************************
     *  TESTING FOR SLAVE FUNCTIONALITY
     ***********************************/

        if (mibspi == mibspiREG3 && group == TransferGroup1)
        {
            mibspiDisableGroupNotification(mibspiREG3, TransferGroup1);
            mibspiGetData(mibspi, group, RX_ADS7044_Slave);
            TX_AVAILABLE = true;
        }

        if (mibspi == mibspiREG3 && group == TransferGroup0)
        {
            mibspiDisableGroupNotification(mibspiREG3, TransferGroup0);
            TX_AVAILABLE = true;
        }
}

/*****************************************************************************
 *                 ADC SLAVE SETUP FUNCTIONS - DO NOT MODIFY
 *****************************************************************************/
/* used for ramping up and down the measured voltage simulated by the ADC */

void adcSlaveDataSetup()
{
    mibspiSetData(mibspiREG3, TransferGroup0, TX_Data_Slave);
    mibspiEnableGroupNotification(mibspiREG3, TransferGroup0, 0);
    mibspiTransfer(mibspiREG3, TransferGroup0);
}
