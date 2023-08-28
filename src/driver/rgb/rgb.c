#include "include.h"

void rgb_init(void)
{

    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    tim_pwm_gpio_init();

    rgb_r_config();
    rgb_g_config();
    rgb_b_config();
    return;
}

void rgb_r_config(void)
{
    TIM3->CR1 &= ~(TIM_CR1_CEN);
    TIM3->ARR = 255;
    TIM3->PSC = 99;
    TIM3->CCMR1 |= ((0x6UL << (4U)));
    TIM3->EGR |= TIM_EGR_UG;
    TIM3->CCER = (TIM3->CCER &= ~(TIM_CCER_CC1P)) | (TIM_CCER_CC1E);
    TIM3->CR1 = (TIM_CR1_ARPE) | (TIM3->CR1 &= ~(TIM_CR1_DIR)) | (TIM_CR1_CEN);

    return;
}

void rgb_g_config(void)
{
    TIM3->CR1 &= ~(TIM_CR1_CEN);
    TIM3->ARR = 255;
    TIM3->PSC = 99;
    TIM3->CCMR1 |= (0x6UL << (12U));
    TIM3->EGR |= TIM_EGR_UG;
    TIM3->CCER = (TIM3->CCER &= ~(TIM_CCER_CC2P)) | (TIM_CCER_CC2E);
    TIM3->CR1 = (TIM_CR1_ARPE) | (TIM3->CR1 &= ~(TIM_CR1_DIR)) | (TIM_CR1_CEN);

    return;
}

void rgb_b_config(void)
{
    TIM3->CR1 &= ~(TIM_CR1_CEN);
    TIM3->ARR = 255;
    TIM3->PSC = 99;
    TIM3->CCMR2 |= ((0x6UL << (4U)));
    TIM3->EGR |= TIM_EGR_UG;
    TIM3->CCER = (TIM3->CCER &= ~(TIM_CCER_CC3P)) | (TIM_CCER_CC3E);
    TIM3->CR1 = (TIM_CR1_ARPE) | (TIM3->CR1 &= ~(TIM_CR1_DIR)) | (TIM_CR1_CEN);

    return;
}


#if RGB_TEST
void rgb_test(void)
{
    int data[3];

    scanf("%d",&data[0]);
    scanf("%d",&data[1]);
    scanf("%d",&data[2]);

    TIM3->CCR1 = data[0];
    TIM3->CCR2 = data[1];
    TIM3->CCR3 = data[2];
	
		printf("%d\n",data[0]);
		printf("%d\n",data[1]);
		printf("%d\n",data[2]);
    return;
}
#endif
