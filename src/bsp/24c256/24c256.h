#pragma once

#define TEST_24C256 0

void byte_write(uint8_t data, uint16_t addr);
void page_write(uint8_t data, size_t len);
uint8_t current_addr_read(void);
uint8_t randow_read(uint16_t addr);
void seq_read(void);
void init_24c256(void);

#if TEST_24C256
    uint8_t test_24c256(void);
#endif