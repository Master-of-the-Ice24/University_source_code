/*

Scrivere un programma che richieda in ingresso un massimo di DIM (dove DIM è una macro) numeri interi non negativi (fermandosi quandoviene inserito un numero negativo) e stampi il numero minimo, il numero massimo, la media aritmetica e i numeri più frequenti. 
Per l’input e per il calcolo delle statistiche creare apposite funzioni con parametro di tipo array.

Per testare il programma,
- creare un file di testo di nome numeri.in contenente 30 interi compresi fra 0 e 99, seguiti dal numero -1;
- eseguire il programma redirigendo l’input su numeri input

*/ 

#include <stdio.h>
#define DIM 4


void mostFrequent(int *vector) {
    int selected, counter=1, mostCounted = vector[0], frequency = 1;

    for (int i=0; i<DIM; i++) {
        for (int j=i+1; j<DIM; j++) 
            if (vector[j] == vector[i])
                counter++; 
        
        if (counter > frequency) {
            mostCounted = vector[i];
            frequency = counter;
        }
        
        counter = 1;
    }

    printf("\nmost frequent number: %d", mostCounted);
}


void maxMin(int *vector) {
    int max=vector[0], min=vector[0];

    for (int i=0; i<DIM; i++) {
        if (max < vector[i])
            max = vector[i];

        if (min > vector[i])
            min = vector[i];
    }

    printf("\nmax: %d, min: %d", max, min);
}


void aritmeticAverage(int *vector) {
    int sum = 0;
    float finalValue;

    for (int i=0; i<DIM; i++) 
        sum = sum + vector[i];

    finalValue = (float)sum/(float)DIM;

    printf("\naritmetic average: %0.2f", finalValue);

}


void getStats(int *vector) {
    maxMin(vector);
    mostFrequent(vector);
    aritmeticAverage(vector);
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

    getStats(vector);

    return 0;
}
