/*
 * global.c
 *
 *  Created on: Oct 26, 2025
 *      Author: hieun
 */

#include "global.h"

void toggle_RED()
{
	HAL_GPIO_TogglePin(RED_GPIO_Port, RED_Pin);
}

void toggle_BLUE()
{
	HAL_GPIO_TogglePin(BLUE_GPIO_Port, BLUE_Pin);
}

void toggle_GREEN()
{
	HAL_GPIO_TogglePin(GREEN_GPIO_Port, GREEN_Pin);
}

void toggle_YELLOW()
{
	HAL_GPIO_TogglePin(YELLOW_GPIO_Port, YELLOW_Pin);
}

void toggle_WHITE()
{
	HAL_GPIO_TogglePin(WHITE_GPIO_Port, WHITE_Pin);
}


