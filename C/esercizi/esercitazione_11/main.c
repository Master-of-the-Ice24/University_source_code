#include <stdio.h>
#include <stdlib.h>
#include "./clientsList.h"


void readFile(char *filename) {
    FILE *documentManager;
    char text[256], line[256];

    documentManager = fopen(filename, "rt");

    if (documentManager == NULL) {
        printf("Error, shutting down...");
        exit(1);
    }

    while (fgets(line, 255, documentManager)) {
        printf("%s ", line);
        
    }
    
    fclose(documentManager);

    if (documentManager != 0) {
        printf("Error in closing");
        //exit(2);
    }

}


int main(int argc, char **argv) {

    readFile(argv[1]);

    return EXIT_SUCCESS;
}