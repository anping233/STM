#include "include.h"


void driver_init(void) {
    gpio_init();
    usart_init();
    //SysTick_Config();
    return;
}
