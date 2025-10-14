#include <stdio.h>


int main() {
    int sum=0, num;

    for (int i=0; i<3; i++) {
        printf("Enter number: ");
        scanf("%d", &num);
        sum = sum + num;
    }

    printf("%d", sum);

    return 0;
}
