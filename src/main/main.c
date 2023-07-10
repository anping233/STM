#include<stdio.h>
#include "include.h"

int main(int argc, char **argv) {
	driver_init();

	 while(1)
	 {
		 #if LED_TEST
            led_test();
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
	 }
    return 0;
}
