/*
 * common.c
 *
 *  Created on: Nov 9, 2020
 *      Author: Mahmoud Ahmed
 */

#include "stdint.h"

void delayms(uint16_t ms) {
      volatile unsigned int delayval;
      delayval = ms * 8400;   // 8400 are about 1ms
      while(delayval--);
}

