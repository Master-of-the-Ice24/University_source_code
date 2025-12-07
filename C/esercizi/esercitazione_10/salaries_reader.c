#include <stdio.h>
#include <stdlib.h>
#include "employee.h"


int main() {

    FILE *document;

    if ((document = fopen("salaries.dat", "rb")) == NULL) {
        printf("OPENING ERROR shutting down...");
        exit(1);
    }

    /*
    Employee germano;

    while(fread(&germano, sizeof(Employee), 1, document)) {
        //printf("data: %s ", germano.name);
    }
    */

    Employee vector[5];

    for (int i=0; i<5; i++) {
        //fread(&vector[i], sizeof(Employee), 1 ,document);
        fread(vector + i, sizeof(Employee), 1 ,document);
        printf("\n%d %s %0.2f", i, vector[i].name, vector[i].salary);
    }

    if (fclose(document) != 0) {
        printf("CLOSING ERROR shutting down...");
        exit(2);
    }
    
    return 0;
}
