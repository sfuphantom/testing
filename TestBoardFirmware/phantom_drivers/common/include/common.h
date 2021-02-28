/*
 * common.h
 *
 *  Created on: Nov 9, 2020
 *      Author: Mahmoud Ahmed
 */

#ifndef PHANTOM_DRIVERS_COMMON_INCLUDE_COMMON_H_
#define PHANTOM_DRIVERS_COMMON_INCLUDE_COMMON_H_

#include "stdint.h"

typedef enum
{
  SUCCESS,
  FAIL
} Result_t;

void delayms(uint16_t ms);

#endif /* PHANTOM_DRIVERS_COMMON_INCLUDE_COMMON_H_ */
