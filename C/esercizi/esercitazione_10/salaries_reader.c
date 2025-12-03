#include <stdio.h>
#include <stdlib.h>
#include "employee.h"


int main() {

    FILE *document;

    if ((document = fopen("salaries.dat", "rb")) == NULL) {
        printf("OPENING ERROR shutting down...");
        exit(1);
    }

    Employee germano;

    while(fread(&germano, sizeof(Employee), 1, document)) {
        printf("data: %s ", germano.name);
    }

    if (fclose(document) != 0) {
        printf("CLOSING ERROR shutting down...");
        exit(2);
    }




    return 0;
}