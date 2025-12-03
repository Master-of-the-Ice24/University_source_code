#include <stdio.h>
#include <stdlib.h>
#include "./employee.h"


int main() {
    Employee employee[5] = {
        {"Rossi", 2000},
        {"Giordani", 1700},
        {"Petrelli", 2300},
        {"Bovina", 900},
        {"Ferrari", 1800}
    };


    FILE *document;

    if ((document = fopen("salaries.dat", "wb")) == NULL) {
        printf("OPENING ERROR shutting down...");
        exit(1);
    }

    fwrite(employee, sizeof(employee), 1, document);

    if (fclose(document) != 0) {
        printf("CLOSING ERROR shutting down...");
        exit(2);
    }

    return 0;
};