#include<stdio.h>
#include "systems.h"
#include "io.h"
#include "malloc.h"
#include "string.h"
int main() {
    char * q = malloc(SIZE);
    char * p = malloc(SIZE);
    strcpy(q, "921300");
    strcpy(p, "9");
    printf("\n\n%s", power(q, p, 10));

    //readfile();
    return 0;
}
