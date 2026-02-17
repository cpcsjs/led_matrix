#include "display.h"

static int tick = 0;

void anim_init(void)
{
    tick = 0;
}

void anim_update(void)
{
    display_clear();

    for (int x = 0; x < DISPLAY_WIDTH; x++)
    {
        int y = (x + tick) % DISPLAY_HEIGHT;
        display_set_pixel(x, y, 1);
    }

    tick++;
}
