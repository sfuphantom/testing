/*
 * shutdown.h
 *
 *  Created on: Sep 18, 2021
 *      Author: Rafael Guevara
 */

#ifndef PHANTOM_DRIVERS_COMMON_INCLUDE_SHUTDOWN_H_
#define PHANTOM_DRIVERS_COMMON_INCLUDE_SHUTDOWN_H_

#include "hwConfig.h"
#include "sys_vim.h"
#include "common.h"
#include <phantom_drivers/common/include/timer.h>
#include "gpio_tests.h"
#include "Phantom_sci.h"
#include "gio.h"
#include "het.h"

// Halcogen Setup
// 1.Enable HET1 Driver
// 2.Choose Edge Interrupt to enable and output on specific pin
// 3.Select VIM Channel for either Low/High Priority (same priority as edge interrupt)
// 4.Initialize VIM, GIO, and enableIRQ in the code
// HET1 interrupt set at both edges; set to high priority with internal pull up resistor

#define SHUTDOWN_TIMEOUT_PERIOD 5000
#define SHUTDOWN_RESULT_INVALID -1
#define SHUTDOWN_ACTIVE_LOW true // determines logic of test

void initializeShutdownInterrupt();

/* Getters and Setters */

int8_t isShutdownPass();
uint8_t isShutdownTimeout();
uint8_t getShutdownSignal();
uint8_t getExpectedShutdownResult();
void setShutdownOccurence(bool);

/* Callback Functions */

void shutdown_timeout_callback(int);
void shutdown_callback();

#ifdef SHUTDOWN_UNIT_TESTS
void shutdownStaleTest();
void shutdownExpectedTest();
void shutdownUnexpectedTest();
void timeout_test();

#endif

#endif /* PHANTOM_DRIVERS_COMMON_INCLUDE_SHUTDOWN_H_ */
