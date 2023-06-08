#include "include.h"

int main(int argc, char **argv) {
		rcc_init();
		gpio_init();
		driver_init();
	#if 0
    while (1) {
      GPIO_SetBits(GPIOC, GPIO_Pin_13);
      delay_ms(1000);
      GPIO_ResetBits(GPIOC, GPIO_Pin_13);
      delay_ms(1000);
    }
    GPIOA->AFR[1];
 #endif
	 while(1)
	 {
		 led(0);
		 led(1);
		 delay_ms(300);
		 led(0);
		 led(1);
		 delay_ms(300);
	 }
    return 0;
}
