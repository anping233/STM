#pragma once

#define WWDG_TEST 0

void wwdg_init(void);
void wwdg_feed(void);

#if WWDG_TEST
    void wwdg_test(void);
#endif