#pragma once


#define PERIPH_BIT_BAND_ALIAS       (0x42000000)
#define PERIPH_BIT_BAND_REGION      (0x40000000)
#define periph_bit_band(addr, bit_number)     (PERIPH_BIT_BAND_ALIAS \
                    + ((uint32_t)(addr) - PERIPH_BIT_BAND_REGION) * 32 + (bit_number) * 4)

#define periph_bit_band_clr(addr, bit_number) ((*(__IO uint32_t *)periph_bit_band(addr, bit_number)) = 0)
#define periph_bit_band_set(addr, bit_number) ((*(__IO uint32_t *)periph_bit_band(addr, bit_number)) = 1)
#define periph_bit_band_get(addr, bit_number) (*(__IO uint32_t *)periph_bit_band(addr, bit_number))
