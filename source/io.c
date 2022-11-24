#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "systems.h"
#include "string.h"

int readfile(char *argv[]) {
    FILE *fp_in;
    FILE *fp_out;
    char *line = malloc(SIZE);
    size_t len = 0;
    ssize_t read;
    char * path = malloc(SIZE);
    char * path_out = malloc(SIZE);
    strcpy(path, "..\\Examples\\");
    strcpy(path_out, "..\\Examples\\");
    for (int (i) = 0; i < checkLength(argv[1])+1; i++) {
        if ((argv[1][i]) == '.'){
            if (argv[1][i-1] == 'n' && argv[1][i-2] == 'i'){
                argv[1][i-2] = '\0';
                sprintf(path, "%s%sin.txt", path, argv[1] );
                sprintf(path_out, "%s%sout.txt", path_out, argv[1] );
            }else{
                sprintf(path, "%s%s", path, argv[1] );
                argv[1][i] = '\0';
                sprintf(path_out, "%s%s_out.txt", path_out, argv[1]);
                printf("\n%s\n", path_out);
            }
        }
    }

    printf("Otwieranie %s\n", path);
    fp_in = fopen(path, "r");
    fp_out = fopen(path_out, "w");
    if (fp_in == NULL) {
        printf("Plik nie istnieje\n");
        exit(EXIT_FAILURE);
    }
    if (fp_out == NULL) {
        printf("Blad tworzenia pliku wyjscia\n", path_out, errno);
        exit(EXIT_FAILURE);
    }
    char * operation;
    char * system;
    char * score = malloc(SIZE);
    char * val = malloc(SIZE);
    strcpy(val, "0");
    char * temp = malloc(SIZE);

    short start = 0;
    short empty = 0;
    while (fgets(line, SIZE, fp_in)) {
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
                strcpy(score, "0");
                start = 1;
            }
            empty += 1;
        }
        printf("%s", line);
        fprintf(fp_out,"%s", line);
    }
    printf("\nWynik zapisany w %s\n", path_out);

    fclose(fp_in);
    fclose(fp_out);
    free(temp);
    if (line)
        free(line);
    free(path_out);
    free(path);
    return 0;
}

void operations(char *val1, char *val2, char *sys, char *operation) {
    int sys_int = sysCharToInt(sys);
    //if (strcmp(operation, "+")==0&&strcmp(operation, "*")==0&&strcmp(operation, "/")==0&&strcmp(operation, "%")==0&&strcmp(operation, "^")==0){
    //    if (isValidNumber(val1, sys_int)==0 || isValidNumber(val2, sys_int)==0){
    //        strcpy(val1, "-1");
    //        return;
    //    }
    //}
    char * temp;
    deleteZeros(val1);
    deleteZeros(val2);
    deleteZeros(sys);
    deleteZeros(operation);

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
