#include "include.h"

#define LED_TEST     0
#define LED1_TEST    0

void led(int x);
void led_toggle(void);
void led1(uint8_t x);
void led1_toggle(void);

#if LED_TEST
    void led_test(void);
#endif

#if LED1_TEST
    void led1_test(void);
#endif