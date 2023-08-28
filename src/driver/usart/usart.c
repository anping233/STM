#include "include.h"

#include "config.h"
#include"reg.h"


FILE __stdout;
FILE __stdin;


int fputc(int ch, FILE *f)
{
  /* Your implementation of fputc(). */
  while (!(USART1->SR & USART_SR_TXE));/*缓冲区为空*/
  USART1->DR = (ch & USART_DR_MASK);
  return ch;
}

int fgetc( FILE *f)
{
        int ret = 0;

    while (!(USART1->SR & USART_SR_RXNE));/*数据准备好读取*/
        ret = (USART1->DR & 0xff);
        fputc(ret & 0xff, NULL);
    return ret;
}

void usart_init(void)
{
    uint8_t buffer[BUFFER_SIZE];
    uint32_t temp;
    uint8_t OVER8 = 0;
    RCC_ClocksTypeDef RCC_Clocks = {0};

    RCC_GetClocksFreq(&RCC_Clocks);
    temp = RCC_Clocks.PCLK2_Frequency  / BAUDRATE;

    usart_gpio_init();

    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;/*使能串口1的时钟*/

    USART1->CR1 &= ~(USART_CR1_UE); /*usart disable*/
    USART1->CR1 &= ~(USART_CR1_OVER8);/*oversampling by 16*/
    USART1->CR1 |= USART_CR1_M; /*word lenght 8 bit*/
    USART1->CR1 |= (USART_CR1_PCE); /*使能校验*/
    USART1->CR1 &= ~(USART_CR1_PS); /*偶校验*/
    USART1->CR2 &= ~(USART_CR2_STOP);/*1 stop bit*/
    USART1->BRR &= ~(USART_BRR_MSK);/*清零原始的设置*/
    USART1->BRR |= temp;/* USARTDIV */
    USART1->CR1 |= (USART_CR1_TE);/* Transmitter enable*/
    USART1->CR1 |= (USART_CR1_RE);/*Receiver enable*/
    USART1->CR1 |= (USART_CR1_UE); /*usart enable*/
    USART1->CR3 |= (USART_CR3_DMAR);
    dma_config(DMA1_Stream1, (uint32_t)buffer, (uint32_t)&USART1->DR, BUFFER_SIZE);

}

#if USART_TEST
    void usart_test(void)
    {
        printf("hello!");
        return;
    }
#endif


