#pragma once

typedef enum {
    gpio_pin0,
    gpio_pin1,
    gpio_pin2,
    gpio_pin3,
    gpio_pin4,
    gpio_pin5,
    gpio_pin6,
    gpio_pin7,
    gpio_pin8,
    gpio_pin9,
    gpio_pin10,
    gpio_pin11,
    gpio_pin12,
    gpio_pin13,
    gpio_pin14,
    gpio_pin15,
}gpio_t;

static inline void gpio_set(GPIO_TypeDef *port, uint32_t pin) {
    periph_bit_band_set((uint32_t)&port->ODR, pin);
    return;
}

static inline void gpio_reset(GPIO_TypeDef *port, uint32_t pin) {
    periph_bit_band_clr((uint32_t)&port->ODR, pin);
    return;
}

static inline int gpio_get(GPIO_TypeDef *port, uint32_t pin) {
    return (int)periph_bit_band_get((uint32_t)&port->IDR, pin);
}

void led_gpio_init(void);
void usart_gpio_init(void);
void led1_gpio_init(void);

