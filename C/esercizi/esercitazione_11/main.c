#include <stdio.h>
#include <stdlib.h>
#include "./clientsList.h"


void readFile(char *filename) {
    FILE *documentManager;
    clientsRawList mylist[30];

    documentManager = fopen(filename, "rt");

    if (documentManager == NULL) {
        printf("Error, shutting down...");
        EXIT_FAILURE;
    }

    for (int i=0; i<5; i++) {
        //fread(&vector[i] sizeof(Employee), 1 ,document);
        fread(mylist + i, sizeof(clientsRawList), 1, documentManager);
        printf("\n%s %0.2f", mylist[i].fiscalCode, mylist[i].amount);
    }

 

    fclose(documentManager);

    if (documentManager != 0) {
        printf("Error, shutting down...");
        EXIT_FAILURE;
    }
}


int main(int argc, char **argv) {

    readFile(argv[1]);




    return EXIT_SUCCESS;
}