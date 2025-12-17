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
        while (subnode != NULL) {
            if ((*subnode).data.studentID == ID.studentID) {
                flag = true;
                break;
            }
            subnode = (*subnode).next;
            index++;
        }

        if (flag == false) {
            createNode(node, ID.studentID, ID.grade);
            node = (*node).next;
        } else {
            updateNode(head, ID.grade, index);
        }

        flag = false;
        subnode = head;
        index = 0;
    }


    node = head;
    int c;
    while (node != NULL) {
        printf("%d %d %d\n", (*node).data.studentID, (*node).data.grade, c);
        node = (*node).next;
        c++;
    }

    /*
    int i=0;
    while (i<4) {
        while (i<3) {
            if (i=2) {
                flag = true;
                break;
            }            
        }
        i++;
    }

    printf("%d ", flag);
    */

    
    
    
    

    if (fclose(fp) != 0)
        printf("Error in closing");

    return 0;
}