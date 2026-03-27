/*
 * global.c
 *
 *  Created on: Oct 11, 2025
 *      Author: hieun
 */

#include "global.h"

GPIO_TypeDef* SEG_GPIO[7] = {pin_a_GPIO_Port,pin_b_GPIO_Port,
		  pin_c_GPIO_Port,pin_d_GPIO_Port,pin_e_GPIO_Port,
		  pin_f_GPIO_Port,pin_g_GPIO_Port};

 int SEG_pin[7] = {pin_a_Pin,pin_b_Pin,pin_c_Pin,
		  pin_d_Pin,pin_e_Pin,pin_f_Pin,pin_g_Pin};
int acceptrun = 1;

void blinkred()
 {
		HAL_GPIO_WritePin(green_up_GPIO_Port, green_up_Pin, RESET);
		HAL_GPIO_WritePin(green_left_GPIO_Port, green_left_Pin, RESET);
		HAL_GPIO_WritePin(yellow_up_GPIO_Port, yellow_up_Pin, RESET);
		HAL_GPIO_WritePin(yellow_left_GPIO_Port, yellow_left_Pin, RESET);

		HAL_GPIO_TogglePin(red_up_GPIO_Port, red_up_Pin);
		HAL_GPIO_TogglePin(red_left_GPIO_Port, red_left_Pin);
 }
 void blinkgreen()
 {
		HAL_GPIO_WritePin(red_up_GPIO_Port, red_up_Pin, RESET);
		HAL_GPIO_WritePin(red_left_GPIO_Port, red_left_Pin, RESET);
		HAL_GPIO_WritePin(yellow_up_GPIO_Port, yellow_up_Pin, RESET);
		HAL_GPIO_WritePin(yellow_left_GPIO_Port, yellow_left_Pin, RESET);

		HAL_GPIO_TogglePin(green_up_GPIO_Port, green_up_Pin);
		HAL_GPIO_TogglePin(green_left_GPIO_Port, green_left_Pin);
 }
 void blinkyellow()
 {
		HAL_GPIO_WritePin(green_up_GPIO_Port, green_up_Pin, RESET);
		HAL_GPIO_WritePin(green_left_GPIO_Port, green_left_Pin, RESET);
		HAL_GPIO_WritePin(red_up_GPIO_Port, red_up_Pin, RESET);
		HAL_GPIO_WritePin(red_left_GPIO_Port, red_left_Pin, RESET);

		HAL_GPIO_TogglePin(yellow_up_GPIO_Port, yellow_up_Pin);
		HAL_GPIO_TogglePin(yellow_left_GPIO_Port, yellow_left_Pin);
 }


 void display7SEG(int counter, GPIO_TypeDef* pin[7], int p[7])
 {
 	  switch (counter){
 	  case 0:
 		  HAL_GPIO_WritePin(pin[0], p[0], RESET);
 		  HAL_GPIO_WritePin(pin[1], p[1], RESET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], RESET);
 		  HAL_GPIO_WritePin(pin[4], p[4], RESET);
 		  HAL_GPIO_WritePin(pin[5], p[5], RESET);
 		  HAL_GPIO_WritePin(pin[6], p[6], SET);
 		  break;
 	  case 1:
 		  HAL_GPIO_WritePin(pin[0], p[0], SET);
 		  HAL_GPIO_WritePin(pin[1], p[1], RESET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], SET);
 		  HAL_GPIO_WritePin(pin[4], p[4], SET);
 		  HAL_GPIO_WritePin(pin[5], p[5], SET);
 		  HAL_GPIO_WritePin(pin[6], p[6], SET);
 		  break;
 	  case 2:
 		  HAL_GPIO_WritePin(pin[0], p[0], RESET);
 		  HAL_GPIO_WritePin(pin[1], p[1], RESET);
 		  HAL_GPIO_WritePin(pin[2], p[2], SET);
 		  HAL_GPIO_WritePin(pin[3], p[3], RESET);
 		  HAL_GPIO_WritePin(pin[4], p[4], RESET);
 		  HAL_GPIO_WritePin(pin[5], p[5], SET);
 		  HAL_GPIO_WritePin(pin[6], p[6], RESET);
 		  break;
 	  case 3:
 		  HAL_GPIO_WritePin(pin[0], p[0], RESET);
 		  HAL_GPIO_WritePin(pin[1], p[1], RESET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], RESET);
 		  HAL_GPIO_WritePin(pin[4], p[4], SET);
 		  HAL_GPIO_WritePin(pin[5], p[5], SET);
 		  HAL_GPIO_WritePin(pin[6], p[6], RESET);
 		  break;
 	  case 4:
 		  HAL_GPIO_WritePin(pin[0], p[0], SET);
 		  HAL_GPIO_WritePin(pin[1], p[1], RESET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], SET);
 		  HAL_GPIO_WritePin(pin[4], p[4], SET);
 		  HAL_GPIO_WritePin(pin[5], p[5], RESET);
 		  HAL_GPIO_WritePin(pin[6], p[6], RESET);
 		  break;
 	  case 5:
 		  HAL_GPIO_WritePin(pin[0], p[0], RESET);
 		  HAL_GPIO_WritePin(pin[1], p[1], SET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], RESET);
 		  HAL_GPIO_WritePin(pin[4], p[4], SET);
 		  HAL_GPIO_WritePin(pin[5], p[5], RESET);
 		  HAL_GPIO_WritePin(pin[6], p[6], RESET);
 		  break;
 	  case 6:
 		  HAL_GPIO_WritePin(pin[0], p[0], RESET);
 		  HAL_GPIO_WritePin(pin[1], p[1], SET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], RESET);
 		  HAL_GPIO_WritePin(pin[4], p[4], RESET);
 		  HAL_GPIO_WritePin(pin[5], p[5], RESET);
 		  HAL_GPIO_WritePin(pin[6], p[6], RESET);
 		  break;
 	  case 7:
 		  HAL_GPIO_WritePin(pin[0], p[0], RESET);
 		  HAL_GPIO_WritePin(pin[1], p[1], RESET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], SET);
 		  HAL_GPIO_WritePin(pin[4], p[4], SET);
 		  HAL_GPIO_WritePin(pin[5], p[5], SET);
 		  HAL_GPIO_WritePin(pin[6], p[6], SET);
 		  break;
 	  case 8:
 		  HAL_GPIO_WritePin(pin[0], p[0], RESET);
 		  HAL_GPIO_WritePin(pin[1], p[1], RESET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], RESET);
 		  HAL_GPIO_WritePin(pin[4], p[4], RESET);
 		  HAL_GPIO_WritePin(pin[5], p[5], RESET);
 		  HAL_GPIO_WritePin(pin[6], p[6], RESET);
 		  break;
 	  case 9:
 		  HAL_GPIO_WritePin(pin[0], p[0], RESET);
 		  HAL_GPIO_WritePin(pin[1], p[1], RESET);
 		  HAL_GPIO_WritePin(pin[2], p[2], RESET);
 		  HAL_GPIO_WritePin(pin[3], p[3], RESET);
 		  HAL_GPIO_WritePin(pin[4], p[4], SET);
 		  HAL_GPIO_WritePin(pin[5], p[5], RESET);
 		  HAL_GPIO_WritePin(pin[6], p[6], RESET);
 		  break;
 	  default:
 		  HAL_GPIO_WritePin(pin[0], p[0], SET);
 		  HAL_GPIO_WritePin(pin[1], p[1], SET);
 		  HAL_GPIO_WritePin(pin[2], p[2], SET);
 		  HAL_GPIO_WritePin(pin[3], p[3], SET);
 		  HAL_GPIO_WritePin(pin[4], p[4], SET);
 		  HAL_GPIO_WritePin(pin[5], p[5], SET);
 		  HAL_GPIO_WritePin(pin[6], p[6], SET);
 		  break;
 	  }
 }

 int led_buffer[5] = {1,0,6,0,4};

 void update7SEG(int index)
 {
	 display7SEG(10, SEG_GPIO, SEG_pin);
	  switch(index) {
	  		  case 0:
	  			  HAL_GPIO_WritePin(stage_GPIO_Port, stage_Pin, RESET);
	  			  HAL_GPIO_WritePin(up_c_GPIO_Port, up_c_Pin, SET);
	  			  HAL_GPIO_WritePin(up_dv_GPIO_Port, up_dv_Pin, SET);
	  			  HAL_GPIO_WritePin(left_c_GPIO_Port, left_c_Pin, SET);
	  			  HAL_GPIO_WritePin(left_dv_GPIO_Port, left_dv_Pin, SET);
	  			  break;
	  		  case 1:
	  			  HAL_GPIO_WritePin(stage_GPIO_Port, stage_Pin, SET);
	  			  HAL_GPIO_WritePin(up_c_GPIO_Port, up_c_Pin, RESET);
	  			  HAL_GPIO_WritePin(up_dv_GPIO_Port, up_dv_Pin, SET);
	  			  HAL_GPIO_WritePin(left_c_GPIO_Port, left_c_Pin, SET);
	  			  HAL_GPIO_WritePin(left_dv_GPIO_Port, left_dv_Pin, SET);
	  			  break;
	  		  case 2:
	  			  HAL_GPIO_WritePin(stage_GPIO_Port, stage_Pin, SET);
	  			  HAL_GPIO_WritePin(up_c_GPIO_Port, up_c_Pin, SET);
	  			  HAL_GPIO_WritePin(up_dv_GPIO_Port, up_dv_Pin, RESET);
	  			  HAL_GPIO_WritePin(left_c_GPIO_Port, left_c_Pin, SET);
	  			  HAL_GPIO_WritePin(left_dv_GPIO_Port, left_dv_Pin, SET);
	  			  break;
	  		  case 3:
	  			  HAL_GPIO_WritePin(stage_GPIO_Port, stage_Pin, SET);
	  			  HAL_GPIO_WritePin(up_c_GPIO_Port, up_c_Pin, SET);
	  			  HAL_GPIO_WritePin(up_dv_GPIO_Port, up_dv_Pin, SET);
	  			  HAL_GPIO_WritePin(left_c_GPIO_Port, left_c_Pin, RESET);
	  			  HAL_GPIO_WritePin(left_dv_GPIO_Port, left_dv_Pin, SET);
	  			  break;
	  		  case 4:
	  			  HAL_GPIO_WritePin(stage_GPIO_Port, stage_Pin, SET);
	  			  HAL_GPIO_WritePin(up_c_GPIO_Port, up_c_Pin, SET);
	  			  HAL_GPIO_WritePin(up_dv_GPIO_Port, up_dv_Pin, SET);
	  			  HAL_GPIO_WritePin(left_c_GPIO_Port, left_c_Pin, SET);
	  			  HAL_GPIO_WritePin(left_dv_GPIO_Port, left_dv_Pin, RESET);
	  			  break;
	  		  default:
	  			  break;
	  		  }
	  display7SEG(led_buffer[index], SEG_GPIO, SEG_pin);
 }
 int redvalue = normal_red;
 int greenvalue = normal_green;
 int yellowvalue = normal_yellow;
