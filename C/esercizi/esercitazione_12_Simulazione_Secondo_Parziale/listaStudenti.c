#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./listaStudenti.h"


void createNode(list *lastNode, int studentID, int value) {
    list *newNode = (list *)malloc(sizeof(list));
    (*newNode).next = NULL;
    
    (*lastNode).data.studentID = studentID;
    (*lastNode).data.examsNumber = 1;
    (*lastNode).data.summedUpGrades = value;
    (*lastNode).next = newNode;
}

void updateNode(list *node, int value, int index) {
    for (int i=0; i<=index; i++) {
        if (i == index) { 
            (*node).data.summedUpGrades = (*node).data.summedUpGrades + value;
            (*node).data.examsNumber++;
            break;
        }
        node = (*node).next;
    }
}

void searchForDuplicate(list *node, studentInfo *ID, int *index, bool *flag) {
    while ((*node).next != NULL) { 
        if ((*node).data.studentID == (*ID).studentID) {
            *flag = true;
            break;
        }
        node = (*node).next;
        (*index)++;
    }
}

void printNodes(list *node) {
    while((*node).next != NULL) {
        printf(
            "ID:%d, exams:%d, arithmetic average:%0.2f\n", 
            (*node).data.studentID, (*node).data.examsNumber,
            (float)(*node).data.summedUpGrades/(float)(*node).data.examsNumber
        );
        node = (*node).next;
    }
}

