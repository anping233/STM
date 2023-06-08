#include<stdio.h>
#include "include.h"

int main(int argc, char **argv) {
	driver_init();

    printf("Hello!\n");
    printf("usart!\n");


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