int up = normal_red;
int stageup = 0;
int left = normal_green;
int stageleft = 1;

void updatevalue(int r,int g,int y)
{
	redvalue = r;
	greenvalue = g;
	yellowvalue = y;
}

int revalue(int stage)
{
	if(stage == 0) return redvalue;
	else if(stage == 1) return greenvalue;
	else if(stage == 2) return yellowvalue;
	return 0;
}
void turnoffallled()
{
	HAL_GPIO_WritePin(red_up_GPIO_Port, red_up_Pin, RESET);
	HAL_GPIO_WritePin(red_left_GPIO_Port, red_left_Pin, RESET);
	HAL_GPIO_WritePin(green_up_GPIO_Port, green_up_Pin, RESET);
	HAL_GPIO_WritePin(green_left_GPIO_Port, green_left_Pin, RESET);
	HAL_GPIO_WritePin(yellow_up_GPIO_Port, yellow_up_Pin, RESET);
	HAL_GPIO_WritePin(yellow_left_GPIO_Port, yellow_left_Pin, RESET);
}

void turnonled()
{

	turnoffallled();
	if(stageup == 0)
	{
		HAL_GPIO_WritePin(red_up_GPIO_Port, red_up_Pin, SET);
	}
	else if(stageup == 1)
	{
		HAL_GPIO_WritePin(green_up_GPIO_Port, green_up_Pin, SET);
	}
	else if(stageup == 2)
	{
		HAL_GPIO_WritePin(yellow_up_GPIO_Port, yellow_up_Pin, SET);
	}

	if(stageleft == 0)
	{
		HAL_GPIO_WritePin(red_left_GPIO_Port, red_left_Pin, SET);
	}
	else if(stageleft == 1)
	{
		HAL_GPIO_WritePin(green_left_GPIO_Port, green_left_Pin, SET);
	}
	else if(stageleft == 2)
	{
		HAL_GPIO_WritePin(yellow_left_GPIO_Port, yellow_left_Pin, SET);
	}

}

void updateled(int a,int b)
{
	led_buffer[1] = a/10;
	led_buffer[2] = a%10;
	led_buffer[3] = b/10;
	led_buffer[4] = b%10;
}
 void runled()
 {
	 if(acceptrun==1)
	 {
		 if(left<=0)
		 {
			 stageleft++;
			 if(stageleft>2) stageleft=0;
			 left=revalue(stageleft);
			 turnonled();
		 }
		 if(up<=0)
		 {
			 stageup++;
			 if(stageup>2) stageup=0;
			 up=revalue(stageup);
			 turnonled();
		 }
		 updateled(up,left);
		 up--;
		 left--;
	 }
 }

