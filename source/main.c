#include<stdio.h>
#include "systems.h"
#include "io.h"
#include "malloc.h"
int main() {
    char * q = multiply("9354793578947894539", "2138123", 16);
    NUM w = {q, checkLength(q), 0};
    printf("%s", w.val);
    free(q);


    //readfile();
    return 0;
}
