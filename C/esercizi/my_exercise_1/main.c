#include <ncurses.h>
//#include <menu.h>
//#include <stdlib.h>
//#include "./src/basicFuncs.h"

#define ESCAPE 27
#define ENTER 10

int main(void) {
    WINDOW win;


    wprintw(win, "helloworld");

    wgetch(win);
    endwin();

    return 0;
}
return 0;;
