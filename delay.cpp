/*
 * Author: Klusjesman
 */

#include "delay.h"
#include <util/delay.h>

void delay_ms(uint16_t count) 
{
	while(count--) 
	{
		_delay_ms(1);
	}
}

void delay_us(uint16_t count) 
{
	while(count--) 
	{
		_delay_us(1);
	}
}
