#include "include.h"


void driver_init(void) {

    led_init();
    led1_init();
    timer_init();
    usart_init();
    init_24c256();
    oled_init();
    key_init();
    spi_init();
    rgb_init();
    dma_init(DMA1_Stream1);

    return;
}
