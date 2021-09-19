/*
 * shutdown.h
 *
 *  Created on: Sep 18, 2021
 *      Author: Rafael
 */

#ifndef PHANTOM_DRIVERS_COMMON_INCLUDE_SHUTDOWN_H_
#define PHANTOM_DRIVERS_COMMON_INCLUDE_SHUTDOWN_H_

#include "hwConfig.h"
#include "common.h"

//Halcogen Setup
//1.Enable HET1 Driver
//2.Choose Edge Interrupt to enable and output on specific pin
//3.Select VIM Channel for either Low/High Priority (same priority as edge interrupt)
//4.Initialize VIM,GIO, and enableIRQ in the code
//HET1 interrupt set at both edges; set to high priority


#define SHUTDOWN_TIMEOUT_PERIOD 5000

bool validateThrottleControls(uint8_t, uint8_t);

uint8_t getShutdownSignal(); // getter for shutdown signal

void setShutdownOccurence(bool); // tells the validation module the type of shutdown signal to expect

bool getShutdownResult() // getter for shutdown_fail

void shutdown_timeout_callback(int);



#endif /* PHANTOM_DRIVERS_COMMON_INCLUDE_SHUTDOWN_H_ */
