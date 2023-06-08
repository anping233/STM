#pragma once

#include "inc/stm32f4xx.h"
#include "inc/stm32f4xx_gpio.h"
#include "inc/stm32f4xx_rcc.h"

#define SRAM_BIT_BAND_REGION_BASE (0x40000000)
#define SRAM_BIT_BAND_ALIAS_BASE  (0x42000000)

#define bit_band_sram(addr, bit)   (SRAM_BIT_BAND_ALIAS_BASE + (addr - SRAM_BIT_BAND_REGION_BASE ) * 32 + bit * 4)
#define bit_band_peri(reg, bit)    (0x22000000 + (reg - 0x20000000 ) * 32 + bit * 4)
