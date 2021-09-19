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

/*
 * shutdown.c
 *
 *  Created on: Sep 18, 2021
 *      Author: Rafael Guevara
 */

#include "hwConfig.h"
#include "common.h"
#include "Phantom_sci.h"
#include "shutdown.h"

void initializeShutdownInterrupt();

/* Getters and Setters */

uint8_t isShutdownPass();

uint8_t isShutdownTimeout();

uint8_t getShutdownSignal();

uint8_t getExpectedShutdownResult();

void setShutdownOccurence(bool);

/* Callback Functions */

void shutdown_timeout_callback(int);

void shutdown_callback();


#endif /* PHANTOM_DRIVERS_COMMON_INCLUDE_SHUTDOWN_H_ */
