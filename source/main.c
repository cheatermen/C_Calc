#include<stdio.h>
#include "systems.h"
#include "io.h"
#include "malloc.h"
#include "string.h"
#include "time.h"
#include "math.h"
int main() {
    char * q = malloc(SIZE);
    char * p = malloc(SIZE);
    strcpy(q, "AB21314F");
    //strcpy(p, "FA");
    printf("%s", slice(q, 4, 6));
    //212_2 //3
    //  _16
    //readfile();
    return 0;
}
