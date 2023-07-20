#include "include.h"

#include "cmd.h"
#include "config.h"

void i2c_writebit(uint8_t bit)
{
    if(bit >= 1)
    {
        gpio_set(GPIOB, gpio_pin7);
    }
    else
    {
        gpio_reset(GPIOB, gpio_pin7);
    }

    return;
}

uint8_t i2c_readbit(void)
{
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

    for(i = 0; i < 8; i++)
    {
        i2c_writebit(byte & (BYTE_HIGH_1_BIT >> i));
        sck_h();
        sck_l();
    }
    sck_h();
    sck_l();

    return;
}

uint8_t i2c_read_byte(uint8_t ack)
{
    uint8_t byte = 0;

    for(size_t i = 0; i < 8; i++)
    {
        sck_h();
        byte <<= 1;
        byte |= i2c_readbit();
        sck_l();
        delay_us(20);
    }

    sck_h();
    sck_l();

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



void i2c_send_data(uint8_t *data, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        i2c_send_byte(*data);
        data++;
    }

    return;
}


