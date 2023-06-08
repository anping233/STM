#pragma once
#define USART_PIN1 GPIO_Pin_9
#define USART_PIN2 GPIO_PIN_10
#define buff_max_len 200

void usart_init(void);
void usart_gpio(void);