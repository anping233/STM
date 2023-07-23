#pragma once

#define OLED_TEST       0

void send_commend(uint8_t commend);
void send_data(uint8_t data);
void set_cursor(uint8_t seg,uint8_t col);
void oled_clear(void);
void oled_show_char(uint8_t seg, uint8_t col,char character);
void oled_init(void);
void oled_show_string(uint8_t seg, uint8_t col,char *string);
void oled_show_num(uint8_t seg, uint8_t col, uint32_t num, uint8_t len);
void oled_show_hex_num(uint8_t seg, uint8_t col, uint32_t num, uint8_t len);
void oled_show_bin_num(uint8_t seg, uint8_t col, uint8_t num, uint8_t len);
uint8_t oled_pow(uint8_t x, uint8_t y);

#if OLED_TEST
void oled_test(void);
#endif