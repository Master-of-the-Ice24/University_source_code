/*

scrivere un programma che calcoli i numeri primi fino a 100 indicando quali sono pari e 
quali dispari, e che infine mostri i loro quadrati. 

*/



#include <stdio.h>
#include <stdlib.h>


void dinamicAppendValue(int **array, int number, int *length) {     //"**array" è una variabile che contiene un indirizzo di memoria che a sua volta contiene l'indirizzo del primo intero dell'array
    (*length)++;        //aggiornamento della lunghezza dell'array
    int *newArray = (int *) realloc(*array, (*length)*sizeof(int));     //creazione di una variabile che contiene un indirizzo di memoria che punta al primo intero del vecchio array e aggiunge una posizione alla fine
    if (newArray == NULL) {     //se il valore di questa variabile non è un indirizzo di memoria ma NULL significa che l'allocazione non è andata a buon fine
        printf("Segmentation fault, shutting down");
        free(*array);       //si restituisce al S.O. il buffer usato per l'array
        *array = NULL;      //la variabile che conteneva l'indirizzo di memoria che avrebbe portato al primo intero dell'array iniziale è impostata a 0
        return;     //rischiando segmentation fault la funzione è terminata
    } 
    *array = newArray;      //la variabile che puntava al primo intero dell'array è aggiornata ad una lunghezza più grande
    (*array)[*length-1] = number;       //il nuovo posto appena creato è assegnato al valore
}


void primeNumbers(void) {       //funzione che non restituisce valori nè prende parametri
    int localCounter = 0, primeCounter = 0, length=0;       //i contatore vanne sempre inizializzati a 0
    int *primeNumbersList = NULL;       //il puntatore della lista dei numeri primi all'inizio è vuoto
    for(int i=0; i<101; i++) {      //da 0 fino a 100
        for (int j=1; j<101; j++ ) {        //da 1 fino a 100
            if (i % j == 0) {
                localCounter++;
            }
        }
        if (localCounter == 2) {        //se sono stati trovati 2 e solo 2 divisori allora il numero è primo
            primeCounter++;     //aggiornamento contatore numeri primi
            dinamicAppendValue(&primeNumbersList, i, &length);

        }

        localCounter = 0;       //resettazione del contatore dei divisori
    }
    printf("\nFrom 0 to 100 there are %d prime numbers:\n", primeCounter);
    for (int i=0; i<length; i++) {
        printf("%d) %d", i+1, primeNumbersList[i]);
        if (primeNumbersList[i] % 2 == 0) {     //controllo se il numero è pari
            printf(" is even ");
        } else {
            printf(" is odd ");
        }
        printf("and its square is %d\n", primeNumbersList[i]*primeNumbersList[i]);
    }
}


int main(void) {
    primeNumbers();     //invocazione dell'omonima funzione 
    return 0;       //restituzione di valori diversi da 0 in caso di eventuali errori
}
