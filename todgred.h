#ifndef todgred_header
#define todgred_header

#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#define COLS 128
#define ROWS 128

#define BLANK ' '
#define FILLED '*'

#define EQUAL2(lhs, rhs1, rhs2) ((lhs) == (rhs1) || (lhs) == (rhs2))

#define DRAW (mode == modeDraw) ? FILLED : BLANK


// 2D char array storing the canvas
typedef char Screen[COLS][ROWS];

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int radius;
    Point centre;
} Circle;

typedef struct {
    Point lowerCorner;
    Point upperCorner;
} Rectangle;

typedef struct {
    Point start;
    Point end;
} Line;

typedef enum {
    modeDraw,
    modeErase,
} Mode;

void initScreen(Screen screen);
void clearScreen(Screen screen);
void printScreen(Screen screen);
void drawCircle(Screen screen, Circle circle, Mode mode);
void drawRectangle(Screen screen, Rectangle rect, Mode mode);
void drawLine(Screen screen, Line line, Mode mode);

int max(int a, int b);
int min(int a, int b);
bool isBetweenEq(int val, int lower, int upper);
bool isBetween(int val, int lower, int upper);

#endif
