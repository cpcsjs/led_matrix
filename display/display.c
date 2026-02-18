#include "display.h"
#include <string.h>

static uint8_t front_buffer[DISPLAY_WIDTH][DISPLAY_HEIGHT];
static uint8_t back_buffer[DISPLAY_WIDTH][DISPLAY_HEIGHT];

void display_init(void)
{
    memset(front_buffer, 0, sizeof(front_buffer));
    memset(back_buffer, 0, sizeof(back_buffer));
}

void display_clear(void)
{
    memset(back_buffer, 0, sizeof(back_buffer));
}

void display_set_pixel(int x, int y, uint8_t v)
{
    if (x < 0 || x >= DISPLAY_WIDTH) return;
    if (y < 0 || y >= DISPLAY_HEIGHT) return;

    back_buffer[x][y] = v;
}

void display_swap(void)
{
    memcpy(front_buffer, back_buffer, sizeof(front_buffer));
}

uint8_t (*display_get_front(void))[DISPLAY_HEIGHT]
{
    return front_buffer;
}
