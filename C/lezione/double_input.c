/*

La variabile v deve essere inserita dall'utente tramite scanf, questa funzione prende 2 argomenti per parametri:
il primo è uno string literal che specifica il tipo di dato in entrata, il secondo è l'indirizzo di memoria dove
risiede tale dato

*/



#include <stdio.h>


int main() {
	int v;
	printf("Enter a number: ");
	scanf("%d", &v);
	printf("The double of v is: %d", v*2);

	return 0;
}
