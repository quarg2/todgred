#include "menu.h"

#include "input.h"

// Print the menu
void menu(void) {
    printf("1. Draw shape\n");
    printf("2. Display drawing\n");
    printf("3. Modify drawing\n");
    printf("4. Clear drawing\n");
    printf("5. Help\n");
    printf("Enter choice [0-6] (0 to exit): ");
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
        case 5:
            return CHOICE_HELP;
        default:
            return CHOICE_ERR;
    }

#undef MAXLINE
}
