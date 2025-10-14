/*

La variabile v deve essere inserita dall'utente tramite scanf, quest'ultima funzione prende come input un 
indirizzo di memoria per leggere il dato in ingresso, con ""%d" gli si ordina di interpretarlo come intero

*/



#include <stdio.h>


int main() {
	int v;
	printf("Enter a number: ");
	scanf("%d", &v);
	printf("The double of v is: %d", v*2);

	return 0;
}
