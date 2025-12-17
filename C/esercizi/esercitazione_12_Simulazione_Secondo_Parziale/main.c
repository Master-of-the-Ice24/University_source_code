#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listaStudenti.h"


int main(int argc, char **argv) {
    FILE *fp;
    
    fp = fopen(argv[1], "rb");
    
    if (fp == NULL) {
        printf("Error in opening");
        exit(1);
    }
    
    list *node = (list *)malloc(sizeof(list));
    (*node).next = NULL;
    list *head = node;

    studentInfo ID;
    bool flag = false;
    list *subnode = head;
    int index = 0;

    while ((fread(&ID, sizeof(studentInfo), 1, fp) != 0)) {
        subnode = head;
        searchForDuplicate(subnode, &ID, &index, &flag);

        if (flag == false) {
            createNode(node, ID.studentID, ID.grade);
            node = (*node).next;
        } else {
            subnode = head;
            updateNode(subnode, ID.grade, index);
        }

        flag = false;
        index = 0;
    }

    node = head;
    printNodes(node);

    if (fclose(fp) != 0)
        printf("Error in closing");

    return 0;
}