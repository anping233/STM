#pragma once

typedef enum {
    ack_i2c = 0,
    nack_i2c = 1,
}i2c_ack_t;

void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_send_data(uint8_t *buffer, size_t len);
void i2c_send_byte(uint8_t byte);
uint8_t i2c_read_byte(uint8_t ack);

#define sda_h()     gpio_set(I2C_SDA_GPIO_PORT, I2C_SDA_GPIO_PIN)
#define sda_l()     gpio_reset(I2C_SDA_GPIO_PORT, I2C_SDA_GPIO_PIN)

#define sck_h()     gpio_set(I2C_SCL_GPIO_PORT, I2C_SCL_GPIO_PIN)
#define sck_l()     gpio_reset(I2C_SCL_GPIO_PORT, I2C_SCL_GPIO_PIN)
