#include <stdio.h>


int main() {
    FILE *document;
    char c;

    document = fopen("text", "r");

    fscanf(document, "%c", &c);

    return 0;
}
