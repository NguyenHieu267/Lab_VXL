/*
 * timer.c
 *
 *  Created on: Sep 21, 2025
 *      Author: hieun
 */

#include"timer.h"

int counter = 0;
int time_flag = 0;

void settimer(int duration)
{
	counter = duration;
	time_flag = 0;
}

void runtime()
{
	counter --;
	if(counter<=0)
	{
		time_flag=1;
	}
}
