/*
 * hv_current_sensor.c
 *
 *      Author: Nathan Cushing
 */

#include "hv_current_sensor.h"
#include "MCP48FV_DAC_SPI.h"

#define VOUT1 1
#define DAC_SIZE_HVCT 0xFF

const int MAX_VOUT = 438;
const int MIN_VOUT = 63;

enum operation 
{  
    INTERVAL_HV_CT_RANGE, //send range of voltages at .125V intervals
    GRANULAR_HV_CT_RANGE, //send range of voltages at .001V intervals
    OFFLINE_HV_CT, //send 0V
    PROPORTIONAL_APPS, //send voltages at .1V intervals, alongside APPS readings
    LOW_APPS, //same as proportional_apps, but apps is too low
    HIGH_APPS //same as proportional_apps, but apps is too high
};

//Test function prototypes
static void interval_hv_ct_range();
static void granular_hv_ct_range();
static void offline_hv_ct();
static void proportional_apps();
static void low_apps();
static void high_apps();

//ignore this test
//Test 1
void interval_hv_ct_range()
{
    uint16_t current = 63;
    for(int i = 0; i<30;i++)
    {
        current += i*;
        MCP48FV_Set_Value_Single(current, DAC_SIZE_HVCT, VOUT1, 1);
    }
}

//Test 2
void granular_hv_ct_range()
{
    //test goes from .63V to 4.3V
    uint16_t current = MIN_VOUT;
    for( ; current<MAX_VOUT; current++)
        MCP48FV_Set_Value_Single(current, DAC_SIZE_HVCT, VOUT1, 1);
    //for this one, make sure to make .csv files to graph the the values after, and they should be roughly proportional
    //max uncertainty can be 4amps 
}

//Test 3
void offline_hv_ct()
{
    MCP48FV_Set_Value_Single(0, DAC_SIZE_HVCT, VOUT1, 1);
}

//Test 4
void proportional_apps()
{
    int current = MIN_VOUT;
    int i = 0;
    while (current<MAX_VOUT)
    {
        MCP48FV_Set_Value_Single(current, DAC_SIZE_HVCT, VOUT1, 1);
        //send_apps_current(current);
        i += 10;
        current += i;
    }
}

//Test 5
void low_apps()
{
    int current = MIN_VOUT;
    int i = 0;
    while (current<MAX_VOUT)
    {
        MCP48FV_Set_Value_Single(current, DAC_SIZE_HVCT, VOUT1, 1);
        //send_apps_current(current-10);
        i += 10;
        current += i;
    }
}

//Test 6
void high_apps()
{
    int current = MIN_VOUT;
    int i = 0;
    while (current<MAX_VOUT)
    {
        MCP48FV_Set_Value_Single(current, DAC_SIZE_HVCT, VOUT1, 1);
        //send_apps_current(current+10);
        i += 10;
        current += i;
    }
}