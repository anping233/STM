#pragma once

#define USART_TEST 0

void usart_init(void);

#if USART_TEST
    void usart_test(void);
#endif