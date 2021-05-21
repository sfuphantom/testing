/*
 * hv_current_sensor.c
 *
 *      Author: Nathan Cushing
 */

#include "hv_current_sensor.h"

enum operation 
{  
    INTERVAL_HV_CT_RANGE //send range of voltages at .125V intervals
    GRANULAR_HV_CT_RANGE, //send range of voltages at .001V intervals
    OFFLINE_HV_CT, //send 0V
    PROPORTIONAL_APPS, //send voltages at .125 intervals, alongside APPS readings
};

//Test function prototypes
static void interval_hv_ct_range();
static void granular_hv_ct_range();
static void offline_hv_ct();
static void proportional_apps();
static void low_apps();
static void high_apps();

//Other function prototypes
static float send_hvct_current(int a);
static float send_apps_current(int a);

//Variable notes
    //The voltages can be stored as ints, where the range is from 0 to 3750, corrosponding to .625 - 4.375V.

//Test 1
void interval_hv_ct_range()
{
    int currentInt = 0;
    for(int i = 0; i<30;i++)
    {
        currentInt = i*125;
        send_hvct_current(currentInt);
    }
}

//Test 2
void granular_hv_ct_range()
{
    int currentInt = 0;
    for(int i = 0; i<3750;i++)
    {
        currentInt = i*125;
        send_hvct_current(currentInt);
    }
    //for this one, make sure to make .csv files to graph the the values after, and they should be roughly proportional
    //max uncertainty can be 4amps 
}

//Test 3
void offline_hv_ct()
{
    send_hvct_current(0);
}

//Test 4
void proportional_apps()
{
    int currentInt = 0;
    for(int i = 0; i<30;i++)
    {
        currentInt = i*125;
        send_hvct_current(currentInt);
        send_apps_current(currentInt);
    }
}

//Test 5
void low_apps()
{
    int currentInt = 0;
    for(int i = 0; i<30;i++)
    {
        currentInt = i*125;
        send_hvct_current(currentInt);
        send_apps_current(currentInt-125);
    }
}

//Test 6
void high_apps()
{
    int currentInt = 0;
    for(int i = 0; i<30;i++)
    {
        currentInt = i*125;
        send_hvct_current(currentInt);
        send_apps_current(currentInt+125);
    }
}

//Other functions
void send_hvct_current(int currentInt)
{
    currentInt = currentInt*.001 + .625
    //convert int to float
    //send the current to the VCU
}

void send_apps_current(int currentInt)
{
    //convert int to what the APPS should be. ie, with 200A, there should be x amount of the pedal pushed down.
    //send the apps value to the VCU
}