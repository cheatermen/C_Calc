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

    fp_in = fopen("examples/lk-01-in", "r");
    fp_out = fopen("examples/lk-01-out.txt", "w");
    if (fp_in == NULL) {
        fp_in = fopen("examples/lk-01-in.txt", "r");
        if(fp_in == NULL){
            exit(EXIT_FAILURE);
        }
    }
    if (fp_out == NULL) {
        fp_out = fopen("examples/lk-01-out.txt", "r");
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
                    operation = strtok(temp, " ");
                    system = strtok(NULL, " ");
                    space = 1;
                    start = 1;
                    strcpy(score, "0");
                }
            }
            if (space == 0){
                if (start == 1){
                    sprintf(score,"%s", line);
                    deleteEndl(score);
                    start = 0;
                    if (strcmp(operation,"+")!=0 && strcmp(operation,"*")!=0 && strcmp(operation,"/")!=0 &&
                    strcmp(operation,"%")!=0 && strcmp(operation,"^")!=0){
                        operations(score,val,system,operation);
                    }
                }else{
                    sprintf(val,"%s", line);
                    deleteEndl(val);
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

    fclose(fp_in);
    fclose(fp_out);
    free(temp);
    if (line)
        free(line);
    return 0;
}

void operations(char *val1, char *val2, char *sys, char *operation) {
    int sys_int = sysCharToInt(sys);
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
        temp = divideModulo(val1, val2, sys_int);
    }else{
        char * buf;
        buf = sysToDec(val1, sysCharToInt(operation));
        temp = decToSys(buf, sysCharToInt(sys));
        free(buf);
    }
    strcpy(val1, temp);
    free(temp);
}
