CC = clang

CFLAGS = -I. -I$(PREFIX)/include/SDL2
LDFLAGS = -L$(PREFIX)/lib -lSDL2

SRC = main.c \
      display/display.c \
      display/anim.c \
      hal/led_sdl.c

OUT = app

all:
	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
