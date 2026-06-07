#ifndef todgred_draw_h
#define todgred_draw_h

#include <math.h>
#include <stdbool.h>

// Height and width of the screen
#define COLS 128
#define ROWS 128

// Character used to draw blank spaces on the screen
#ifndef BLANK
#define BLANK '_'
#endif

// Character used to draw a filled space on the screen
#ifndef FILLED
#define FILLED '*'
#endif

#define EQUAL2(lhs, rhs1, rhs2) ((lhs) == (rhs1) || (lhs) == (rhs2))

#define DRAW (mode == MODE_DRAW) ? FILLED : BLANK

// Macros that buffer the shapes.
// Use these instead of explicit buffer to hide implementation details
#define DRAW_CIRCLE(circle, mode)     bufferShape(circle, mode)
#define DRAW_LINE(line, mode)         bufferShape(line, mode)
#define DRAW_RECTANGLE(rect, mode)    bufferShape(rect, mode)
#define DRAW_TRIANGLE(triangle, mode) bufferShape(triangle, mode)

// 2D char array storing the canvas
// Stored as [COLS][ROWS] since C uses a column major format
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

// Mode in which the shape is to be drawn
typedef enum {
    MODE_DRAW,   // Draws with DRAW character
    MODE_ERASE,  // Draws with BLANK character (draw with negative space)
} Mode;

// Tag for Shape
typedef enum {
    SHAPETYPE_NULL,  // Null shape used as sentinel
    SHAPETYPE_CIRCLE,
    SHAPETYPE_RECTANGLE,
    SHAPETYPE_LINE,
    SHAPETYPE_TRIANGLE,
} ShapeType;

// A struct that stores a tagged union with the shape and the mode
typedef struct {
    ShapeType type;
    union {
        Circle circle;
        Line line;
        Rectangle rect;
        Triangle triangle;
    } as;
    Mode mode;
} Shape;

// Functions to convert the various shapes into a Shape
#define SHAPE_AS_NULL \
    (Shape) { .type = SHAPETYPE_NULL, .as = {{0}}, .mode = BLANK }
#define SHAPE_AS_CIRCLE(circle, mode) \
    (Shape) { .type = SHAPETYPE_CIRCLE, .as = {.circle = circle}, .mode = mode }
#define SHAPE_AS_LINE(line, mode) \
    (Shape) { .type = SHAPETYPE_LINE, .as = {.line = line}, .mode = mode }
#define SHAPE_AS_RECT(rect, mode) \
    (Shape) { .type = SHAPETYPE_RECTANGLE, .as = {.rect = rect}, .mode = mode }
#define SHAPE_AS_TRIANGLE(triangle, mode)                                      \
    (Shape) {                                                                  \
        .type = SHAPETYPE_TRIANGLE, .as = {.triangle = triangle}, .mode = mode \
    }

// Macros to check what shape a Shape is
#define IS_SHAPE_NULL(shape)     ((shape).type == SHAPETYPE_NULL)
#define IS_SHAPE_CIRCLE(shape)   ((shape).type == SHAPETYPE_CIRCLE)
#define IS_SHAPE_LINE(shape)     ((shape).type == SHAPETYPE_LINE)
#define IS_SHAPE_RECT(shape)     ((shape).type == SHAPETYPE_RECT)
#define IS_SHAPE_TRIANGLE(shape) ((shape).type == SHAPETYPE_TRIANGLE)

void initScreen(Screen screen);
void clearScreen(Screen screen);
void printScreen(Screen screen);

void bufferShape(Shape shape);

#endif
