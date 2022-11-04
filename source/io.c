#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "systems.h"
#include "string.h"

int readfile() {
    FILE *fp_in;
    FILE *fp_out;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("\n\n");
    fp_in = fopen("../examples/lk-01-in", "r");
    fp_out = fopen("../examples/lk-01-out", "w");
    if (fp_in == NULL) {
        exit(EXIT_FAILURE);
    }

    char * operation;
    char * system;
    char * score = malloc(SIZE);
    char * val = malloc(SIZE);
    char * temp = malloc(SIZE);

    short start = 0;
    short empty = 0;
    while ((read = getline(&line, &len, fp_in)) != -1) {
        if (strcmp(line, "\n")!=0){
            short space = 0;
            empty = 0;
            for(int i = 0; i < checkLength(line);i++){
                if (line[i] == ' '){
                    strcpy(temp,line);
                    temp[checkLength(line)]='\0';
                    //printf("%s", line);
                    operation = strtok(temp, " ");
                    system = strtok(NULL, " ");
                    //printf("|%s,%s| ", operation, system);
                    space = 1;
                    start = 1;
                }
            }
            if (space == 0){
                if (start == 1){
                    memcpy(score, line, sizeof(char )* checkLength(line));
                    start = 0;
                }else{
                    memcpy(val, line, sizeof(char )* checkLength(line));
                    operations(score, val, system, operation);
                }
            }
        }else{
            if (empty == 1){
                fprintf(fp_out,"%s", score);
                printf("%s", score);
            }
            empty += 1;
        }
        printf("%s", line);
        fprintf(fp_out,"%s", line);
    }
    //free(operation);
    //free(system);

    fclose(fp_in);
    fclose(fp_out);
    free(temp);
    if (line)
        free(line);
    return 0;
}

void operations(char *val1, char *val2, char *sys, char *operation) {
    int sys_int = what_sys(sys);
    char * temp;
    if(strcmp(operation, "+") == 0){
        temp = addition(val1, val2, sys_int);
    }else if(strcmp(operation, "*") == 0){
        temp = multiply(val1, val2, sys_int);
    }else if(strcmp(operation, "^") == 0){
        temp = power(val1, val2, sys_int);
    }else if(strcmp(operation, "/") == 0){
        temp = divide(val1, val2, sys_int);
    }else if(strcmp(operation, "%") == 0){
        temp = divide_modulo(val1, val2, sys_int);
    }else{
        return;
    }
    strcpy(val1, temp);
    free(temp);
}

int what_sys(char *sys_char) {
    int sys;
    if (strcmp(sys_char, "1")==0){
        sys = 1;
    }else if (strcmp(sys_char, "2")==0){
        sys = 2;
    }else if (strcmp(sys_char, "3")==0){
        sys = 3;
    }else if (strcmp(sys_char, "4")==0){
        sys = 4;
    }else if (strcmp(sys_char, "5")==0){
        sys = 5;
    }else if (strcmp(sys_char, "6")==0){
        sys = 6;
    }else if (strcmp(sys_char, "7")==0){
        sys = 7;
    }else if (strcmp(sys_char, "8")==0){
        sys = 8;
    }else if (strcmp(sys_char, "9")==0){
        sys = 9;
    }else if (strcmp(sys_char, "10")==0){
        sys = 10;
    }else if (strcmp(sys_char, "11")==0){
        sys = 11;
    }else if (strcmp(sys_char, "12")==0){
        sys = 12;
    }else if (strcmp(sys_char, "13")==0){
        sys = 13;
    }else if (strcmp(sys_char, "14")==0){
        sys = 14;
    }else if (strcmp(sys_char, "15")==0){
        sys = 15;
    }else if (strcmp(sys_char, "16")==0){
        sys = 16;
    }else{
        sys = 0;
    }
    return sys;
}