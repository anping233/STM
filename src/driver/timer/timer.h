#pragma once

#define TIMER_TEST 0

void timer_init(void);
void timer_hander(void);

#if TIMER_TEST
    void timer_test(void);
#endif