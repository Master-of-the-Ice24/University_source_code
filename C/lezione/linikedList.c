#include <stdio.h>
#include <stdlib.h>


typedef struct mynode {
    int num;
    struct mynode *next;
} Node;


Node *addNode(int val, Node *lastNode) {
    Node *newNode = malloc(sizeof(Node));
    void *closer = NULL;

    lastNode->next = newNode;
    newNode->num = val;

    return newNode;
}


int main() {

    Node *head = NULL;
    Node *first = NULL;
    Node *second = NULL;

    first = malloc(sizeof(Node));
    second = malloc(sizeof(Node));

    head = first;

    (*first).num = 10;
    (*first).next = second;

    (*second).num = 1;
    (*second).next = NULL;

    /*
    while (head != NULL) {
        printf("%d ", head->num);
        head = head->next;
    }
    */

    addNode(13, second);

    while (head != NULL) {
        printf("%d ", head->num);
        head = head->next;
    }

    return 0;
}