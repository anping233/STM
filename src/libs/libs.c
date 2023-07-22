#include "include.h"

void __aeabi_assert (const char *expr, const char *file, int line) {
    printf("expr:%s,file:%s,line:%d\r\n", expr, file, line);
    return;
}

uint8_t pow(uint8_t x, uint8_t y)
{
    uint8_t result = 1;

    while (y--)
    {
        result *= x;
    }

    return result;
}