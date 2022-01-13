/*
 * hv_current_sensor.c
 *
 *      Author: Nathan Cushing
 */

#include "hv_current_sensor.h"
#include "apps.h"
#include "timer.h"

#define VOUT1 1
#define DAC_SIZE_HVCT 0xFF //8 bit DAC
#define MAX_VOUT 438 //4.375V, highest the HVCT should record -> 300A
#define MIN_VOUT 63 //.625V, lowest the HVCT should record -> -300A
#define OFFLINE_VOUT 0

#define HVCT_SWEEP_STEP 1 //Voltage step 1 -> 0.01 volts

/*
enum operation 
{  
    NORMAL_HVCT, //sends a HVCT corresponding to 100A
    SWEEP_HV_CT_RANGE, //send range of voltages at .01V intervals
    OFFLINE_HV_CT, //send 0V
    PROPORTIONAL_APPS, //send voltages at .1V intervals, alongside APPS readings
    LOW_APPS, //same as proportional_apps, but apps is too low
    HIGH_APPS //same as proportional_apps, but apps is too high
};*/

//Test function prototypes
static void normal_hvct();
static void sweep_hv_ct_range();
static void offline_hv_ct();
static void proportional_apps();
static void low_apps();
static void high_apps();

void hvct_timer(int ID);
void send_hvct_voltage(int voltage);

void hv_ct_process (uint8_t state)
{
    switch (state)
    {
        case NORMAL_HVCT:
            normal_hvct();
            break;
        case SWEEP_HV_CT_RANGE:
            sweep_hv_ct_range();
            break;
        case OFFLINE_HV_CT:
            offline_hv_ct();
            break;
        case PROPORTIONAL_APPS:
            proportional_apps();
            break;
        case LOW_APPS:
            low_apps();
            break;
        case HIGH_APPS:
            high_apps();
            break;
    }
}

//Test 1
static void normal_hvct()
{
    int voltage = (MAX_VOUT-MIN_VOUT)/6; //corrosponds to ~100A
    send_hvct_voltage(voltage);
    return;
}

//Test 2
static void sweep_hv_ct_range()
{
    //How many cycles timer has gone through
    setTimerID(HVCT, 0);

    startTimer(HVCT, SWEEP_PERIOD, true);
    return;

    //test goes from .63V to 4.3V
    //test should take ~3.1 minutes, but can be done shorter if SWEEP_PERIOD is shortened or HVCT_SWEEP_STEP is increased
    //max uncertainty in VCU reading should be 4amps
}

//Test 3
static void offline_hv_ct()
{
    startTimer(HVCT, SWEEP_PERIOD, true);
    MCP48FV_Set_Value_Single(OFFLINE_VOUT, DAC_SIZE_HVCT, VOUT1, 1);
}

//Test 4
static void proportional_apps()
{
    //Function sending mid-range values
    int voltage = (MAX_VOUT-MIN_VOUT)/2;
    int range = MIN_VOUT + voltage;

    //Use HV_CT debug instead of timer_debug
    #ifdef HV_CT_DEBUG
    UARTprintf("Inside proportional apps.\n\n\r");
    #endif

    //normal_apps_on();
    send_hvct_voltage(range);
    return;
}

//Test 5
static void low_apps()
{
    //For foot pedal sensors
    int voltage = (MAX_VOUT-MIN_VOUT)/2;
    int range = (MIN_VOUT + voltage)*1.2;

    #ifdef HV_CT_DEBUG
    UARTprintf("Inside low apps\n\n\r");
    #endif

    //normal_apps_on();
    send_hvct_voltage(range);
    return;
}

//Test 6
static void high_apps()
{
    int voltage = (MAX_VOUT-MIN_VOUT)/2;
    int range = (MIN_VOUT + voltage)*0.8;

    #ifdef HV_CT_DEBUG
    UARTprintf("Inside high apps\n\n\r");
    #endif

    //normal_apps_on();
    send_hvct_voltage(range);
    return;
}

//Misc functions
void hvct_timer(int ID)
{

    #ifdef HV_CT_DEBUG
    UARTprintf("Inside hvct timer\n\n\r");
    #endif

    update_value(HVCT, MIN_VOUT, MAX_VOUT, HVCT_SWEEP_STEP, ID, true);

    //is_ceil is for positive or negative slope
    //doesn't have to be MAX_VOUT or MIN_VOUT. Pass in values based on sweep step

}

void send_hvct_voltage(int voltage)
{
    MCP48FV_Set_Value_Single(voltage, DAC_SIZE_HVCT, VOUT1, 1);
    return;
}
