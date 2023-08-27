#pragma once

#define RGB_TEST    1

void rgb_init(void);
void rgb_r_config(void);
void rgb_g_config(void);
void rgb_b_config(void);

#if RGB_TEST
    void rgb_test(void);
#endif