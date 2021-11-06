/*
 * apps.c
 *
 *  Created on: Nov 12, 2020 
 *      Author: Courtenay Huffman
 */

#include "apps.h"

#define APPS1_MAX 440
#define APPS1_MIN 150
#define APPS2_MAX 150
#define APPS2_MIN 50

// Static function prototypes
static void normal_apps_on();
static void normal_apps_off();
static void apps_implausibility();
static void apps_open_circuit();
static void apps_short_circuit();
static void apps_bse_activated();
static void apps_sweep();

//Timer Periods
#define SHORT_PERIOD 500
#define OPEN_PERIOD 500
#define BSE_ACTIVATED_PERIOD 500

static int voltage;

void apps_process(uint8_t state)
{
    switch(state)
    {
        case NORMAL_APPS_ON:
            normal_apps_on();
            break;
        case APPS_IMPLAUSIBILITY:
            apps_implausibility();
            break;
        case APPS_SHORT_CIRCUIT:
            apps_short_circuit();
            break;
        case APPS_OPEN_CIRCUIT:
            apps_open_circuit();
            break;
        case APPS_BSE_ACTIVATED: //be wary of this test...bse cannot change the value
            apps_bse_activated();
            break;
        case APPS_SWEEP:
            apps_sweep();
            break;
        default: 
            normal_apps_off();
            break;
    }
}

static void normal_apps_off(){

    sendAPPSVoltages(APPS1_MIN, APPS2_MIN);
    return;
}

static void normal_apps_on()
{
    // sets APPS values at midpoint of valid APPS range
    uint16_t apps1_volt = ((APPS1_MAX-APPS1_MIN)/2)+APPS1_MIN;

    sendAPPSdiff(apps1_volt, 1.0);
    return;
}

static void apps_implausibility()
{
    uint16_t apps1_volt = ((APPS1_MAX-APPS1_MIN)/2)+APPS1_MIN;

    sendAPPSdiff(apps1_volt, 1.15);

    return;
}

static void apps_short_circuit()
{
    setTimerID(APPS, 0);

    setTimerCallback(APPS, apps_short_callback);

    startTimer(APPS, SHORT_PERIOD);

    return;
}

static void apps_open_circuit()
{
    setTimerID(APPS, 0);

    setTimerCallback(APPS, apps_open_callback);

    startTimer(APPS, OPEN_PERIOD);

    return;
}

static void apps_bse_activated()
{
    //reset timer ID if necessary...

    // BSE activated
//    bse_process(NORMAL_BSE_ON);
//
//    startTimer(APPS, BSE_ACTIVATED_PERIOD);
//    return;
}

static void apps_sweep()
{
    setTimerID(APPS, 0);

    setTimerCallback(APPS, apps_sweep_callback);

    startTimer(APPS, SWEEP_PERIOD);

    return;
}


/* Timer-Callback Functions */

void apps_sweep_callback(int ID){

    #ifdef TIMER_DEBUG
    UARTprintf("Apps sweep timer expired.\n\n\r");
    #endif

    voltage = update_value(APPS, APPS1_MIN, APPS1_MAX, 50, ID, true);


    sendAPPSdiff(voltage, 1.0);
}

void apps_short_callback(int ID){

    #ifdef TIMER_DEBUG
    UARTprintf("Apps short timer expired\n\n\r");
    #endif

    voltage = update_value(APPS, APPS1_MIN, APPS1_MAX, 20, ID, true);

    if (voltage >= APPS1_MIN)    sendAPPSVoltages(APPS1_MAX+20, APPS2_MAX); //short APPS1

    if (voltage >= APPS1_MAX+20) sendAPPSVoltages(APPS1_MAX, APPS2_MAX+20); //APPS1 shorted to APPS1 normal, APPS2 shorted

    if (voltage >= APPS2_MAX+20) sendAPPSVoltages(APPS1_MAX+20, APPS2_MAX+20); //APPS2 shorted to both shorted
}

void apps_open_callback(int ID){

    #ifdef TIMER_DEBUG
    UARTprintf("Apps open timer expired\n\n\r");
    #endif

    voltage = update_value(APPS, APPS2_MIN, APPS1_MIN, -20, ID, false);

    if (voltage < APPS1_MIN)     sendAPPSVoltages(APPS1_MIN-20, APPS2_MIN); //open APPS1

    if (voltage <= APPS1_MIN-20) sendAPPSVoltages(APPS1_MIN, APPS2_MIN-20); //open APPS2

    if (voltage <= APPS2_MIN-20) sendAPPSVoltages(APPS1_MIN-20, APPS2_MIN-20); //open both
}

/* End of Timer-Related Functions */



//ARCHIVE

/*case BSE_ACTIVATED_TIMER:

           //check if vcu can clear faults (MINOR)

           #ifdef TIMER_DEBUG

           UARTprintf("Apps bse activated timer expired\n\n\r");

           #endif

           // sets APPS values at midpoint of valid APPS range

           prev = APPS1_MIN + ( 20 * ID);

           if (prev == APPS1_MIN){ //FAULT

               apps1_volt = ((APPS1_MAX-APPS1_MIN)/2)+APPS1_MIN; //finding the median

               apps2_volt = create_apps2_volt(apps1_volt, 1.0); //create apps2 counterpart voltage

               MCP48FV_Set_Value_Double(apps1_volt, apps2_volt, DAC_SIZE_APPS, 0);


               delayms(250);

               //apps1 should be median voltage, apps2 should be equivalent to apps1 percentage wise...

               //evaluate VCU state (CAN driver(MINOR)/check throttle pin should be 0V/minimum) configure DAC pin

               //if(testfailed) stopTimer(APPS)


           } else{ //NORMAL OPERATION
               // to be executed after apps_bse_activated()
               // APPS sensors indicate <5% activation, regardless if BSE is still activated
               MCP48FV_Set_Value_Double(APPS1_MIN+10, create_apps2_volt(APPS1_MIN+10, 1.00), DAC_SIZE_APPS, 0); //less than 5% apps range

               delayms(250);

               //apps1 should be 1.6V, apps2 should be 0.5 to 0.6V

               //evaluate VCU state (CAN driver (RUNNING) /check throttle pin should be non-zero voltage)

           }

           setTimerID(APPS, ++ID); //TODO: double check later...

           //STOP CONDITION
           if(ID >= 2)
               stopTimer(APPS);



           break;*/

void apps_unit_test(){

    int i = 0;
    for(i = 0; i < APPS1_MAX; i+=20){

        sendAPPSVoltages(i, i);
        delayms(500);
    }


}
