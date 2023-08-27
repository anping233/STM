#pragma once


#include "gpio/gpio.h"
#include "usart/usart.h"
#include "delay/delay.h"
#include "rcc/rcc.h"
#include "led/led.h"
#include "i2c/i2c.h"
#include "myoled/myoled.h"
#include "timer/timer.h"
#include "key/key.h"
#include "spi/spi.h"
#include "rgb/rgb.h"

void driver_init(void);
