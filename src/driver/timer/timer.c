#include "include.h"
#include "conf.h"

void timer_init(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;/*使能定时器的时钟*/

    TIM2->PSC = PRE_VAL;/*设置分频值*/
    TIM2->CR1 |= TIM_CR1_ARPE;/*自动重载*/
    TIM2->ARR = TMR_PERIOD;/*计数器周期*/

    TIM2->DIER |= TIM_DIER_UIE;/*启动定时器中断*/

    TIM2->CR1 |= TIM_CR1_CEN;

    return;
}

void timer_hander(void)
{
    if((TIM2->SR & TIM_SR_UIF) == TIM_SR_UIF)
    {
        led_toggle();
    }
    TIM2->SR &= ~(TIM_SR_UIF);/*清除中断标志位*/

    return;
}

#if TIMER_TEST
    void timer_test(void)
    {
        timer_hander();
        return;
    }
#endif

