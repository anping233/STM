#include "include.h"

void key_init(void)
{
    key_gpio_init();

    return;
}

void push_key1(uint8_t mode)
{
    static uint8_t key_up = 1;

    if(mode == 1)
    key_up = 1;

    if(key_up && gpio_get(GPIOA, gpio_pin0))
    {
        key_up = 0;
        delay_ms(10);
        led1_toggle();
    }
    return;
}

void push_key2(uint8_t mode)
{
    static uint8_t key_up = 1;

    if(mode == 1)
    key_up = 1;

    if(key_up && gpio_get(GPIOB, gpio_pin2))
    {
        key_up = 0;
        delay_ms(10);
        led1_toggle();
    }
    return;
}

#if KEY_TEST
void key_test(void)
{
    push_key1(1);

    return;
}
#endif

