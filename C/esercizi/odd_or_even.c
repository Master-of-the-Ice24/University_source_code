/*

in questo esercizio bisogna calcolare se un numero è pari o dispari

RISOLUZIONE:

char[] è un array, punta a diverse zone di memoria e permette di trattarle come una struttura unica

*/


#include <stdio.h>


char *odd_or_even(int num) {
	if (num%2==0)
		return "even";
	return "odd";
}

int main() {
	printf(odd_or_even(33));

	return 0;	
}
