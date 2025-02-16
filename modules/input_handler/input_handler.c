#include "input_handler.h"
#include "pico/stdlib.h"
#include <stdio.h>

void read_input(char *input_str, int size) {
    int buffer = 0;
    int ch;

    // Lê caracteres individualmente com timeout
    while (true) {
        ch = getchar_timeout_us(100000);  // 100 ms de timeout
        if (ch == PICO_ERROR_TIMEOUT) {
            // Se houver caracteres no buffer, consideramos que a entrada terminou
            if (buffer > 0)
                break;
        } else if (ch == '\n') {
            break;
        } else if (ch != EOF) {
            if (buffer < size - 1) {
                input_str[buffer++] = (char) ch;
            }
        }
    }
    input_str[buffer] = '\0';
}
