#include "menu.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

static Shape getShape(ShapeType shape, Mode mode);

// Print the menu
void mainMenu(void) {
    printf("1. Draw shape\n");
    printf("2. Display drawing\n");
    printf("3. Modify drawing\n");
    printf("4. Clear drawing\n");
    printf("Enter choice [0-5] (0 to exit): ");
}

// Get user input and then print the output
// Returns the choice entered by the user
// If the input is invalid, returns CHOICE_ERR
Choice getChoice(void) {
#define MAXLINE 100
    char s[MAXLINE];
    getLine(s, MAXLINE);
    int choice = parseInt(s);

    switch (choice) {
        case 0:
            return CHOICE_EXIT;
        case 1:
            return CHOICE_DRAW;
        case 2:
            return CHOICE_DISPLAY;
        case 3:
            return CHOICE_MODIFY;
        case 4:
            return CHOICE_CLEAR;
        default:
            return CHOICE_ERR;
    }

#undef MAXLINE
}

// Menu to draw shapes
void drawMenu(ShapeBuffer *shapeBuffer) {
#define MAXLINE 1000
    char shapeInp[MAXLINE];
    char modeInp[MAXLINE];
    Mode mode;
    ShapeType shapeType;
    Shape shape;

shape:
    printf("Shapes:\n");
    printf("\t1. Circle\n");
    printf("\t2. Line\n");
    printf("\t3. Rectangle\n");
    printf("\t4. Triangle\n");
    printf("Enter shape [0-4] (0 to abort): ");

    getLine(shapeInp, MAXLINE);
    switch (parseInt(shapeInp)) {
        case 0:
            return;
        case 1:
            shapeType = SHAPETYPE_CIRCLE;
            break;
        case 2:
            shapeType = SHAPETYPE_LINE;
            break;
        case 3:
            shapeType = SHAPETYPE_RECTANGLE;
            break;
        case 4:
            shapeType = SHAPETYPE_TRIANGLE;
            break;
        default:
            printf("Enter valid value\n");
            goto shape;
    }

mode:
    printf("Mode of shape:\n");
    printf("\t1. Draw\n\t2. Negative\n");
    printf("Enter mode [0-2] (0 to abort): ");

    getLine(modeInp, MAXLINE);

    switch (parseInt(modeInp)) {
        case 0:
            return;
        case 1:
            mode = MODE_DRAW;
            break;
        case 2:
            mode = MODE_ERASE;
            break;
        default:
            printf("Please enter valid value\n");
            goto mode;
    }

    shape = getShape(shapeType, mode);

    bufferShape(shape, shapeBuffer);

#undef MAXLINE
}

// Print menu to modify things
void modifyMenu(/*ShapeBuffer shapeBuffer*/) {
#define MAXLINE 1000
    extern ShapeBuffer shapeBuffer;
    char shape[100];
    char inp[MAXLINE];
    int idx;

    for (int i = 0; i < shapeBuffer.count; i++) {
        switch (shapeBuffer.shapes[i].type) {
            case SHAPETYPE_NULL:
                continue;
                break;
            case SHAPETYPE_CIRCLE:
                strcpy(shape, "Circle");
                break;
            case SHAPETYPE_LINE:
                strcpy(shape, "Line");
                break;
            case SHAPETYPE_RECTANGLE:
                strcpy(shape, "Rectangle");
                break;
            case SHAPETYPE_TRIANGLE:
                strcpy(shape, "Triangle");
                break;
            default:  // Unreachable
                break;
        }

        printf("%d %s\n", i, shape);
    }

    printf("Enter index of shape to be modified: [0-%d] (0 to abort): ",
           shapeBuffer.quantity);
    getLine(inp, MAXLINE);
    idx = parseInt(inp);

    printf("What should happen to the shape?:");
    printf("\t1. Modify coordinates\n");
    printf("\t2. Change drawing mode\n");
    printf("\t3. Delete shape\n");

#undef MAXLINE
}

