#ifndef LED_SDL_H
#define LED_SDL_H

#include <stdint.h>

void led_init(void);
void led_clear(void);
void led_draw_pixel(int x, int y, uint8_t on);
void led_present(void);
void led_poll(void);
void hal_init(int w, int h);
void hal_draw_buffer(uint8_t *buf);
void hal_delay(int ms);

#endif
