#include <stdio.h>


void reset(int *myVar) {
    *myVar = 0;
}


int main() {
    int a = 34;

    printf("Before %d", a);

    reset(&a);

    printf("After %d", a);

    return 0;
    
}


