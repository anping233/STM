#include<stdio.h>
#include "include.h"

int main(int argc, char **argv) {
    driver_init();

     while(1)
     {
         #if LED_TEST
            led_test();
         #endif

         #if LED1_TEST
            led1_test();
         #endif

         #if USART_TEST
            usart_test();
         #endif

         #if TIMER_TEST
            timer_test();
         #endif

         #if WWDG_TEST
            wwdg_test();
         #endif

         #if E2_24C256_TEST_EN
            uint8_t temp1 = 0;
            temp1 = test_24c256();
            printf("%d",temp1);

         #endif

         #if OLED_TEST
            oled_test();
         #endif

         #if KEY_TEST
            key_test();
         #endif

         #if TIM_CAP_IN_TEST
            tim_cap_in_test();
         #endif

         #if SPI_TEST
            spi_test();
         #endif

         #if W25Q128_TEST
            w25q128_test();
         #endif

         #if READ_STATUS_REGISTER
            read_status_register();
         #endif

         #if BLOCK_PROCTECT_TEST
            block_proctect_test();
         #endif

         #if RGB_TEST
            rgb_test();
         #endif
     }


    return 0;
}
