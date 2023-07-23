#include "include.h"


void driver_init(void) {
    led_init();
    led1_init();
    usart_init();
    init_24c256();
    oled_init();
    key_init();
    return;
}
