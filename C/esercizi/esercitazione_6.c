#include <stdio.h>


float absoluteValue(float value) {
    if (value >= 0)
        return value;
    return -value;
}


float radiceN(float a, int N) {
    float x = 1;
    float p;
    
    do {
      p = 1;

      for (int i=0; i<N-1; i++) 
          p = p*x;

      x = (((N-1)*p*x) + a)/(N*p);

    } while (absoluteValue((p*x)-a)/a > 0.00001);

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
