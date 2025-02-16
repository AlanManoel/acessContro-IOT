#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "modules/led/led_control.h"
#include "modules/input_handler/input_handler.h"
#include "modules/display_oled/display_oled.h"
#include "modules/buzzer/buzzer.h"

int main() {
    stdio_init_all();

    init_leds();
    display_oled_init();
    buzzer_init(BUZZER1_PIN);
    buzzer_init(BUZZER2_PIN);
    
    char input_str[100];

    while (true) {
        display_message("Digite a senha");
        read_input(input_str, sizeof(input_str));
        
        if (strcmp(input_str, "admin") == 0) {
            display_message("Senha correta");
            blink_led_verde();
            sleep_ms(500);   
        } else {
            display_message("Senha incorreta!");
            blink_led_vermelho();
            sleep_ms(500);   
        }
    }
    
    return 0;
}
