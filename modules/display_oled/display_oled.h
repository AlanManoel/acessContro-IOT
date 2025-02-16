// display_oled.h
#ifndef DISPLAY_OLED_H
#define DISPLAY_OLED_H

#ifdef __cplusplus
extern "C" {
#endif

void display_oled_init(void);
void display_message(const char *msg);

#ifdef __cplusplus
}
#endif

#endif // DISPLAY_OLED_H
