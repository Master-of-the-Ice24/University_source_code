/*

Scrivere un programma che richieda all’utente un PIN al massimo tre volte. Se l’utente
inserisce il PIN esatto (uguale a 44122) il programma deve stampare il messaggio
"Accesso consentito"; se l’utente commette tre errori, deve stampare il messaggio
"Accesso negato".

*/



#include <stdio.h>


int main(void) {
    int pin;
    int c = 0;

    do {
        scanf("%d", &pin);

        if (pin == 44122)
            printf("Access granted");
        else 
            printf("Access denied");

        c++;
    } while(c < 3);

}

