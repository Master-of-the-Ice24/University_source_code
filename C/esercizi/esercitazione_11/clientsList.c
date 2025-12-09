#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char **splitter(char *line) {
    char **splitted = (char **)malloc(4*sizeof(char *));
    int lenght = 0, start = 0, innerIndex = 0;

    for (int i=0; line[i]!='\0'; i++) {
        if (line[i] == ' ') {
            lenght = i - start;
            splitted[innerIndex] = (char *)malloc(256*sizeof(char));
            strncpy(splitted[innerIndex], line + start, lenght);
            splitted[innerIndex][lenght] = '\0';
            innerIndex++;
            start = i + 1;
        }
    }

    int finalPosition = strlen(line);
    int finalLength = finalPosition - start;
    splitted[innerIndex] = (char *)malloc(256*sizeof(char));
    strncpy(splitted[innerIndex], line + start, finalLength);
    splitted[innerIndex][finalLength] = '\0';
    splitted[innerIndex + 1] = NULL;

    return splitted;
}
    
    
int main() {
    char example[256] = "HRNTZV39Y56X303E 5 6 2023 818.50";

    char **result = splitter(example);

    for (int i=0; i<5; i++) 
        printf("\n%d:  %s ", i, result[i]);

    return 0;
}