#include <stdio.h>
#include <stdlib.h>
#include "./listaStudenti.h"

void createNode(list *lastNode, int value) {
    list *newNode = (list *)malloc(sizeof(list));
    newNode = NULL;
    (*lastNode).next = newNode;
    (*lastNode).data.grade = value;
}

