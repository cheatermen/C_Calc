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

    short start = 0;
    char * val1 = malloc(SIZE);
    char * val2 = malloc(SIZE);
    int vals_count = 0;
    char ** vals;
    vals = calloc(10, sizeof (char *));
    int y = 0;
    while ((read = getline(&line, &len, fp_in)) != -1) {
        fprintf(fp_out,"%s", line);
        if (strcmp(line, "\n")!=0){
            short space = 0;
            for(int i = 0; i < checkLength(line);i++){
                if (line[i] == ' '){
                    if (start == 1){
                        char * temp;
                        temp = operations(val1,val2,vals, vals_count);
                        fprintf(fp_out,"%s", temp);
                        free(temp);
                        for(int x = 0; x < vals_count; x++){
                            free(vals[x]);
                        }
                        vals_count = 0;
                    }else{
                        start = 1;
                    }

                    memcpy(val1, line, sizeof(char)*i);
                    memcpy(val2, line+i+1, sizeof(char)* checkLength(line)-i-1);
                    printf("|%s,%s|", val1, val2);
                    printf(" |%d| ", i);
                    space = 1;
                }
            }
            if (space == 0){
                vals[vals_count] = calloc(SIZE, sizeof (char ));
                memcpy(vals[vals_count], line, sizeof(char )* checkLength(line));
                printf(" |%s,%d| ", vals[vals_count], vals_count);
                vals_count += 1;
            }else{
            }
        }
        printf("%s", line);
        y+=1;
    }
    free(val1);
    free(val2);

    fclose(fp_in);
    fclose(fp_out);
    if (line)
        free(line);
    return 0;
}

char * operations(char *val1, char *sys, char ** vals, int vals_count) {
    char * score = malloc(SIZE);
    strcpy(score, vals[0]);
    int sys_int = what_sys(sys);
    for(int i = 1; i < vals_count; i++){
        char * temp;
        if(strcmp(val1, "+")==0){
            temp = addition(score, vals[i], sys_int);
        }else if(strcmp(val1, "*")==0){
            temp = multiply(score, vals[i], sys_int);
        }else if(strcmp(val1, "^")==0){
            temp = power(score, vals[i], sys_int);
        }else if(strcmp(val1, "/")==0){
            temp = divide(score, vals[i], sys_int);
        }else if(strcmp(val1, "%")==0){
            temp = divide_modulo(score, vals[i], sys_int);
        }else{
            temp = malloc(SIZE);
        }
        strcpy(score, temp);
        free(temp);
    }
    return score;
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
