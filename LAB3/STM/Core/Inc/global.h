/*
 * global.h
 *
 *  Created on: Oct 11, 2025
 *      Author: hieun
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

#define normal_red 6
#define normal_green 4
#define normal_yellow 2
int redvalue;
int greenvalue;
int yellowvalue;
int acceptrun; // accept run or stop


 void display7SEG(int counter, GPIO_TypeDef* pin[7], int p[7]);
 int led_buffer[5];
 void update7SEG(int index);
 void updateled_buffer();
 void runled();
 void turnonled();
 void updatevalue(int r,int g,int y);
 void updateled(int a,int b);
 void blinkred();
 void blinkgreen();
 void blinkyellow();
 void turnoffallled();


#endif /* INC_GLOBAL_H_ */
