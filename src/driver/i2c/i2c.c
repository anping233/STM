#include "include.h"

#include "cmd.h"
#include "config.h"

static inline void i2c_writebit(uint8_t bit) {
    sck_l();
    if(bit >= 1)
        gpio_set(I2C_SDA_GPIO_PORT, I2C_SDA_GPIO_PIN);
    else
        gpio_reset(I2C_SDA_GPIO_PORT, I2C_SDA_GPIO_PIN);
    sck_h();
    delay_us(I2C_DELAY);

    sck_l();
    sda_h();
    return;
}

static inline void sda_output(void) {
    gpio_mod_cfg(I2C_SDA_GPIO_PORT, I2C_SDA_GPIO_PIN, gpio_output);
    return;
}


static inline void sda_input(void) {
    gpio_mod_cfg(I2C_SDA_GPIO_PORT, I2C_SDA_GPIO_PIN, gpio_input);
    return;
}

static void i2c_ack(void)
{
    sda_l();
    sck_h();
    sck_l();

    sck_l();
    sda_h();
    return;
}

static void i2c_nack(void)
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

    sda_output();

    for(i = 0; i < 8; i++)
    {
        i2c_writebit(byte & (BYTE_HIGH_1_BIT >> i));
    }

    return;
}

uint8_t i2c_read_byte(uint8_t ack)
{
    uint8_t byte = 0;

    sda_input();

    for(size_t i = 0; i < 8; i++)
    {
        sck_h();
        byte <<= 1;
        byte |= gpio_get(I2C_SDA_GPIO_PORT, I2C_SDA_GPIO_PIN);
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


void i2c_send_data(uint8_t *data, size_t len)
{
    sda_output();
    for (size_t i = 0; i < len; i++)
    {
        i2c_send_byte(*data);
        data++;
    }

    return;
}

void i2c_recv_data(uint8_t *buffer, size_t len) {
    sda_input();
    for (size_t i = 0; i < len; i++)
    {
        if(i == 1)
        {
             buffer[i] = i2c_read_byte(0);
        }
        else
        {
             buffer[i] = i2c_read_byte(1);
        }

    }

    return;

}

