#include <stdio.h>
#include <stdlib.h>
#include "./clientsList.h"
#include <string.h>


char *splitter(char *line) {
    char *splitted = (char *)malloc(6*sizeof(char));
    int lenght = 0;

    for (int i=0; i<sizeof(line); i++) {
        if (line[i] == " ") {
            lenght = i-1;
            strncpy(splitted[i], line[i], lenght);
    }
    
    }
    return splitted;
    
}


void readFile(char *filename) {
    FILE *documentManager;
    char text[256], line[256];
    char 

    documentManager = fopen(filename, "rt");

    if (documentManager == NULL) {
        printf("Error, shutting down...");
        exit(1);
    }

    while (fgets(line, 255, documentManager)) {
        printf("%s", line);

        
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