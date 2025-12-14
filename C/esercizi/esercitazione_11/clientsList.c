#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./clientsList.h"


void addNode(char *code, int day, int month, int year, float amount, clientsList *pastNode) {
    clientsList *newNode = (clientsList *)malloc(sizeof(clientsList));
    (*pastNode).next = newNode;
    (*newNode).next = NULL;
    
    memcpy((*newNode).information.fiscalCode, code, sizeof(char)*16);
    (*newNode).information.day = day;
    (*newNode).information.month = month;
    (*newNode).information.year = year;
    (*newNode).information.amount = amount;
}


void dataFetcher(char *filename) {
    FILE *filePointer;

    filePointer = fopen(filename, "rt");

    if (filePointer == NULL)
        printf("Error in opening");

    char code[256];
    int day, month, year;
    float amount;

    clientsList *node = (clientsList *)malloc(sizeof(clientsList));
    clientsList *head = node;

    for (int i=0; i<30; i++) {
        fscanf(filePointer, "%s %d %d %d %f", &code, &day, &month, &year, &amount);
        addNode(code, day, month, year, amount, node);
        node = (*node).next;

        //printf("%0.2f\n", (*node).information.amount);
    }

    node = head;
    while (node != NULL) {
        printf("%0.2f\n", (*node).information.amount);
        node = (*node).next;
    }
    
    fclose(filePointer);

    if (filePointer != 0) 
        printf("Error in closing");
}