#pragma once

#define KEY_TEST 0

void key_init(void);
void push_key1(uint8_t mode);
void push_key2(uint8_t mode);

#if KEY_TEST
void key_test(void);
#endif