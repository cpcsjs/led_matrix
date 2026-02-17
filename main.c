#include "display/display.h"
#include <SDL2/SDL.h>
#include <signal.h>

extern void hal_init(int w, int h);
extern void hal_delay(int ms);

/* -------- graceful exit flag -------- */
static volatile int running = 1;

void handle_sigint(int sig)
{
    (void)sig;
    running = 0;
}

int main(void)
{
    signal(SIGINT, handle_sigint);

    hal_init(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    display_init();

    SDL_Event e;
    int offset = 0;

    while (running)
    {
        /* ---- SDL event pump ---- */
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                running = 0;
        }

        /* ---- logic layer ---- */
        display_clear();

        for (int x = 0; x < DISPLAY_WIDTH; x++)
        {
            int y = (x + offset) % DISPLAY_HEIGHT;
            display_set_pixel(x, y, 1);
        }

        offset++;

        /* ---- render ---- */
        display_flush();

        /* ---- timing ---- */
        hal_delay(30);   // ~33 FPS
    }

    SDL_Quit();
    return 0;
}
