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

void led_toggle(void)
{
    GPIOC->IDR ^= (1<<gpio_pin13);
    return;
}

void led1(uint8_t x)
{
    if(x >= 1)
    {
        GPIOA->BSRR |= GPIO_BSRR_BS5;
    }
    else
    {
        GPIOA->BSRR |= GPIO_BSRR_BR5;
    }
    return;
}

void led1_toggle(void)
{
    GPIOA->IDR ^= (1 << gpio_pin5);
}

#if LED_TEST
    void led_test(void)
    {
        led(0);
        led(1);
        delay_ms(300);
        led(0);
        led(1);
        return;
    }
#endif

#if LED1_TEST
    void led1_test(void)
    {
        led1(1);
        led1(0);
        delay_ms(300);
        led1(1);
        led(0);
    }
#endif