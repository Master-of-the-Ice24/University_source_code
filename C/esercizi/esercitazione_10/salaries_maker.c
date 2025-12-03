#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char name[20];
    float salary;
} Employee;


int main() {
    Employee employee[5] = {
        {"Rossi", 2000},
        {"Giordani", 1700},
        {"Petrelli", 2300},
        {"Bovina", 900}
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