#include "menu.h"

#include "input.h"

void menu(void) {
    printf("1. Draw shape\n");
    printf("2. Display drawing\n");
    printf("3. Modify drawing\n");
    printf("4. Clear drawing\n");
    printf("5. Help\n");
    printf("Enter choice [0-6] (0 to exit): ");
}

Choice getChoice(void) {
#define MAXLINE 100
    char s[1000];
    getLine(s, MAXLINE);
    int choice = parseInt(s);

    switch (choice) {
        case 0:
            return choiceExit;
        case 1:
            return choiceDraw;
        case 2:
            return choiceDisplay;
        case 3:
            return choiceModify;
        case 4:
            return choiceClear;
        case 5:
            return choiceHelp;
        default:
            return -1;
    }

#undef MAXLINE
}
