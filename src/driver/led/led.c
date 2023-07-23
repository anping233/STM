#include "include.h"
void led(int x)
{
	if(x >= 1)
	{
        gpio_set(GPIOC, gpio_pin13);
	}
	else
	{
		gpio_reset(GPIOC, gpio_pin13);
	}
	return;
}

void led_init(void)
{
    led_gpio_init();
    return;
}

void led_toggle(void)
{
    GPIOC->ODR ^= (1<<gpio_pin13);
    return;
}

void led1(uint8_t x)
{
    if(x >= 1)
    {
        gpio_set(GPIOA, gpio_pin5);
    }
    else
    {
        gpio_reset(GPIOA, gpio_pin5);
    }
    return;
}

void led1_toggle(void)
{
    GPIOA->ODR ^= (1 << gpio_pin5);
}

void led1_init(void)
{
    led1_gpio_init();
    return;
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