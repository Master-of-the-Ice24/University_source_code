#include <ncurses.h>
//#include <menu.h>
//#include <stdlib.h>

#include "./src/basicFuncs.h"

#define ESCAPE 27
#define ENTER 10

char *menuItems[] = {
					"Choice 1",
					"Choice 2",
					"Choice 3"
				};

int numItems = sizeof(menuItems) / sizeof(menuItems[0]);


void displayMenu(int highlight) {
	clear();
	for (int i=0; i<numItems; i++) {
		if (i == highlight) 
			attron(A_REVERSE);
		mvprintw(i+1, 1, "%s", menuItems[i]);
		if (i == highlight)
			attroff(A_REVERSE);
	}
	refresh();
}

/*

int main() {
	int highlight = 0;
	int choice;

	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	while(TRUE) {
		displayMenu(highlight);
		choice = getch();

		switch(choice) {
			case KEY_UP:
				highlight = (highlight-1 + numItems) % numItems;
				break;
			case KEY_DOWN:
				highlight = (highlight+1 + numItems) % numItems;
				break;	
		}

		mvprintw(numItems +2, 1, "You selected %s", menuItems[highlight]);
	}


	return 0;
}

*/

