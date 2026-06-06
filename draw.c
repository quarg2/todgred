#include "draw.h"

#include <stdio.h>

typedef struct {
    int count;
    Shape buffer[BUFSIZE];
} Shapes;

static Shapes buffer;

static int max(int a, int b) { return (a > b) ? a : b; }

static int min(int a, int b) { return (a < b) ? a : b; }

static bool isBetweenEq(int val, int lower, int upper) {
    return val >= min(lower, upper) && val <= max(lower, upper);
}
static bool isBetween(int val, int lower, int upper) {
    return val > min(lower, upper) && val < max(lower, upper);
}

void initScreen(Screen screen) {
    for (int y; y < COLS; y++) {
        for (int x; x < ROWS; x++) {
            screen[y][x] = BLANK;
        }
    }
}

void clearScreen(Screen screen) { initScreen(screen); }

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

static void drawCircle(Screen screen, Circle circle, Mode mode) {
    for (int y = 0; y < COLS; y++) {
        for (int x = 0; x < ROWS; x++) {
            if (pow(circle.radius, 2)
                == pow(x - circle.centre.x, 2) + pow(y - circle.centre.y, 2)) {
                screen[y][x] = DRAW;
            }
        }
    }
}

static void drawLine(Screen screen, Line line, Mode mode) {
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

static void drawRectangle(Screen screen, Rectangle rect, Mode mode) {
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

static void drawTriangle(Screen screen, Triangle triangle, Mode mode);

void bufferCircle(Screen screen, Circle circle, Mode mode);
