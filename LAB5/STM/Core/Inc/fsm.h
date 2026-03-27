/*
 * fsm.h
 *
 *  Created on: Nov 9, 2025
 *      Author: hieun
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "main.h"
#include <stdint.h>

extern uint8_t  waiting_for_ok;
extern uint32_t timeout_counter;
extern const uint32_t TIMEOUT_3S;
extern char last_adc_response[20];
extern uint32_t current_adc_value;

#endif /* INC_FSM_H_ */
