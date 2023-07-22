#pragma once

void i2c_writebit(uint8_t bit);
uint8_t i2c_readbit(void);
void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_ack(void);
void i2c_nack(void);
void i2c_send_byte(uint8_t byte);
uint8_t i2c_read_byte(uint8_t ack);
void i2c_send_data(uint8_t data, size_t len);
void sda_in(void);
void sda_out(void);

#define sda_h()     gpio_set(GPIOB, gpio_pin7)
#define sda_l()     gpio_reset(GPIOB, gpio_pin7)

#define sck_h()     gpio_set(GPIOB, gpio_pin6)
#define sck_l()     gpio_reset(GPIOB, gpio_pin6)
