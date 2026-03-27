/*
 * input_reading.h
 *
 *  Created on: Oct 12, 2025
 *      Author: hieun
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_1s(unsigned int index);
void initial_setting();

#endif /* INC_INPUT_READING_H_ */
