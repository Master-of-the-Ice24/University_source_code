#include <stdio.h>




int main() {
    FILE *document;
    char c;
    int counter = 0;

    document = fopen("text.text", "r");

    while ((c = fgetc(document)) != EOF) {
        printf("%c", c);
        counter++;
    }

    fclose(document);

    printf("\n%d\n", counter);

    return 0;
}
