#include <stdio.h>
#include <stdlib.h>
#include "./listaStudenti.h"

void createNode(list *lastNode, int studentID, int value) {
    list *newNode = (list *)malloc(sizeof(list));
    (*newNode).next = NULL;
    
    (*lastNode).next = newNode;
    (*lastNode).data.grade = value;
    (*lastNode).data.studentID = studentID;
}

void updateNode(list *node, int value, int index) {
    for (int i=0; i<=index; i++) {
        if (i < index) {
            node = (*node).next;
            continue;
        } 
        else {
            (*node).data.grade = value;
        }
    }
}

