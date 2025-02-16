#include "led_control.h"

int count = 3;  

void init_leds(void) {
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
}

void blink_led_vermelho(void) {
    for (size_t i = 0; i < count; i++) {
        gpio_put(LED_VERMELHO, 1);
        buzzer_beep(BUZZER1_PIN, 200);  
        gpio_put(LED_VERMELHO, 0);
        sleep_ms(200);
    }
}

void blink_led_verde(void) {
    gpio_put(LED_VERDE, 1);
    sleep_ms(600);
    gpio_put(LED_VERDE, 0);
}
