#include<stdio.h>
#include "systems.h"
#include "io.h"
#include "malloc.h"
#include "string.h"
#include "time.h"
#include "math.h"
int main(int argc, char *argv[]) {
    if (argc == 2){
        readfile(argv);
    }
    return 0;
}
