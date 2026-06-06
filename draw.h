#ifndef todgred_draw_h
#define todgred_draw_h

#include <math.h>
#include <stdbool.h>

#define COLS 128
#define ROWS 128

#ifndef BLANK
#define BLANK '_'
#endif

#ifndef FILLED
#define FILLED '*'
#endif

#ifndef BUFSIZE
#define BUFSIZE 10
#endif

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
    Point start;
    Point end;
} Line;

typedef struct {
    Point lowerCorner;
    Point upperCorner;
} Rectangle;

typedef struct {
    Point corner1;
    Point corner2;
    Point corner3;
} Triangle;

typedef enum {
    shapeTypeCircle,
    shapeTypeRect,
    shapeTypeLine,
    shapeTypeTriangle,
} ShapeType;

typedef enum {
    modeDraw,
    modeErase,
} Mode;

typedef struct {
    ShapeType type;
    union {
        Circle circle;
        Rectangle rect;
        Line line;
    } as;
} Shape;

void initScreen(Screen screen);
void clearScreen(Screen screen);
void printScreen(Screen screen);

void bufferCircle(Screen screen, Circle circle, Mode mode);
void bufferLine(Screen screen, Line line, Mode mode);
void bufferRectangle(Screen screen, Rectangle rect, Mode mode);
void bufferTriangle(Screen screen, Triangle triangle, Mode mode);

#endif
