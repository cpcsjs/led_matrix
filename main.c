#include "display/display.h"
#include <SDL2/SDL.h>
#include <signal.h>
#include "display/anim.h"

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
       display_clear();

       anim_update();       // วาดลง back buffer

       display_swap();      // เตรียม frame ใหม่

       display_flush();     // HAL ส่งออก

       hal_delay(16);       // ~60 FPS
     }
    SDL_Quit();
    return 0;
}
