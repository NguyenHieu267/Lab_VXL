/*
 * timer.c
 *
 *  Created on: Oct 10, 2025
 *      Author: hieun
 */


#include "timer.h"

int timer_counter=0;
int timer_flag=0;

void settimer(int duration)
{
	timer_counter=duration;
	timer_flag=0;
}

void runtime()
{
		timer_counter-=1;
	if(timer_counter<=0)
	{
		timer_flag=1;
	}
}
