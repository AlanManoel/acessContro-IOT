#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include "pico/stdlib.h"
#include "modules/buzzer/buzzer.h"

#define LED_VERMELHO 13
#define LED_VERDE 11

void init_leds(void);
void blink_led_vermelho(void);
void blink_led_verde(void);

#endif
