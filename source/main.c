#include<stdio.h>
#include "systems.h"
#include "io.h"
#include "malloc.h"
#include "string.h"
#include "time.h"
int main() {
    char * q = malloc(SIZE);
    char * p = malloc(SIZE);
    strcpy(q, "AB21314F");
    strcpy(p, "FA");
    clock_t begin = clock();
    printf("%s", power(q, p, 16));
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n%f", time_spent);
    //212_2 //3
    //  _16
    //readfile();
    return 0;
}
