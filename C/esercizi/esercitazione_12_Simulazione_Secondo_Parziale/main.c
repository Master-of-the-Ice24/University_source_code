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
    list *head = node;

    studentInfo studentID;
    bool flag = false;
    list *subnode = node;

    while (node == NULL) {
        fread(&studentID, sizeof(studentInfo), 1, fp);

        while (subnode == NULL) {
            if ((*subnode).data.studentID == studentID.studentID) {
                flag = true;
                break;
            }
            subnode = (*subnode).next;
        }

        if (flag == false) {
            createNode(node, studentID.grade);
        } else {
            //update value
        }

        node = (*node).next;
        subnode = head;
        flag = false;
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