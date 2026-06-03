#ifndef todgred_header
#define todgred_header

#define COLS 128
#define ROWS 128

#define BLANK ' '
#define DRAW '*'

#define SQR(X) ((X) * (X))

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
    Point upperCorner;
    Point lowerCorner;
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
void drawLine(Screen screen, Line line, Mode mde);

#endif
