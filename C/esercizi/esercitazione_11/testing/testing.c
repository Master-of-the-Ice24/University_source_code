#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./clientsList.h"


void createNode(clientsList *pastNode) {
    clientsList *newNode = (clientsList *)malloc(sizeof(clientsList));
    (*newNode).next = NULL;
    (*pastNode).next = newNode;
}

int searchValue(clientsList *node, char *val) {
    while(node != NULL) {
        if ((*node).information.d == "NFSMFK26V77Y723Y") {
            return 0;
        }
        node = (*node).next;
    }
    return 1;
}


void dataFetcher(char *filename) {
    FILE *filePointer;

    filePointer = fopen(filename, "rt");

    if (filePointer == NULL)
        printf("Error in opening");

    clientsList *node = (clientsList *)malloc(sizeof(clientsList));
    clientsList *head = node;
   
    
    /*
    while(c < lines) {
        c++;
        fscanf(filePointer, "%s %d %d %d %f", &(*node).information.fiscalCode, 
                                                        &(*node).information.day, 
                                                        &(*node).information.month, 
                                                        &(*node).information.year, 
                                                        &(*node).information.amount);
        createNode(node);
        node = (*node).next;
    }
    */
    

    for (int i=1; i<31; i++) {
        fscanf(filePointer, "%s %d %d %d %f", &(*node).information.fiscalCode, 
                                                &(*node).information.day, 
                                                &(*node).information.month, 
                                                &(*node).information.year, 
                                                &(*node).information.amount);
        createNode(node);
        node = (*node).next;
    }

    
    
    

    
    node = head;
    int i = 0;
    while ((*node).next != NULL) {
        i++;
        printf("%d)  %s\n", i, (*node).information.fiscalCode);
        node = (*node).next;
    }     
    
    printf("%d ", searchValue(head, "NFSMFK26V77Y723Y"));


    fclose(filePointer);

    if (filePointer != 0) 
        printf("Error in closing");
}