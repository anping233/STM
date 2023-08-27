#pragma once

#define E2_24C256_TEST_EN 0

void byte_write(uint8_t *data, uint16_t addr);
void page_write(uint16_t addr, uint8_t *data, size_t len);
uint8_t current_addr_read(void);
uint8_t randow_read(uint16_t addr);
void seq_read(uint8_t *buffer, uint8_t len);
void init_24c256(void);

#if E2_24C256_TEST_EN
    uint8_t test_24c256(void);
#endif
