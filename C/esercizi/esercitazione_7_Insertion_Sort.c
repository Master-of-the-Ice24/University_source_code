#include <stdio.h>
#include <stdlib.h>


void sorting(int *array) {
   // printf("%p", &*array);
    
    int temp, i;
    int finalArray[4];

    for (int i=0; i<3; i++) {
        finalArray[i] = array[i];
        position = i;

        for (int j=i-1; j<3; j++) {
            if (finalArray[j] > finalArray[i]) {
                position = j;
        }

        if (position != i) {
            temp = finalArray[i];

        }
        }
    }
}
    


int main() {
    int unorderedArray[4];

    //printf("%p", &unorderedArray);

    for (int i=0; i<4; i++) {
        scanf("%d", &unorderedArray[i]);
    }

    sorting(unorderedArray);

    printf("\n\n sorted array:\n");

    for (int i=0; i<4; i++) 
        printf("%d\n", unorderedArray[i]);

    return 0;
}
