#include "todgred.h"

#include <stdio.h>

int main(void) {
    Screen screen;
 
    return 0;
}

void drawCircle(Screen screen, Circle circle, Mode mode) {
    for (int x = 0; x < ROWS; x++) {
        for (int y = 0; y < COLS; y++) {
            if (SQR(circle.radius)
                == SQR(x - circle.centre.x) + SQR(y - circle.centre.y)) {
                screen[x][y] = (mode == modeDraw) ? DRAW : BLANK;
            }
        }
    }
}

void printScreen(Screen screen) {
#ifdef DEBUG
    for (int i = 0; i < COLS; i++) {
        printf("%d", i % 10);
    }
#endif
    for (int i = 0; i < COLS; i++) {
#ifdef DEBUG
        printf("%d", i % 10);
#endif
        for (int j = 0; j < ROWS; j++) {
            putchar(screen[i][j]);
        }
        putchar('\n');
    }
}

void clearScreen(Screen screen) { initScreen(screen); }

void initScreen(Screen screen) {
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            screen[i][j] = BLANK;
        }
    }
}
