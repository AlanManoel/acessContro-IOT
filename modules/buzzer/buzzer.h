#ifndef BUZZER_H
#define BUZZER_H

#include "pico/stdlib.h"

#define BUZZER1_PIN 21  // Associado ao LED vermelho
#define BUZZER2_PIN 10  // Associado ao LED verde
#define BUZZER_FREQUENCY 2000  

void buzzer_init(uint pin);
void buzzer_beep(uint pin, uint duration_ms);

#endif
