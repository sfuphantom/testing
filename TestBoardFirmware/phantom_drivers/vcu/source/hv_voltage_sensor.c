/*
 * hv_voltage_sensor.c
 *
 *  Created on: Mar 16, 2021 
 *      Author: Ryan Heo
 */

#include "hv_voltage_sensor.h"
#include <math.h>

# define MAX_DATA_BITS  (12u)
# define START_INDEX    (1u)

static uint8 binaryNum[12];

enum
{
    NORMAL_HV_VS_OPERATION,
    HV_VS_BOTH_BOUNDS,
    HV_VS_OUT_OF_RANGE,
    HV_VS_AT_ZERO,
    HV_VS_SWEEP
};

// Static function prototypes
static void normal_hv_vs_operation();

void hv_cs_process(uint8_t state)
{
    switch(state)
    {
        case NORMAL_HV_VS_OPERATION:
            normal_hv_vs_operation();
            break;
        case HV_VS_BOTH_BOUNDS:
            hv_vs_both_bounds();
            break;
        case HV_VS_OUT_OF_RANGE:
            hv_vs_out_of_range();
            break;
        case HV_VS_AT_ZERO:
            hv_vs_at_zero();
            break;
        case HV_VS_SWEEP:
            hv_vs_sweep();
            break;
    }
}


static float (int battery_voltage)
{
   float output_voltage;
   // convert accumulator voltage to ADC output in floating form
   if (battery_voltage >=0){
       output_voltage = ((battery_voltage *(4.99/479.99))-1.5)*8.2/2.048*2^12;
   }
   else if {
       output_voltage = ((1.5-(battery_voltage *(4.99/479.99)))*8.2/2.048*2^12;
   }
   return output_voltage;
}

static void decToBinary(float ADC_input)
{
  int remainder, counter = 0, my_binary = 0;
  while (integer > 0)
{
    remainder = integer % 2;
    my_binary += remainder * pow(10, counter);
    integer /= 2;
    counter++;
}  
    return my_binary
}


static void extract12bits(int n)
{
    int  idx = 0;
    // Size of an integer is assumed to be 12 bits
    for (idx = (MAX_DATA_BITS -1) ; idx >= 0; idx--)
    {
        int k = n >> idx;
        if (k & 1)
        {
            binaryNum[idx] = 1;
        }
        else
        {
            binaryNum[idx] = 0;
        }
    }
}

void getADCdigital(int input)
{
    float output;

    adc_input = analogtodigital (input)
    TX_ADS7044_Slave[1] = decToBinary(adc_input);
}

static void normal_hv_vs_operation()
{
    // HV_VS operate between 125V and 168V range
    ADC_output_voltage = getADCdigital();
    
}

static void hv_vs_both_bounds()
{
    // HV_VS indicate 125V and 168V
}

static void hv_vs_out_of_range()
{
    // HV_VS operate outside normal operating range between 125V and 168V
}

static void hv_vs_at_zero()
{
    // HV_VS indicate 0 voltage
    TX_ADS7044_Slave[1] = 0;
}

static void HV_VS_SWEEP()
{
    // Sweep test checking range of values
}
