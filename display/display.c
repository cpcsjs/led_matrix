#include "display.h"

static uint8_t fb[DISPLAY_WIDTH];

extern void hal_draw_buffer(uint8_t *buf);

void display_init(void)
{
    display_clear();
}

void display_clear(void)
{
    for (int i = 0; i < DISPLAY_WIDTH; i++)
        fb[i] = 0;
}

void display_set_pixel(int x, int y, int val)
{
    if (x < 0 || x >= DISPLAY_WIDTH) return;
    if (y < 0 || y >= DISPLAY_HEIGHT) return;

    if (val)
        fb[x] |=  (1 << y);
    else
        fb[x] &= ~(1 << y);
}

void display_flush(void)
{
    hal_draw_buffer(fb);
}
