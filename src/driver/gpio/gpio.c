#include "include.h"


void gpio_init(void) {
    GPIO_InitTypeDef para;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

    para.GPIO_Pin = GPIO_Pin_13;
    para.GPIO_Mode = GPIO_Mode_OUT;
    para.GPIO_Speed = GPIO_High_Speed;
    para.GPIO_OType = GPIO_OType_PP;
    para.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(GPIOC, &para);
    return;
}