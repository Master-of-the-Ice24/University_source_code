#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./clientsList.h"


void createNode(clientsList *pastNode) {
    clientsList *newNode = (clientsList *)malloc(sizeof(clientsList));
    (*newNode).next = NULL;
    (*pastNode).next = newNode;
}


void dataFetcher(char *filename) {
    FILE *filePointer;

    filePointer = fopen(filename, "rt");

    if (filePointer == NULL)
        printf("Error in opening");


    clientsInfo mylist[31];
    clientsInfo narrow[31];
    

    for (int i=0; i<30; i++) {
        fscanf(filePointer, "%s %d %d %d %f", &(mylist[i]).fiscalCode, 
                                                &(mylist[i]).day, 
                                                &(mylist[i]).month, 
                                                &(mylist[i]).year, 
                                                &(mylist[i]).amount);
    }

    bool duplicate = false;
    int clientsCounter = 0;
    for (int i=0; i<30; i++) {
        duplicate = false;
        for (int j=i+1; j<30; j++) {
            if (strcmp(mylist[i].fiscalCode, mylist[j].fiscalCode) == 0) {
                duplicate = true;
                break;
            }
        }
        if (duplicate == false) {
            memcpy(&narrow[clientsCounter].fiscalCode, &mylist[i].fiscalCode, sizeof(mylist[i].fiscalCode));
            clientsCounter++;
        }
    }

    clientsList *node = (clientsList *)malloc(sizeof(clientsList));
    clientsList *head = node;

    for (int i=0; i<clientsCounter; i++) {
        for (int j=i+1; i<clientsCounter; j++){
            if (strcmp(narrow[i].fiscalCode, narrow[j].fiscalCode) > 0) {
                memcpy(&(*node).information.fiscalCode, &narrow[j].fiscalCode, sizeof(narrow[i].fiscalCode));
            } else {
                memcpy(&(*node).information.fiscalCode, &narrow[i].fiscalCode, sizeof(narrow[i].fiscalCode));
            }

            break;
        }

        createNode(node);
        node = (*node).next;
    }




    /*
    for (int i=0; i<clientsCounter; i++)
        printf("%d) %s\n", i, narrow[i].fiscalCode);
    */

    node = head;
    int i = 0;
    while ((*node).next != NULL) {
        i++;
        printf("%d)  %s\n", i, (*node).information.fiscalCode);
        node = (*node).next;
    } 
    
    fclose(filePointer);

    if (filePointer != 0) 
        printf("Error in closing");
}