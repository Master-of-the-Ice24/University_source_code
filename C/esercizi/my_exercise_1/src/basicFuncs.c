#include <ncurses.h>


char *testingText() {
	return "Hello World !!";
}


char insertString(char *string) {

	getstr(string);
	
	addstr(string);
}

