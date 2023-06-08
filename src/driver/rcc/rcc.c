#include "include.h"

#include "config.h"

uint8_t rcc_init()
{
	RCC->CR |= RCC_CR_HSEON;/*startup HSE*/
	while(!(RCC->CR & RCC_CR_HSERDY));/*HSE ready*/

	RCC->CFGR &= ~RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SW_HSE;
	while(!(RCC->CFGR & RCC_CFGR_SWS_HSE));/*choose HSE as clock sourse*/


	RCC->PLLCFGR = RCC_PLLCFGR_PLLSRC_HSE;/*HSE as PLL clock sourse*/

	RCC->PLLCFGR |= (PLL_M << RCC_PLLCFGR_PLLM_Pos);
	RCC->PLLCFGR |= (PLL_N << RCC_PLLCFGR_PLLN_Pos);
	RCC->PLLCFGR |= (PLL_P << RCC_PLLCFGR_PLLP_Pos);
	RCC->PLLCFGR |= (PLL_Q << RCC_PLLCFGR_PLLQ_Pos);

	RCC->CR |= RCC_CR_PLLON;/*startup PLL*/
	while(!(RCC->CR & RCC_CR_PLLRDY));/*PLL ready*/

	RCC->CR |= RCC_CR_PLLI2SON;
	while(!(RCC->CR & RCC_CR_PLLI2SRDY));

	RCC->CFGR |= RCC_CFGR_MCO1_0;
	RCC->CFGR |= RCC_CFGR_MCO1PRE_0;
	RCC->CFGR |= RCC_CFGR_MCO2_0;
	RCC->CFGR |= RCC_CFGR_MCO2PRE_0;

	RCC->CFGR |= RCC_CFGR_I2SSRC;

	RCC->CFGR &= ~RCC_CFGR_HPRE;
	RCC->CFGR |= RCC_CFGR_HPRE_DIV2;
	RCC->CFGR &= ~RCC_CFGR_PPRE1;
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
	RCC->CFGR &= RCC_CFGR_PPRE2;
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;
	
	while(!(RCC->CR & RCC_CR_PLLRDY));/*wait for clock steady */

	RCC->CFGR &= ~RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SWS_PLL;
	while(!(RCC->CFGR & RCC_CFGR_SWS_PLL));/*choose PLL as clock sourse*/


	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;/*config GPIOC clock*/


	return 1;

}