/*
 * bse.c
 *
 *  Created on: Nov 12, 2020 
 *      Author: Courtenay Huffman
 */

#include "bse.h"
#include "hwConfig.h"
#include "MCP48FV_DAC_SPI.h"

#define BSE_MAX 430
#define BSE_MIN 150
#define BSE_OPEN 0
#define BSE_SHORT 500
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
        case APPS_BSE_ACTIVATED:
            apps_bse_activated();
            break;
        default:
            normal_bse_off();
            break;
    }
}

static void normal_bse_off(){
    //sets BSE value at minimum of its range as though the pedal is not being pressed
//    MCP48FV_Set_Value_Single(BSE_MIN, DAC_SIZE_BSE, VOUT1, 1);
    return;
}

static void normal_bse_on(){
    // sets BSE value at midpoint of operating range
    uint16_t bse_volt = ((BSE_MAX-BSE_MIN)/2)+BSE_MIN;
//    MCP48FV_Set_Value_Single(bse_volt, DAC_SIZE_BSE, VOUT1, 1);
    return;
}

static void bse_open_circuit(){
    // bse sensor reads an open circuit (0V)
//    MCP48FV_Set_Value_Single(BSE_OPEN, DAC_SIZE_BSE, VOUT1, 1);
    return;
}

static void bse_short_circuit(){
    // bse sensor reads a short circuit (5V)
//    MCP48FV_Set_Value_Single(BSE_SHORT, DAC_SIZE_BSE, VOUT1, 1);
    return;
}

/* TESTS THE NEED TIMERS BEGIN HERE */

void bse_sweep_timer(Timer sweepTimer, int ID){
    // loops through values within a normal range
    // make sure it stops when it reaches the max voltage
//    int prev_voltage = get_bse_voltage(readRegister(VOUT1, 1));

//    uint8_t num_cycles =  (uint8_t) pvTimerGetTimerID(sweepTimer);


//    #ifdef TIMER_DEBUG
//
////    UARTSend(PC_UART, "Bse sweep timer expired!\n\r");
//
//    UARTSend(PC_UART, (char) num_cycles);
//
//
//    #endif




//    int voltage = BSE_MIN + ( SWEEP_STEP * num_cycles );
//
//    MCP48FV_Set_Value_Single(voltage, DAC_SIZE_BSE, VOUT1, 1);
//
//    //increment cycle
//
//    num_cycles++;
//
//    vTimerSetTimerID( sweepTimer, ( void * ) num_cycles );


    UARTprintf("Bse sweep timer expired!\n\r");


}

static void bse_sweep(){

    //reset timer ID ( counts # of cycles)
    setTimerID(BSE_SWEEP_TIMER, 0);

    //start timer
    startTimer(BSE_SWEEP_TIMER);
}




/* TESTS THAT NEED TIMERS END HERE */

static void apps_bse_activated(){
    normal_bse_on();
    return;
}

uint16_t get_bse_voltage(uint16_t dac_val){
    return ((dac_val*500000)/(0xFF*1000));
}
