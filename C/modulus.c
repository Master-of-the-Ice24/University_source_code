/*

la funzione printf si aspetta una stringa, ma siccome il parametro è un intero ha bisogno 
dell'argomento "%d", esso metterà al corrente la funzione di convertire il paramentro da intero a
stringa prima di eseguire la stampa a schermo

*/

#include <stdio.h>


int main() {
	printf("%d", 7%3);
	
	return 0;
}
