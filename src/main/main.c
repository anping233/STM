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
	 }
    return 0;
}
