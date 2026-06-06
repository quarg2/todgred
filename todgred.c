#include "todgred.h"

#include "draw.h"
#include "menu.h"

int main(void) {
    Screen screen;

    initScreen(screen);

    while (true) {
        menu();
        Choice choice = getChoice();

        switch (choice) {
            case choiceDraw:
                break;
            case choiceDisplay:
                break;
            case choiceClear:
                break;
            case choiceModify:
                break;
            case choiceExit:
                break;
            case choiceHelp:
                break;
            default:  // Unreachable
                break;
        }
    }

    return 0;
}
