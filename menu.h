#ifndef todgred_menu_h
#define todgred_menu_h

#include "draw.h"

// Choices in the menu
typedef enum {
    CHOICE_DRAW,
    CHOICE_DISPLAY,
    CHOICE_CLEAR,
    CHOICE_MODIFY,
    CHOICE_EXIT,
    CHOICE_ERR,
} Choice;

void mainMenu(void);
void drawMenu(ShapeBuffer *shapeBuffer);
void modifyMenu(ShapeBuffer *shapeBuffer);
Choice getChoice(void);

int getLine(char *s, int lim);
int parseInt(char *s);

#endif
