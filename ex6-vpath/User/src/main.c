#include "GPIO.h" 

int main()
{
	Clock_Init();
	GPIO_Init();
	
	PA->OUT |= (1 << 5);	
	
	while(1)
	{
		PA->OUT ^= (1 << 5);
		myDelay(500);
	}
	
}
