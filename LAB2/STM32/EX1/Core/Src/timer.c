/*
 * timer.c
 *
 *  Created on: Sep 21, 2025
 *      Author: hieun
 */

#include "timer.h"

int count = 0;
int time_flag = 0;

void settimer(int num)
{
	count = num;
	time_flag = 0;
}

void runtime()
{
	count --;
	if(count <= 0)
	{
		time_flag = 1;
	}
}
