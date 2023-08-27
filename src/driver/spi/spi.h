#pragma once

#define SPI_TEST    0

void spi_init(void);
uint8_t spi_write_read_byte(uint8_t byte);

#if SPI_TEST
void spi_test(void);
#endif