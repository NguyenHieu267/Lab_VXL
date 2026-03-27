/*
 * input_processing.c
 *
 *  Created on: Oct 12, 2025
 *      Author: hieun
 */
#include "main.h"
#include "input_reading.h"
#include "global.h"
#define duration_auto_increase 50

int count = duration_auto_increase;
int count1 = duration_auto_increase;
 enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND} ;
 enum ButtonState buttonState[3] = {BUTTON_RELEASED,BUTTON_RELEASED,BUTTON_RELEASED};
int temp = 1;

int getvalue()
{
	 int k;
	if(led_buffer[0]==2) {k = redvalue; redvalue = 1;}
	else if(led_buffer[0] == 3) {k =greenvalue; greenvalue = 1;}
	else if(led_buffer[0] == 4) {k = yellowvalue; yellowvalue = 1;}
	return k;
}

 void fsm_for_input_processing0()
 {
	 switch(buttonState[0])
	 {
		 case BUTTON_RELEASED:
			 if(is_button_pressed(0)){
			 buttonState[0] = BUTTON_PRESSED;
			 //todo
			 	 	if(acceptrun==0)
			 	 	{
			 	 		if(led_buffer[0] == 2)
			 	 		{
			 	 			redvalue = temp;
			 	 		}
			 	 		else if(led_buffer[0] == 3)
			 	 		{
			 	 			greenvalue = temp;
			 	 		}
			 	 		else if(led_buffer[0] == 4)
			 	 		{
			 	 			yellowvalue = temp;
			 	 		}
			 	 	}
					led_buffer[0]++;
					if(led_buffer[0]==5) led_buffer[0]=1;
			 }
			 break;
		 case BUTTON_PRESSED:
			 if(!is_button_pressed(0)){
				 buttonState[0] = BUTTON_RELEASED;
				 if(led_buffer[0]==1)
				 {
					 updatevalue(normal_red, normal_green, normal_yellow);
					 acceptrun = 1;
				 }
				 else
				 {
					 temp = getvalue();
					 acceptrun = 0;
					 updateled(1, 1);
					 turnoffallled();
				 }
			 } else {
			 if(is_button_pressed_1s(0)){
				 	 buttonState[0] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				 	 //todo
					led_buffer[0]++;
					if(led_buffer[0]==5) led_buffer[0]=1;
					count = duration_auto_increase;
				 }
			 }
			 break;
		 case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			 if(!is_button_pressed(0)){
			 buttonState[0] = BUTTON_RELEASED;
			 }
			 else
			 {
				 count--;
				 if(count<=0)
				 {
					 count = duration_auto_increase;
					led_buffer[0]++;
					if(led_buffer[0]==5) led_buffer[0]=1;
				 }
			 }
			 break;
		 default:
			 break;
	 }
 }


 void fsm_for_input_processing2()
 {
	 switch(buttonState[2])
	 {
		 case BUTTON_RELEASED:
			 if(is_button_pressed(2)){
			 buttonState[2] = BUTTON_PRESSED;
			 acceptrun = 1;
			 turnonled();
			 }
			 break;
		 case BUTTON_PRESSED:
			 if(!is_button_pressed(2)){
			 buttonState[2] = BUTTON_RELEASED;
			 } else {
			 if(is_button_pressed_1s(2)){
				 	 buttonState[2] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				 }
			 }
			 break;
		 case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			 if(!is_button_pressed(2)){
			 buttonState[2] = BUTTON_RELEASED;
			 }
			 break;
	 }
 }


 void increase()
 {
	 if(led_buffer[0]==2)
	 {
		 redvalue++;
		 if(redvalue>=100) redvalue=1;
		 updateled(redvalue, redvalue);
	 }
	 else if(led_buffer[0]==3)
	 {
		 greenvalue++;
		 if(greenvalue>=100) greenvalue=1;
		 updateled(greenvalue,greenvalue);
	 }
	 else if(led_buffer[0]==4)
	 {
		 yellowvalue++;
		 if(yellowvalue>=100) yellowvalue=1;
		 updateled(yellowvalue, yellowvalue);
	 }
 }


 void fsm_for_input_processing1()
 {
	 switch(buttonState[1])
	 {
		 case BUTTON_RELEASED:
			 if(is_button_pressed(1)){
				 buttonState[1] = BUTTON_PRESSED;
				 //todo
				 increase();
			 }
			 break;
		 case BUTTON_PRESSED:
			 if(!is_button_pressed(1)){
			 buttonState[1] = BUTTON_RELEASED;
			 } else {
			 if(is_button_pressed_1s(1)){
				 	 buttonState[1] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				 	 //todo
					increase();
					count1 = duration_auto_increase;
				 }
			 }
			 break;
		 case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			 if(!is_button_pressed(1)){
			 buttonState[1] = BUTTON_RELEASED;
			 }
			 else
			 {
				 count1--;
				 if(count1<=0)
				 {
					count1 = duration_auto_increase;
					increase();
				 }
			 }
			 break;
	 }
 }
 void process()
 {
	 fsm_for_input_processing0();
	 fsm_for_input_processing1();
	 fsm_for_input_processing2();
 }
