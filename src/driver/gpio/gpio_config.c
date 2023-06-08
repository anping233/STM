#include    "include.h"
void gpio_init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    GPIOC->MODER   |= GPIO_MODER_MODER13_0;    /*引脚13设置为输出模式*/
    GPIOC->OTYPER  &= ~GPIO_OTYPER_OT13;    /*引脚13设置为推挽模式*/
    GPIOC->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED13;
    GPIOC->OSPEEDR |= GPIO_OSPEEDR_OSPEED13_0;    /*引脚13设置为中速模式*/
    GPIOC->PUPDR   |= GPIO_PUPDR_PUPD13_0;  /*引脚13设置为上拉模式*/

    return;
}
