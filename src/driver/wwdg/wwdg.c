#include"include.h"

#include"config.h"
#include"reg.h"


void wwdg_init(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_WWDGEN;

    WWDG->CFR &= ~(WWDG_CFR_WDGTB);
    WWDG->CFR |= (WWDG_CFR_WDGTB_Msk);/*8分频*/

    WWDG->CR &= ~CR_T_MASK;
    WWDG->CR |= COUNTER_VAL;/*计数器初始化值*/

    WWDG->CFR |= (WWDG_CFR_W_Msk & 0X50);/*设置窗口值*/

    WWDG->CR |= WWDG_CR_WDGA;/*使能窗口看门狗*/
    return;
}

void wwdg_feed(void)
{
    WWDG->CR = (WWDG_CR_T_Msk & WWDG->CR)|COUNTER_VAL;
    return;
}

#if WWDG_TEST
    void wwdg_test(void)
    {
        wwdg_feed();
        return;
    }
#endif