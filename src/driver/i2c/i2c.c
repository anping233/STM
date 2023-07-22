#include "include.h"

#include "cmd.h"
#include "config.h"

void sda_in(void)
{
    GPIOB->MODER &= ~(GPIO_MODER_MODE7);
    return;
}

void sda_out(void)
{
    GPIOB->MODER &= ~(GPIO_MODER_MODE7_Msk);
    GPIOB->MODER |= (GPIO_MODER_MODE7_0);
    return;
}

void i2c_writebit(uint8_t bit)
{
    sda_out();
    if(bit >= 1)
    {
        sck_l();
        gpio_set(GPIOB, gpio_pin7);
        sck_h();
    }
    else
    {
        sck_l();
        gpio_reset(GPIOB, gpio_pin7);
        sck_h();
    }

    sck_l();
    sda_h();
    return;
}

uint8_t i2c_readbit(void)
{
    sda_in();
    if(gpio_get(GPIOB, gpio_pin7))
        return 1;
    else
        return 0;
}

void i2c_init(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;/*使能i2c1时钟*/

    gpio_init_24c256();

    sda_h();
    sck_h();
    return;
}

void i2c_start(void)
{
    sck_h();
    sda_h();
    sda_l();
    sck_l();

    return;
}

void i2c_stop(void)
{

    sda_l();
    sck_h();
    sda_h();

    return;
}

void i2c_ack(void)
{
    sda_l();
    sck_h();
    sck_l();

    sck_l();
    sda_h();
    return;
}

void i2c_nack(void)
{
    sda_h();
    sck_h();
    sck_l();

    sck_l();
    sda_h();
    return;
}

void i2c_send_byte(uint8_t byte)
{
    uint8_t i;

    sda_out();

    for(i = 0; i < 8; i++)
    {
        i2c_writebit(byte & (BYTE_HIGH_1_BIT >> i));

    }

    return;
}

uint8_t i2c_read_byte(uint8_t ack)
{
    uint8_t byte = 0;

    sda_in();

    for(size_t i = 0; i < 8; i++)
    {
        sck_h();
        byte <<= 1;
        byte |= i2c_readbit();
        sck_l();
        delay_us(20);
    }

    sck_l();
    sda_h();

    if(ack)
    {
        i2c_ack();
    }
    else
    {
        i2c_nack();
    }

    return byte;
}



void i2c_send_data(uint8_t data, size_t len)
{
    sda_out();
    for (size_t i = 0; i < len; i++)
    {
        i2c_send_byte(data);
        data++;
    }

    return;
}


