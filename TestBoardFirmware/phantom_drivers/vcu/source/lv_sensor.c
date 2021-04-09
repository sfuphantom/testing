/*
 * lv_sensor.c
 *
 *  Created on: April 1, 2021
 *      Author: Vlad Bors
 */
​
#include "lv_sensor.h"
​
enum operation
{
    LV_POW_STD_OP, // standard operation, send 12v to power
    LV_POW_UV, // power undervoltage, send 9v to power
    LV_POW_OV, // power overvoltage, send 15v to power
    LV_POW_POWERDRAW, // power draw, send any signal to chip's shunt resistor
    LV_POW_CURRENT_SHORT, // high current signal, short signal to shunt for an instant
    LV_POW_CURRENT_SUSTAINED, // sustained high current, short a sustained signal to shunt
};

// static function definitions
static void lv_pow_std_op();
static void lv_pow_uv();
static void lv_pow_ov();
static void lv_pow_powerdraw();
static void lv_pow_current_short();
static void lv_pow_current_sustained();
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
        case LV_POW_CURRENT_SHORT:
            lv_pow_current_short();
            break;
        case LV_POW_CURRENT_SUSTAINED:
            lv_pow_current_sustained();
            break;
        default:
            lv_pow_std_op();
            break;
    }
}
​
void lv_pow_std_op() {
    uint16_t mode;
    ​
        ​
}

void v_pow_uv() {
    ​
        ​
}

void lv_pow_ov() {
    ​
        ​
}

void lv_pow_powerdraw() {
    ​
        ​
}

void lv_pow_current_short() {
    ​
        ​
}

void lv_pow_current_sustained() {
    ​
        ​
}