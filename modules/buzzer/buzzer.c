#include "buzzer.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

void buzzer_init(uint pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (BUZZER_FREQUENCY * 4096));
    pwm_init(slice_num, &config, true);

    pwm_set_gpio_level(pin, 0); 
}

void buzzer_beep(uint pin, uint duration_ms) {
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_gpio_level(pin, 2048);  
    sleep_ms(duration_ms);
    pwm_set_gpio_level(pin, 0); 
}
