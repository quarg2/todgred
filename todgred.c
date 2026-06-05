#include "todgred.h"

int main(void) {
    Screen screen;

    // Testing
    initScreen(screen);

    drawRectangle(screen,
                  (Rectangle){
                      {10, 10},
                      {20, 20}
    },
                  modeDraw);

    drawRectangle(screen,
                  (Rectangle){
                      {10, 30},
                      {30, 10}
    },
                  modeDraw);

    printScreen(screen);

    return 0;
}

void drawRectangle(Screen screen, Rectangle rect, Mode mode) {
    for (int x = 0; x < COLS; x++) {
        for (int y = 0; y < ROWS; y++) {
            if (EQUAL2(x, rect.lowerCorner.x, rect.upperCorner.x)
                    && isBetweenEq(y, rect.lowerCorner.y, rect.upperCorner.y)
                || EQUAL2(y, rect.lowerCorner.y, rect.upperCorner.y)
                       && isBetweenEq(x, rect.lowerCorner.x,
                                      rect.upperCorner.x)) {
                screen[y][x] = DRAW;
            }
        }
    }
}

void drawLine(Screen screen, Line line, Mode mode) {
    for (int y = 0; y < COLS; y++) {
        for (int x = 0; x < ROWS; x++) {
            if (isBetweenEq(x, line.start.x, line.end.x)
                && isBetweenEq(y, line.start.y, line.end.y)) {
                if ((y - line.start.y) * (line.end.x - line.start.x)
                    == (line.end.y - line.start.y) * (x - line.start.x)) {
                    screen[y][x] = DRAW;
                }
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
    printf(" ");
    for (int i = 0; i < COLS; i++) {
        printf("%d", (i / 10) % 10);
    }
    printf("\n ");
    for (int i = 0; i < COLS; i++) {
        printf("%d", i % 10);
    }
    printf("\n");
#endif
    for (int y = 0; y < COLS; y++) {
#ifdef DEBUG
        printf("%d", y % 10);
#endif
        for (int x = 0; x < ROWS; x++) {
            putchar(screen[y][x]);
        }
        putchar('\n');
    }
}

void clearScreen(Screen screen) { initScreen(screen); }

void initScreen(Screen screen) {
    for (int y = 0; y < COLS; y++) {
        for (int x = 0; x < ROWS; x++) {
            screen[y][x] = BLANK;
        }
    }
}

int max(int a, int b) { return (a > b) ? a : b; }

int min(int a, int b) { return (a < b) ? a : b; }

bool isBetweenEq(int val, int lower, int upper) {
    return val >= min(lower, upper) && val <= max(lower, upper);
}

bool isBetween(int val, int lower, int upper) {
    return val > min(lower, upper) && val < max(lower, upper);
}
