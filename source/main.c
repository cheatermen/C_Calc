#include<stdio.h>
#include "systems.h"
#include "io.h"
#include "malloc.h"
int main() {
    //printf("\n dodawanko: %s", multi_by_one("FB2FFFF24F6FF7F7FF", 'B', 16) );
    char * q = multiply("9354793578947894539", "2138123", 16);
    printf("%s", q);
    free(q);


    //readfile();
    return 0;
}
