/*

Scrivere un programma che richieda in ingresso un massimo di DIM (dove DIM è una macro) numeri interi non negativi (fermandosi quandoviene inserito un numero negativo) e stampi il numero minimo, il numero massimo, la media aritmetica e inumeri più frequenti. 
Per l’input e per il calcolo delle statistiche creare apposite funzioni con parametro di tipo array.

Per testare il programma,
- creare un file di testo di nome numeri.in contenente 30 interi compresi fra 0 e
  99, seguiti dal numero -1;
- eseguire il programma redirigendo l’input su numeri.in.

*/ 

#include <stdio.h>

#define DIM 100


void getMostFrequent() {

}


void getMaxMin(int *vector) {
    

}


void aritmeticAverage() {


}


int main(void) {
    int vector[DIM];
    
    for (int i=0; i<DIM; i++) {        
        scanf("%d", &vector[i]);
        
        if (vector[i] < 0) {
            printf("Nagative number, shutting down...");
            return 11;
        }
        
    }

    getMaxMin(vector);

    return 0;
}
