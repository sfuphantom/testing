/*
 * communications.h
 *
 *  Created on: Oct 25, 2020
 *      Author: Mahmoud Ahmed
 */

#ifndef PHANTOM_DRIVERS_INCLUDE_COMMUNICATIONS_H_
#define PHANTOM_DRIVERS_INCLUDE_COMMUNICATIONS_H_


typedef enum
{
    NORMAL_COMMS_OPERATION,
    COMMS_LOST
} CommunicationsTestState_t;

void communications_process(CommunicationsTestState_t state);


#endif /* PHANTOM_DRIVERS_INCLUDE_COMMUNICATIONS_H_ */
