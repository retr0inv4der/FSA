#include <ncurses.h>

int main() {
    // Try to initialize
    initscr();
    printw("hello world");
    // Wait for key press
    int c = getch();
    printw("%d" , c ) ;
    getch();
    // Clean up
    endwin();
    return 0;
}
