/*

La funzione trasforma il parametro da intero tramite l'argomento %d. Quando stampa a schermo i dati restituisce
implicitamente anche il numero dei caratteri totali.

In questo caso il programma prima esegue printf("%d\n", 3+2) che stampa il valore 5, successivamente esegue
printf("%d\n", printf("%d\n", 3+2)); che ritorna valore 2, poichè i caratteri 5 e "a capo" sommati sono 2 

*/



#include <stdio.h>

int main() {
	printf("%d\n", printf("%d\n", 3+2));

	return 0;
}
