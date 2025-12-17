#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./listaStudenti.h"


void createNode(list *lastNode, int studentID, int value) {
    list *newNode = (list *)malloc(sizeof(list));
    (*newNode).next = NULL;
    (*newNode).data.studentID = studentID;
    (*newNode).data.examsNumber = 1;
    (*newNode).data.summedUpGrades = value;
    
    (*lastNode).next = newNode;
    
}

void updateNode(list *node, int value, int index) {
    for (int i=0; i<=index; i++) {
        if (i < index) {
            node = (*node).next;
            continue;
        } 
        else {
            (*node).data.summedUpGrades = (*node).data.summedUpGrades + value;
            (*node).data.examsNumber++;
        }
    }
}

void searchForDuplicate(list *node, studentInfo *ID, int *index, bool *flag) {
    while (node != NULL) { //(*node).next
        if ((*node).data.studentID == (*ID).studentID) {
            *flag = true;
            break;
        }
        node = (*node).next;
        (*index)++;
    }
}

void printNodes(list *node) {
    while(node != NULL) {
        printf("ID:%d, exams:%d, total grades:%d\n", (*node).data.studentID, (*node).data.examsNumber, (*node).data.summedUpGrades);
        node = (*node).next;
    }
}

