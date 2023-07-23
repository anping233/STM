#include "include.h"

void __aeabi_assert (const char *expr, const char *file, int line) {
    printf("expr:%s,file:%s,line:%d\r\n", expr, file, line);
    return;
}

