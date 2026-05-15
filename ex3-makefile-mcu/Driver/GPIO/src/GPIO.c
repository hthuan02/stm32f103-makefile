//#include <stdio.h>
#include "GPIO.h"

void Clock_Init(void)
{
	RCC->CR |= (1 << 0);
}

void myDelay(uint32_t time)
{
	uint32_t i;
	while(time--)
	{
		for(i = 0; i < 5000; i++);
	}
}

void GPIO_Init(void)
{
	/* PC13 as INPUT pullup mode */
	RCC->AHB1 |= (1 << 2);
	PC->PU |= (1 << 26);
		
	/* PA5 as OUTPUT Push-Pull mode */
	RCC->AHB1 |= (1 << 0);
	PA->MODE |= (1 << 10); 
	PA->TYPE &= ~(1 << LED_GREEN);
	PA->SPEED |= (1 << 10);
} 
