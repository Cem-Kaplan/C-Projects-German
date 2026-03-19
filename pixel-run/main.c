#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

typedef struct {
    int x;
    int y;
} Player;

bool windowShouldClose = false;

int main() {
    initscr();

    while (!windowShouldClose) {
        clear();

        int key = getch();
    }

    endwin();
    return EXIT_SUCCESS;
}