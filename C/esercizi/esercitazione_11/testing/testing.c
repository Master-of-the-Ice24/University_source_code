#include <stdio.h>
#include <stdlib.h>
#include "../clientsList.h"



void readFile(char *filename) {
    FILE *documentManager;

    documentManager = fopen(filename, "rt");

    if (documentManager == NULL) {
        printf("Error, shutting down...");
        exit(1);
    }
    
    clientsRawList list[256];
    
    for (int i=0; i<28; i++) {
        fscanf(documentManager, "%s %d %d %d %f", &(list[i]).fiscalCode, 
                                                    &(list[i]).day, 
                                                    &(list[i]).month, 
                                                    &(list[i]).year, 
                                                    &(list[i]).amount);
    }

    for (int i=0; i<60; i++) {
        printf("%d %s\n", i, list[i].fiscalCode);
    }
    
    fclose(documentManager); 


    if (documentManager != 0) {
        printf("\nError in closing");
    }
}


int main(int argc, char **argv) {
    
    readFile(argv[1]);

    return 0;
}