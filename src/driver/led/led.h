#include "include.h"

#define LED_TEST     0

void led(int x);
void led_toggle(void);

#if LED_TEST
    void led_test(void);
#endif