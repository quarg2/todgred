#ifndef todgred_menu_h
#define todgred_menu_h

#include "todgred.h"

// Choices in the menu
typedef enum {
    CHOICE_DRAW,
    CHOICE_DISPLAY,
    CHOICE_CLEAR,
    CHOICE_MODIFY,
    CHOICE_EXIT,
    CHOICE_HELP,
    CHOICE_ERR,
} Choice;

void menu(void);
Choice getChoice(void);

#endif
