#include <SDL2/SDL.h>
#include "led_sdl.h"
#include <stdint.h>

#define SCALE 5

static SDL_Window *win;
static SDL_Renderer *ren;

void hal_init(int width, int height)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetRelativeMouseMode(SDL_TRUE);
    SDL_ShowCursor(SDL_DISABLE);

    win = SDL_CreateWindow("LED MATRIX",
                           SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED,
                           width * SCALE,
                           height * SCALE,
                           0);

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);
}


void hal_draw_buffer(uint8_t *buf)
{
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderClear(ren);

    SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);

    for (int x = 0; x < 192; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            if (buf[x] & (1 << y))
            {
                SDL_Rect r = {
                    x * SCALE,
                    y * SCALE,
                    SCALE,
                    SCALE
                };
                SDL_RenderFillRect(ren, &r);
            }
        }
    }

    SDL_RenderPresent(ren);
}

void hal_delay(int ms)
{
    SDL_Delay(ms);
}
