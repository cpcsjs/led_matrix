#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>

#define DISPLAY_WIDTH   192
#define DISPLAY_HEIGHT  8

void display_init(void);
void display_clear(void);
void display_set_pixel(int x, int y, int val);
void display_flush(void);

#endif
