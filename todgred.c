#include "todgred.h"

#include "draw.h"
#include "menu.h"

int main(void) {
    Screen screen;
    Shape shapeBuffer[BUFSIZE];

    initScreen(screen);

    while (true) {
        menu();
        Choice choice = getChoice();

        switch (choice) {
            default:  // Unreachable
                break;
        }
    }

    return 0;
}
