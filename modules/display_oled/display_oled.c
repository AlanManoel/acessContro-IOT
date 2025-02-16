#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "inc/ssd1306.h"
#include "hardware/i2c.h"

const uint I2C_SDA = 14;
const uint I2C_SCL = 15;

static struct render_area frame_area;
static uint8_t ssd[ssd1306_buffer_length];

void display_oled_init() {
    stdio_init_all();

    i2c_init(i2c1, ssd1306_i2c_clock * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init();

    frame_area.start_column = 0;
    frame_area.end_column   = ssd1306_width - 1;
    frame_area.start_page   = 0;
    frame_area.end_page     = ssd1306_n_pages - 1;

    calculate_render_area_buffer_length(&frame_area);
    
    memset(ssd, 0, ssd1306_buffer_length);
    render_on_display(ssd, &frame_area);
}

void display_message(const char *msg) {
    int display_height = ssd1306_n_pages * 8;
    int y = (display_height - 8) / 2;
    
    memset(ssd, 0, ssd1306_buffer_length);

    ssd1306_draw_string(ssd, 0, y, msg);

    render_on_display(ssd, &frame_area);
}
