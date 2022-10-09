#include <stdio.h>
#include <stdlib.h>
#include "io.h"

int readfile() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("\n\n");
    fp = fopen("../examples/lk-01-in", "r");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("%s", line);
    }

    fclose(fp);
    if (line)
        free(line);
    return 0;
}