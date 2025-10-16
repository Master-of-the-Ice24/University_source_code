#include <ncurses.h>
#include <menu.h>
#include "./src/basicFuncs.h"

#define ESCAPE 27
#define ENTER 10
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

char *choises[] = {
					"Choise 1",
					"Choise 2",
					"Choise 3"
				};



int main() {
	int key;
	
	do {
		initscr();
		//keypad(stdscr, FALSE);
		noecho();

		key = getch();		//getch() displays a value but underneath gets an integer number
	
		printw("hello enter a string: ");
		/*
		char *myString;
		getstr(myString);
		//myString = testingText();
		addstr(myString);
		*/
		refresh();
	} while (key != ENTER);

	endwin();
	return 0;
}
