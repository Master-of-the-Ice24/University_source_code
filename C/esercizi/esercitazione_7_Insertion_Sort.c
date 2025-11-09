#include <stdio.h>
#include <stdlib.h>


int main() {
    int unorderedArray[10];

    for (int i=0; i<4; i++) {
        scanf("%d", &unorderedArray[i]);
    }

    for (int i=0; i<10; i++) 
        printf("%d\n", unorderedArray[i]);

    return 0;
}
