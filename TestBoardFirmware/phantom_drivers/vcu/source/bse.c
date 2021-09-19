/*
 * bse.c
 *
 *  Created on: Nov 12, 2020 
 *      Author: Courtenay Huffman
 */

#include "bse.h"

#define BSE_MAX 4300
#define BSE_MIN 1500
#define BSE_OPEN 0
#define BSE_SHORT 5000
#define VOUT1 1
#define DAC_SIZE_BSE 0xFF

// Static function prototypes
static void normal_bse_off();
static void normal_bse_on();
static void bse_open_circuit();
static void bse_short_circuit();
static void apps_bse_activated();
static void bse_sweep();
uint16_t get_bse_voltage(uint16_t dac_val);

void bse_process(uint8_t state){

    switch(state)
    {
        case NORMAL_BSE_ON:
            normal_bse_on();
            break;
        case BSE_OPEN_CIRCUIT:
            bse_open_circuit();
            break;
        case BSE_SHORT_CIRCUIT:
            bse_short_circuit();
            break;
        case BSE_SWEEP:
            bse_sweep();
            break;
        case BSE_APPS_ACTIVATED:
            apps_bse_activated();
            break;
        default:
            normal_bse_off();
            break;
    }
}

static void normal_bse_off(){
    //sets BSE value at minimum of its range as though the pedal is not being pressed
   MCP48FV_Set_Value_Single(BSE_MIN, DAC_SIZE_BSE, VOUT1, 1);
    return;
}

static void normal_bse_on(){
    // sets BSE value at midpoint of operating range
    uint16_t bse_volt = ((BSE_MAX-BSE_MIN)/2)+BSE_MIN;
   MCP48FV_Set_Value_Single(bse_volt, DAC_SIZE_BSE, VOUT1, 1);
    return;
}

static void bse_open_circuit(){
    // bse sensor reads an open circuit (0V)
   MCP48FV_Set_Value_Single(BSE_OPEN, DAC_SIZE_BSE, VOUT1, 1);
    return;
}

static void bse_short_circuit(){
    // bse sensor reads a short circuit (5V)
   MCP48FV_Set_Value_Single(BSE_SHORT, DAC_SIZE_BSE, VOUT1, 1);
    return;
}

/* Timer-Related Functions */

void bse_sweep_timer(int ID){

    #ifdef TIMER_DEBUG
    UARTprintf("Bse sweep timer expired.\n\n\r");
    #endif

    int voltage = update_value(BSE, BSE_MIN, BSE_MAX, SWEEP_STEP, ID, true);

    MCP48FV_Set_Value_Single(voltage, DAC_SIZE_BSE, VOUT1, 1);

}

static void bse_sweep(){

    //reset timer ID ( counts # of cycles)
    setTimerID(BSE, 0);

    setTimerCallback(BSE, bse_sweep_timer);

    //start timer
    startTimer(BSE, SWEEP_PERIOD);
}

/* End of Timer-Related Functions */

static void apps_bse_activated(){
    normal_bse_on();
    return;
}

uint16_t get_bse_voltage(uint16_t dac_val){
    return ((dac_val*500000)/(0xFF*1000));
}
