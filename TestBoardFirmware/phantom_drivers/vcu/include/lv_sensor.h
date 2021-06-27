/*
 * lv_sensor.h
 *
 *  Created on: April 8, 2021
 *      Author: Vlad Bors
 */
<<<<<<< HEAD
​
#ifndef PHANTOM_DRIVERS_INCLUDE_LV_SENSOR_H_
#define PHANTOM_DRIVERS_INCLUDE_LV_SENSOR_H_
​
#include "stdint.h"

void lv_sensor_process(uint8_t state);



#endif /* PHANTOM_DRIVERS_INCLUDE_LV_SENSOR_H_ */
=======
#ifndef PHANTOM_DRIVERS_VCU_INCLUDE_LV_POWER_SENSOR_TEST_H_
#define PHANTOM_DRIVERS_VCU_INCLUDE_LV_POWER_SENSOR_TEST_H_


#define LV_DATA_COUNT  2
#define LV_Slave_Address  0x40

//Register
#define LV_configuration_register 0x00
#define LV_Shunt_register 0x01
#define LV_bus_voltage_register 0x02
#define LV_calibration_register 0x05
#define LV_current_register 0x04
#define LV_power_register 0x03

void hv_cs_process(uint8_t state)
void lv_pow_std_op();
void lv_pow_uv();
void lv_pow_ov();
void lv_pow_powerdraw();
void lv_pow_current_short();
void lv_pow_current_sust();
​
#endif /* PHANTOM_DRIVERS_VCU_INCLUDE_LV_POWER_SENSOR_TEST_H_ */
>>>>>>> master
