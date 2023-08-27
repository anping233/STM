#include "include.h"

#include "config.h"

void rcc_init()
{
    RCC->CR |= RCC_CR_HSEON;/*startup HSE*/
    while((RCC->CR & RCC_CR_HSERDY) != RCC_CR_HSERDY);/*HSE ready*/

    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_HSE;
    while((RCC->CFGR & RCC_CFGR_SWS_HSE) != RCC_CFGR_SWS_HSE);/*choose HSE as clock sourse*/


    RCC->PLLCFGR = RCC_PLLCFGR_PLLSRC_HSE;/*HSE as PLL clock sourse*/

    RCC->PLLCFGR |= (PLL_M << RCC_PLLCFGR_PLLM_Pos);
    RCC->PLLCFGR |= (PLL_N << RCC_PLLCFGR_PLLN_Pos);
    RCC->PLLCFGR |= (PLL_P << RCC_PLLCFGR_PLLP_Pos);
    RCC->PLLCFGR |= (PLL_Q << RCC_PLLCFGR_PLLQ_Pos);

    RCC->CR |= RCC_CR_PLLON;/*startup PLL*/
    while((RCC->CR & RCC_CR_PLLRDY) != RCC_CR_PLLRDY);/*PLL ready*/

    /*设置分频系数*/
    RCC->CFGR &= ~RCC_CFGR_HPRE;
    RCC->CFGR |= RCC_CFGR_HPRE_1;
    RCC->CFGR &= ~RCC_CFGR_PPRE1;
    RCC->CFGR |= RCC_CFGR_PPRE1_1;
    RCC->CFGR &= RCC_CFGR_PPRE2;
    RCC->CFGR |= RCC_CFGR_PPRE2_1;

    // 配置Flash存储器访问延迟
    FLASH->ACR &= ~FLASH_ACR_LATENCY;  // 清除Flash存储器访问延迟位
    FLASH->ACR |= FLASH_ACR_LATENCY_3WS;  // 设置Flash存储器访问延迟为3个等待状态

    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while((RCC->CFGR & RCC_CFGR_SWS_PLL) != RCC_CFGR_SWS_PLL);/*choose PLL as clock sourse*/

    return;

}