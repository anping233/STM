#include "include.h"

void spi_init(void)
{
    spi_gpio_init();

    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
    SPI1->CR1 &= ~(SPI_CR1_DFF);//设置8位数据格式
    SPI1->CR1 &= ~(SPI_CR1_RXONLY);//设置全双工模式
    SPI1->CR1 |= (SPI_CR1_SSM);//软件片选控制
    SPI1->CR1 |= (SPI_CR1_SSI);//做主机
    SPI1->CR1 &= ~(SPI_CR1_LSBFIRST);//MSB先传输
    SPI1->CR1 &= ~(SPI_CR1_BR_Msk);
    SPI1->CR1 |= (SPI_CR1_BR_Msk);//256分频
    SPI1->CR1 |= (SPI_CR1_MSTR);//主机模式
    SPI1->CR1 &= ~(SPI_CR1_CPOL);//空闲状态低电平
    SPI1->CR1 &= ~(SPI_CR1_CPHA);//偶数边沿捕获
    SPI1->CR1 |= (SPI_CR1_SPE);//使能SPI1
    return;
}

uint8_t spi_write_read_byte(uint8_t byte)
{
    uint8_t ret = 0;

    delay_us(10);
    while ((SPI1->SR & SPI_SR_TXE) == 0);    //等待发送缓冲区为空
    SPI1->DR = byte;    //发送一个字节
    while((SPI1->SR & SPI_SR_RXNE) == 0);    //等待接受完一个字节
    ret = (uint8_t)SPI1->DR;
    delay_us(10);
    return ret;    //返回接受的字节
}

#if SPI_TEST
void spi_test(void)
{
    uint8_t tmp = 0;
    tmp = spi_write_read_byte(0x34);
    printf("%x",tmp);
    return;
}
#endif