#include "include.h"
void led(int x)
{
	if(x >= 1)
	{
		GPIOC->BSRR |= GPIO_BSRR_BS13;
	}
	else
	{
		GPIOC->BSRR |= GPIO_BSRR_BR13;
	}
	return;
}

