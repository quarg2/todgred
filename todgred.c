#include "todgred.h"

#include "draw.h"
#include "menu.h"

Screen screen;
ShapeBuffer shapeBuffer;

int main(void) {
    shapeBuffer = initShapeBuffer();

    initScreen(screen);

    while (true) {
        mainMenu();
        Choice choice = getChoice();

    choice:
        switch (choice) {
            case CHOICE_DRAW:
                drawMenu(&shapeBuffer);
                break;
            case CHOICE_DISPLAY:
                printScreen(screen, &shapeBuffer);
                break;
            case CHOICE_CLEAR:
                clearScreen(screen, &shapeBuffer);
                break;
            case CHOICE_MODIFY:
                // modifyMenu();
                break;
            case CHOICE_EXIT:
                goto exitLoop;
                break;
            case CHOICE_ERR:
                printf("Enter valid choice!\n");
                break;
            default:  // Unreachable
                printf("Invalid choice\n");
                goto choice;
                break;
        }
    }
exitLoop:

    freeShapeBuffer(&shapeBuffer);

    return 0;
}
