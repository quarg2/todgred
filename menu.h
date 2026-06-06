#ifndef todgred_menu_h
#define todgred_menu_h

#include "todgred.h"

typedef enum {
    choiceDraw,
    choiceDisplay,
    choiceClear,
    choiceModify,
    choiceExit,
    choiceHelp,
} Choice;

void menu(void);
Choice getChoice(void);

#endif
