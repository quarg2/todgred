#include "todgred.h"

#include <math.h>
#include <stdio.h>

int main(void) {
    Screen screen;

    initScreen(screen);

    // drawCircle(screen, (Circle){10, {20, 20}}, modeDraw);

    drawRectangle(screen,
                  (Rectangle){
                      {10, 10},
                      {20, 20}
    },
                  modeDraw);
    drawRectangle(screen,
                  (Rectangle){
                      {30, 10},
                      {10, 30}
    },
                  modeDraw);

    printScreen(screen);

    return 0;
}

void drawRectangle(Screen screen, Rectangle rect, Mode mode) {
    for (int x = 0; x < COLS; x++) {
        for (int y = 0; y < ROWS; y++) {
            if ((x == rect.lowerCorner.x && y >= rect.lowerCorner.y
                 && y <= rect.upperCorner.y)
                || (y == rect.lowerCorner.y && x >= rect.lowerCorner.x
                    && x <= rect.upperCorner.x)
                || (x == rect.upperCorner.x && y <= rect.upperCorner.y
                    && y >= rect.lowerCorner.y)
                || (y == rect.upperCorner.y && x <= rect.upperCorner.x
                    && x >= rect.lowerCorner.x)) {
                screen[y][x] = DRAW;
            }
        }
    }
}

void drawLine(Screen screen, Line line, Mode mode) {
    for (int y = 0; y < COLS; y++) {
        for (int x = 0; x < ROWS; x++) {
            if ((y - line.start.y) * (line.end.x - line.start.x)
                == (line.end.y - line.start.y) * (x - line.start.x)) {
                screen[y][x] = DRAW;
            }
        }
    }
}

void drawCircle(Screen screen, Circle circle, Mode mode) {
    for (int y = 0; y < COLS; y++) {
        for (int x = 0; x < ROWS; x++) {
            if (pow(circle.radius, 2)
                == pow(x - circle.centre.x, 2) + pow(y - circle.centre.y, 2)) {
                screen[y][x] = DRAW;
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
    for (int y = 0; y < COLS; y++) {
#ifdef DEBUG
        printf("%d", i % 10);
#endif
        for (int x = 0; x < ROWS; x++) {
            putchar(screen[y][x]);
        }
        putchar('\n');
    }
}

void clearScreen(Screen screen) { initScreen(screen); }

//
void initScreen(Screen screen) {
    for (int y = 0; y < COLS; y++) {
        for (int x = 0; x < ROWS; x++) {
            screen[y][x] = BLANK;
        }
    }
}
