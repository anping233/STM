#include "include.h"

#include "config.h"


int fputc(int ch, FILE *f)
{
  /* Your implementation of fputc(). */
  while (!(USART1->SR & USART_SR_TXE));/*缓冲区为空*/
  USART1->DR = (ch & 0xff);
  return ch;
}

void usart_init(void)
{
    uint32_t temp;
    uint8_t OVER8 = 0;
    RCC_ClocksTypeDef RCC_Clocks = {0};

    RCC_GetClocksFreq(&RCC_Clocks);
    temp = RCC_Clocks.PCLK2_Frequency  / BAUDRATE;

    usart_gpio_init();

    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;/*使能串口1的时钟*/

    USART1->CR1 &= ~(USART_CR1_UE); /*usart disable*/
    USART1->CR1 &= ~(USART_CR1_OVER8);/*oversampling by 16*/
    USART1->CR1 &= ~(USART_CR1_M); /*word lenght 8 bit*/
    USART1->CR1 |= (USART_CR1_PCE); /*使能校验*/
    USART1->CR1 &= ~(USART_CR1_PS); /*偶校验*/
    USART1->CR2 &= ~(USART_CR2_STOP);/*1 stop bit*/
    USART1->CR3 |= USART_CR3_RTSE | USART_CR3_CTSE;/*使能RTS,CTS控制流*/
    USART1->BRR &= ~(0XFFFF);/*清零原始的设置*/
    USART1->BRR |= temp;/* USARTDIV */
    USART1->CR1 |= (USART_CR1_TE);/* Transmitter enable*/
    USART1->CR1 |= (USART_CR1_RE);/*Receiver enable*/
    USART1->CR1 |= (USART_CR1_UE); /*usart enable*/
}
