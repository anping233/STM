#include "include.h"
void delay_ms(size_t ms)
{// TODO: 将该函数改为基于systick实现并放入systick.c中
    for(int i = 0; i < 1000; i++) {
        for (size_t j = 0; j < ms; j++) {
            __asm
            (
                "NOP"
            );
        }
    }
    return;
}

void delay_us(size_t us)
{// TODO: 将该函数改为基于systick实现并放入systick.c中
    for(int i = 0; i < 10; i++) {
        for (size_t j = 0; j < us; j++) {
            __asm
            (
                "NOP"
            );
        }
    }
    return;
}
