#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <limits.h>


#define KHZ     (1000)
#define MHZ     (KHZ * KHZ)

#define nbits(n) ((uint32_t)((1ull << (n)) - 1))

#define BITS_PER_BYTE   (8)

#define sizeof_array(array)         (sizeof(array) / sizeof(array[0]))
