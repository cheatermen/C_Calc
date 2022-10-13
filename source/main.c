#include<stdio.h>
#include "systems.h"
#include "io.h"
#include "malloc.h"
#include "string.h"
int main() {
    char * q = malloc(SIZE);
    char * p = malloc(SIZE);
    strcpy(q, "AB21314F");
    strcpy(p, "AF2");
    printf("%s", divide_modulo(q, p, 16));

    //readfile();
    return 0;
}
