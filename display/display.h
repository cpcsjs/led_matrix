#pragma once
#include <stdint.h>

#define DISPLAY_WIDTH   192
#define DISPLAY_HEIGHT  8

void display_init(void);
void display_clear(void);
void display_set_pixel(int x, int y, uint8_t v);

void display_render(void);   // วาดลง back buffer
void display_flush(void);    // ส่ง front buffer ออก
void display_swap(void);     // สลับ buffer
