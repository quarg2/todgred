#include "draw.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int count;
    int quantity;
    Shape *shapes;
} ShapeBuffer;

static ShapeBuffer initShapeBuffer(void);
static void addShapeToShapeBuffer(ShapeBuffer *buffer, Shape shape);
static void removeShapeFromShapeBuffer(ShapeBuffer *buffer, int index);
static void freeShapeBuffer(ShapeBuffer *buffer);

static int drawShapes(Screen screen, ShapeBuffer *buffer);

static ShapeBuffer shapeBuffer = {0, 0, NULL};

static int max(int a, int b) { return (a > b) ? a : b; }

static int min(int a, int b) { return (a < b) ? a : b; }

static bool isBetweenEq(int val, int lower, int upper) {
    return val >= min(lower, upper) && val <= max(lower, upper);
}
static bool isBetween(int val, int lower, int upper) {
    return val > min(lower, upper) && val < max(lower, upper);
}

void initScreen(Screen screen) {
    for (int y = 0; y < COLS; y++) {
        for (int x = 0; x < ROWS; x++) {
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
            if ((EQUAL2(x, rect.lowerCorner.x, rect.upperCorner.x)
                 && isBetweenEq(y, rect.lowerCorner.y, rect.upperCorner.y))
                || (EQUAL2(y, rect.lowerCorner.y, rect.upperCorner.y)
                    && isBetweenEq(x, rect.lowerCorner.x,
                                   rect.upperCorner.x))) {
                screen[y][x] = DRAW;
            }
        }
    }
}

static void drawTriangle(Screen screen, Triangle triangle, Mode mode) {
    return;
}

static int drawShapes(Screen screen, ShapeBuffer *buffer) {
    for (int i = 0; i < buffer->quantity; i++) {
        switch (buffer->shapes[i].type) {
            case SHAPETYPE_NULL:
                break;  // Do nothing for the NULL shape
            case SHAPETYPE_CIRCLE:
                drawCircle(screen, buffer->shapes[i].as.circle,
                           buffer->shapes[i].mode);
                break;
            case SHAPETYPE_LINE:
                drawLine(screen, buffer->shapes[i].as.line,
                         buffer->shapes[i].mode);
                break;
            case SHAPETYPE_RECTANGLE:
                drawRectangle(screen, buffer->shapes[i].as.rect,
                              buffer->shapes[i].mode);
                break;
            case SHAPETYPE_TRIANGLE:
                drawTriangle(screen, buffer->shapes[i].as.triangle,
                             buffer->shapes[i].mode);
                break;
            default:  // Unreachable
                break;
        }
    }

    return 0;
}

void bufferShape(Shape shape) {
    switch (shape.type) {
        case SHAPETYPE_NULL:
            // The null shape isn't drawn
            break;
        case SHAPETYPE_CIRCLE:
            addShapeToShapeBuffer(&shapeBuffer, shape);
            break;
        case SHAPETYPE_LINE:
            addShapeToShapeBuffer(&shapeBuffer, shape);
            break;
        case SHAPETYPE_RECTANGLE:
            addShapeToShapeBuffer(&shapeBuffer, shape);
            break;
        case SHAPETYPE_TRIANGLE:
            addShapeToShapeBuffer(&shapeBuffer, shape);
            break;
        default:  // Unreachable
            break;
    }
}

static ShapeBuffer initShapeBuffer(void) { return (ShapeBuffer){0, 0, NULL}; }

static void addShapeToShapeBuffer(ShapeBuffer *buffer, Shape shape) {
    if (buffer->count >= buffer->quantity) {
        buffer->shapes = (Shape *)realloc(buffer->shapes,
                                          sizeof(Shape) * buffer->count * 2);
        buffer->count *= 2;
    }
    buffer->shapes[buffer->quantity++] = shape;
}

static void removeShapeFromShapeBuffer(ShapeBuffer *buffer, int index) {
    if (index > buffer->count) {
        return;
    }
    buffer->shapes[index] = SHAPE_AS_NULL;
}

static void freeShapeBuffer(ShapeBuffer *buffer) {
    free(buffer->shapes);
    *buffer = initShapeBuffer();
}
