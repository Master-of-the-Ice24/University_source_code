#include <stdio.h>
#include <stdlib.h>
#include "listaStudenti.h"


int main(int argc, char **argv) {
    FILE *fp;
    
    fp = fopen(argv[1], "rb");
    
    if (fp == NULL) {
        printf("Error in opening");
        exit(1);
    }
    
    studentInfo test;
    while((fread(&test, sizeof(studentInfo), 1, fp)) != 0) {
        printf("%d %s %d %d %d\n", test.studentID, test.exam, test.day, test.month, test.year, test.grade);
    }    
    

    if (fclose(fp) != 0)
        printf("Error in closing");

    return 0;
}