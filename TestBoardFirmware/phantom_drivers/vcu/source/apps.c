/*
 * apps.c
 *
 *  Created on: Nov 12, 2020 
 *      Author: Courtenay Huffman
 */

#include "apps.h"

#define APPS1_MAX 4400
#define APPS1_MIN 1500
#define APPS2_MAX 1500
#define APPS2_MIN 500
#define DAC_SIZE_APPS 0xFF

// Static function prototypes
static void normal_apps_on();
static void normal_apps_off();
static void apps_implausibility();
static void apps_open_circuit();
static void apps_short_circuit();
static void apps_bse_activated();
static void apps_sweep();
uint16_t create_apps2_volt(uint16_t apps1_volt, float difference);
uint16_t get_apps_voltage(uint16_t dac_val);

//Timer Periods
#define SHORT_PERIOD 500
#define OPEN_PERIOD 500
#define BSE_ACTIVATED_PERIOD 500

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
    MCP48FV_Set_Value_Double(APPS1_MIN, APPS2_MIN, DAC_SIZE_APPS, 0);
    return;
}

static void normal_apps_on()
{
    // sets APPS values at midpoint of valid APPS range
    uint16_t apps1_volt = ((APPS1_MAX-APPS1_MIN)/2)+APPS1_MIN;
    uint16_t apps2_volt = create_apps2_volt(apps1_volt, 1.0);

    MCP48FV_Set_Value_Double(apps1_volt, apps2_volt, DAC_SIZE_APPS, 0);
    return;
}

static void apps_implausibility()
{
    uint16_t apps1_volt = ((APPS1_MAX-APPS1_MIN)/2)+APPS1_MIN;
    uint16_t apps2_volt = create_apps2_volt(apps1_volt, 1.15);

    MCP48FV_Set_Value_Double(apps1_volt, apps2_volt, DAC_SIZE_APPS, 0);

    return;
}

/* Timer-Related Functions */

static void apps_short_circuit()
{
    //reset timer ID if necessary...

    setTimerID(APPS, 0);

    startTimer(APPS, SHORT_TIMER, SHORT_PERIOD);
    return;
}

static void apps_open_circuit()
{
    //reset timer ID if necessary...

    setTimerID(APPS, 0);

    startTimer(APPS, OPEN_TIMER, OPEN_PERIOD);
    return;
}

static void apps_bse_activated()
{
    //reset timer ID if necessary...

    // BSE activated
    bse_process(NORMAL_BSE_ON);

    startTimer(APPS, BSE_ACTIVATED_TIMER, BSE_ACTIVATED_PERIOD);
    return;
}

static void apps_sweep()
{
    //reset timer ID if necessary...

    setTimerID(APPS, 0);

    startTimer(APPS, SWEEP_TIMER, SWEEP_PERIOD);
    return;
}

void apps_timer(TestTimer_t test_timer, int ID){

    uint16_t apps1_volt, apps2_volt; //bse_activated_timer

    uint16_t prev; //short_timer, open_timer

    int prev_voltage; //sweep_timer

    switch(test_timer){

        case SWEEP_TIMER:

            #ifdef TIMER_DEBUG
            UARTprintf("Apps sweep timer expired.\n\n\r");
            #endif

            // make sure it doesnt go over voltage - stop it somehow
//            prev_voltage = get_apps_voltage(readRegister(0, 0));
           prev_voltage = APPS1_MIN + ( 500 * ID);

            //STOP CONDITION
           if(prev_voltage > APPS1_MAX){


               stopTimer(APPS);

               prev_voltage = APPS1_MAX;
           }

            MCP48FV_Set_Value_Double(prev_voltage, create_apps2_volt(prev_voltage, 1.00), DAC_SIZE_APPS, 0);

            setTimerID(APPS, ++ID);

            break;

        case SHORT_TIMER:

            #ifdef TIMER_DEBUG

            UARTprintf("Apps short timer expired\n\n\r");

            #endif

            prev = APPS1_MIN + ( 200 * ID);

            if (prev >= APPS1_MIN) MCP48FV_Set_Value_Double(APPS1_MAX+20, APPS2_MAX, DAC_SIZE_APPS, 0); //short APPS1

            if (prev >= APPS1_MAX+20) MCP48FV_Set_Value_Double(APPS1_MAX, APPS2_MAX+20, DAC_SIZE_APPS, 0); //APPS1 shorted to APPS1 normal, APPS2 shorted

            if (prev >= APPS2_MAX+20) MCP48FV_Set_Value_Double(APPS1_MAX+20, APPS2_MAX+20, DAC_SIZE_APPS, 0); //APPS2 shorted to both shorted

            ///STOP CONDITION
            if(prev > APPS1_MAX)
                stopTimer(APPS);

            setTimerID(APPS, ++ID);

            break;

        case OPEN_TIMER:

            #ifdef TIMER_DEBUG

            UARTprintf("Apps open timer expired\n\n\r");

            #endif

//            prev = get_apps_voltage(readRegister(0, 0));

            prev = APPS1_MIN - ( 200 * ID);


            if (prev < APPS1_MIN){
                MCP48FV_Set_Value_Double(APPS1_MIN-200, APPS2_MIN, DAC_SIZE_APPS, 0); //open APPS1
            }

            if (prev <= APPS1_MIN-200) {
                MCP48FV_Set_Value_Double(APPS1_MIN, APPS2_MIN-200, DAC_SIZE_APPS, 0); //open APPS2
            }

            if (prev <= APPS2_MIN-200) {
                MCP48FV_Set_Value_Double(APPS1_MIN-200, APPS2_MIN-200, DAC_SIZE_APPS, 0); //open both
            }

            ///STOP CONDITION
            if(prev < APPS2_MIN)
                stopTimer(APPS);

            setTimerID(APPS, ++ID);


            break;

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

        default:


            UARTprintf("ERROR. APPS Timer not found\r\n");


            break;

    }//switch case

    //do some ID update here if necessary...

}

/* End of Timer-Related Functions */


// difference is the ratio difference between APPS values, 1 meaning 0% difference
uint16_t create_apps2_volt(uint16_t apps1_volt, float difference){
    uint16_t apps2_volt = (difference*((apps1_volt-APPS1_MIN)/(APPS1_MAX-APPS1_MIN))*(APPS2_MAX-APPS2_MIN))+APPS2_MIN;
    return apps2_volt;
}

uint16_t get_apps_voltage(uint16_t dac_val){
    return ((dac_val*500000)/(0xFF*1000));
}
