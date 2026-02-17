# LED Matrix 192x8

Embedded-style LED Matrix engine  
SDL simulation + double buffer

## Features
- Framebuffer abstraction
- HAL layer
- Animation engine
- Clean embedded architecture

## Build

```bash
clang main.c \
display/display.c \
display/anim.c \
hal/led_sdl.c \
-I. \
-I$PREFIX/include/SDL2 \
-L$PREFIX/lib \
-lSDL2 \
-o app
