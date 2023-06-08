#include "include.h"
void delay_ms(size_t ms)
{
    for(int i = 0; i < 1000; i++) {
        __asm
        (
            "NOP"
        );
    }

}