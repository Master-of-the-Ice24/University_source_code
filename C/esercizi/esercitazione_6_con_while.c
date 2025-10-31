#include <stdio.h>


float absoluteValue(float value) {
    if (value >= 0)
        return value;
    return -value;
}


float radiceN(float a, int N) {
    float x = 1;
    float p;
    
    while (absoluteValue((p*x)-a)/a > 0.00001) {
        p = 1;
        int i = 0;

        while (i < N-1) {
            p = p*x;
            i++;
        }

      x = (((N-1)*p*x) + a)/(N*p);

    }

    return x;

}


int main(void) {
    float y;
    int M;

    scanf("%f%d", &y, &M);

    for (int i=2; i<=M; i++) {
        printf("%0.6f\n", radiceN(y, i));
    }

    return 0;
}