// Reads a line of maximum length lim from stdin
// Asumes that s at least of length lim.
int getLine(char *s, int lim) {
    int c, i = 0;

    while (lim-- > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';

    return i;
}

// Converts string to int
// Returns the int read from the string
// Returns zero on error
int parseInt(char *s) {
    int val, i;

    for (i = 0; isspace(s[i]); i++) {
        ;
    }
    for (val = 0; isdigit(s[i]); i++) {
        val = val * 10 + (s[i] - '0');
    }

    return val;
}

static Shape getShape(ShapeType shapeType, Mode mode) {
#define MAXLINE 100
    char buffer[MAXLINE];
    switch (shapeType) {
        case SHAPETYPE_NULL:  // Unreachable, probably
            return SHAPE_AS_NULL;
        case SHAPETYPE_CIRCLE: {
            Circle circle;

            printf("Enter radius: ");
            getLine(buffer, MAXLINE);
            circle.radius = parseInt(buffer);

            printf("Enter x-coordinate of centre: ");
            getLine(buffer, MAXLINE);
            circle.centre.x = parseInt(buffer);

            printf("Enter y-coordinate of centre: ");
            getLine(buffer, MAXLINE);
            circle.centre.y = parseInt(buffer);

            return SHAPE_AS_CIRCLE(circle, mode);
        }
        case SHAPETYPE_LINE: {
            Line line;

            printf("Enter x-coordinate of start position: ");
            getLine(buffer, MAXLINE);
            line.start.x = parseInt(buffer);

            printf("Enter y-coordinate of start position: ");
            getLine(buffer, MAXLINE);
            line.start.y = parseInt(buffer);

            printf("Enter x-coordinate of end position: ");
            getLine(buffer, MAXLINE);
            line.end.x = parseInt(buffer);

            printf("Enter y-coordinate of end position: ");
            line.end.y = parseInt(buffer);

            return SHAPE_AS_LINE(line, mode);
        }
        case SHAPETYPE_RECTANGLE: {
            Rectangle rect;

            printf("Enter x-coordinate of corner 1: ");
            getLine(buffer, MAXLINE);
            rect.lowerCorner.x = parseInt(buffer);

            printf("Enter y-coordinate of corner 1: ");
            getLine(buffer, MAXLINE);
            rect.lowerCorner.y = parseInt(buffer);

            printf("Enter x-coordinate of corner 2: ");
            getLine(buffer, MAXLINE);
            rect.upperCorner.x = parseInt(buffer);

            printf("Enter y-coordinate of corner 2: ");
            getLine(buffer, MAXLINE);
            rect.upperCorner.y = parseInt(buffer);

            return SHAPE_AS_RECT(rect, mode);
        }
        case SHAPETYPE_TRIANGLE: {
            Triangle triangle;

            printf("Enter x-coordinate of corner 1: ");
            getLine(buffer, MAXLINE);
            triangle.corner1.x = parseInt(buffer);

            printf("Enter y-coordinate of corner 1: ");
            getLine(buffer, MAXLINE);
            triangle.corner1.y = parseInt(buffer);

            printf("Enter x-coordinate of corner 2: ");
            getLine(buffer, MAXLINE);
            triangle.corner2.x = parseInt(buffer);

            printf("Enter y-coordinate of corner 2: ");
            getLine(buffer, MAXLINE);
            triangle.corner2.y = parseInt(buffer);

            printf("Enter x-coordinate of corner 3: ");
            getLine(buffer, MAXLINE);
            triangle.corner3.x = parseInt(buffer);

            printf("Enter y-coordinate of corner 3: ");
            getLine(buffer, MAXLINE);
            triangle.corner3.y = parseInt(buffer);

            return SHAPE_AS_TRIANGLE(triangle, mode);
        }
        default:  // Unreachable
            return SHAPE_AS_NULL;
            break;
    }
#undef MAXLINE
}
