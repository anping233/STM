#pragma once

#define moder_output_mask(pin)  (1 << ((pin) << 1))

#define get_moder_mask(pin)     (3 << (pin * 2))

#define set_moder_mask(pin, mod)     ((uint32_t)(mod) << (pin * 2))

#define SPI_SCK_AF5                     ((0x5UL << (20U)))
#define SPI_MOSI_AF5                     ((0x5UL << (28U)))
#define SPI_MISO_AF5                     ((0x5UL << (24U)))

#define TIM3_CH1_AF2                    ((0x2UL << (16U)))
#define TIM3_CH2_AF2                    ((0x2UL << (20U)))
#define TIM3_CH3_AF2                    (0x2UL)





