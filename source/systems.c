#include "systems.h"
#include <math.h>
#include <string.h>
#include <malloc.h>

char numToChar(int num){
    char strings[17] = {
            '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F', '\0'
    };
    return strings[num];
}

int charToNum(char ch){
    int num;
    if (ch == 'A'){
        num = 10;
    }else if(ch == 'B'){
        num = 11;
    }else if (ch == 'C'){
        num = 12;
    }else if (ch == 'D'){
        num = 13;
    }else if (ch == 'E')
    {
        num = 14;
    }else if (ch == 'F')
    {
        num = 15;
    }else if (ch == '0' || ch == '1' || ch== '2' || ch=='3'|| ch=='4'|| ch=='5'|| ch=='6'|| ch=='7'|| ch=='8'|| ch=='9'){
        num = (int)(ch - '0');
    }
    else{
        num = 0;
    }

    return num;
}

char sys_char_to_char(char *sys_char) {
    if(strcmp(sys_char, "15")==0){
        return 'F';
    }else if(strcmp(sys_char, "14")==0){
        return 'E';
    }else if(strcmp(sys_char, "13")==0){
        return 'D';
    }else if(strcmp(sys_char, "12")==0){
        return 'C';
    }else if(strcmp(sys_char, "11")==0){
        return 'B';
    }else if(strcmp(sys_char, "10")==0) {
        return 'A';
    }else if(strcmp(sys_char, "9")==0) {
        return '9';
    }else if(strcmp(sys_char, "8")==0) {
        return '8';
    }else if(strcmp(sys_char, "7")==0) {
        return '7';
    }else if(strcmp(sys_char, "6")==0) {
        return '6';
    }else if(strcmp(sys_char, "5")==0) {
        return '5';
    }else if(strcmp(sys_char, "4")==0) {
        return '4';
    }else if(strcmp(sys_char, "3")==0) {
        return '3';
    }else if(strcmp(sys_char, "2")==0) {
        return '2';
    }else if(strcmp(sys_char, "1")==0) {
        return '1';
    }else if(strcmp(sys_char, "0")==0) {
        return '0';
    }
    return '0';
}

char* reverse(char* string){
    char *buf = malloc(SIZE);
    strcpy(buf,"");

    int sup = checkLength(string);
    int i = 0;

    while(i<=sup){
        buf[i] = string[sup - i];
        i+=1;
    }
    buf[i] = '\0';

    strcpy(string, buf);
    free(buf);
    return string;
}

int checkLength(const char* string){
    int sup=0;


    while (string[sup] != '\0'){
        sup+=1;
    }
    sup--;

    return sup;
}

char *add_zero(char *num) {
    char * buf = malloc(SIZE);
    strcpy(buf, num);
    int i = checkLength(buf);
    buf[i+1] = '0';
    buf[i+2] = '\0';
    return buf;
}

char *slice(char *val, int x, int y) {
    char * slice = malloc(y-x+2);
    int i = 0;
    while(x<=y){
        slice[i] = val[x];
        i+=1;
        x+=1;
    }
    slice[i] = '\0';
    return slice;
}

short comp(char *num1, char *num2) {
    if (strcmp(num1, num2) == 0){
        return 0;
    }
    int i1 =  checkLength(num1);
    int i2 = checkLength(num2);
    if (i1 > i2){
        return 1;
    }else if (i1 < i2){
        return 2;
    }else{
        for (int x = 0; x < i1 + 1; x++){
            int v1 = charToNum(num1[x]);
            int v2 = charToNum(num2[x]);
            if (v1 > v2){
                return 1;
            }else if (v1 < v2){
                return 2;
            }
        }
    }
    return 3;
}


char *decToSys(char *val, int sys) {
    char * sys_char= malloc(4*sizeof(char));
    char * buf = malloc(SIZE);
    char * buf2;
    char * buf3 = malloc(SIZE);
    char * solution = malloc(SIZE);
    char * zero = malloc(sizeof(char)*2);
    sprintf(zero, "%d", 0);

    sprintf(sys_char, "%d", sys);
    strcpy(buf, val);
    int i = 0;
    while(comp(buf,zero)!=0){
        buf3 = divide_modulo(buf, sys_char ,10);
        buf2 = divide(buf,sys_char,10);
        strcpy(buf, buf2);
        solution[i] = sys_char_to_char(buf3);
        i+=1;
    }
    solution[i]='\0';
    reverse(solution);
    return solution;
    // char *string = malloc(SIZE);
    // int i = 0;

    // while (num != 0){
    //     if (i > 40){
    //         printf("Num too long");
    //         return 0;
    //     }
    //     string[i] = numToChar(num % sys);
    //     num = num / sys;
    //     i+=1;
    // }
    // string[i] = '\0';

    // string = reverse(string);
    // return string;
}


char *sysToDec(char *val, int sys) {
    reverse(val);
    char * buf;
    char * buf2;
    char * multiplier = malloc(SIZE);
    char * solution = malloc(SIZE);
    char * sys_char = malloc(SIZE);
    char * p = malloc(SIZE);
    strcpy(solution, "0");
    for(int i = 0; i<= checkLength(val); i+=1){
        sprintf(sys_char, "%d", sys);
        sprintf(p, "%d", i);
        buf = power(sys_char, p, 10);

        sprintf(multiplier, "%d", charToNum(val[i]));
        buf2 = multiply(buf, multiplier, 10);
        free(buf);
        buf = addition(solution, buf2, 10);
        strcpy(solution, buf);
        free(buf);
        free(buf2);
    }
    free(sys_char);
    free(multiplier);
    reverse(val);
    return solution;
    //long long dec = 0;
    //int sup=0;
    //while (string[sup]!='\0'){
    //    sup+=1;
    //}
    //sup--;
    //for(int i = sup; i >= 0; i--){
    //    int buf = charToNum(string[i]);
    //    dec+=pow(sys,sup - i)*buf;
    //}
    //return dec;
}

char* addition(char* val1, char*val2, int sys){
    char* buf1 = malloc(SIZE);
    char* buf2 = malloc(SIZE);
    reverse(strcpy(buf1, val1));
    reverse(strcpy(buf2, val2));

    int length = checkLength(buf2);

    for (int i = 0; i <= length; i++) {
        buf1 = recursive_addition(buf1, buf2[i], i, sys);
    }
    free(buf2);
    return reverse(buf1);
}

char *recursive_addition(char *val1, char digit1, int pos, int sys) {
    int sum = charToNum(val1[pos]) + charToNum(digit1);
    if (pos > checkLength(val1)){
        val1[pos + 1] = '\0';
    }
    if (sum >= sys){
        val1[pos] = numToChar(sum % sys); // 12 02
        val1 = recursive_addition(val1, numToChar(sum / sys), pos + 1, sys);
    }else{
        val1[pos] = numToChar(sum);
    }
    return val1;
}

char *multi_by_one(char *digit, char num, int pos, int sys) {
    char * sum = malloc(SIZE);
    strcpy(sum, "0");
    int a = charToNum(num);
    if (a==0){
        return sum;
    }

    char * half[4];
    half[0] = malloc(SIZE);
    strcpy(half[0], digit);

    int i = 1, z = 2;
    while(z < a) {
        half[i] = malloc(SIZE);
        half[i] = addition(half[i - 1], half[i - 1], sys);
        z *= 2;
        i += 1;
    }
    i--;
    z=z/2;
    int o = i;

    while(a!=0){
        if ((a-z) >= 0){
            char * temp_sum = addition(half[i], sum, sys);
            strcpy(sum, temp_sum);
            free(temp_sum);
            a -= z;
        }else{
            i-=1;
            z=z/2;
        }
    }

    for(i=0;i<o;i++){
        free(half[i]);
    }
    for (i=0;i<pos;i++){
        char * temp = sum;
        sum = add_zero(temp);
        free(temp);
    }
    return sum;
}

char *multiply(char *val1, char *val2, int sys) {
    char * sum = malloc(SIZE);
    char * buf = malloc(SIZE);
    strcpy(buf, val2);
    reverse(buf);
    strcpy(sum, "0");

    int lim = checkLength(val2);
    for (int i=0;i<=lim;i++){
        char * temp = multi_by_one(val1, buf[i], i, sys);
        char * temp2 = addition(sum, temp, sys);
        free(sum);
        free(temp);
        sum = temp2;
    }
    return sum;
}

char *power(char *val1, char *val2, int sys) {
    char * solution = malloc(SIZE);
    strcpy(solution, "1");

    if (strcmp(val2, "0") == 0){
        return solution;
    }
    char * half[SIZE];
    char * index[SIZE];
    half[0] = malloc(SIZE);
    index[0] = malloc(SIZE);
    strcpy(index[0], "1");
    strcpy(half[0], val1);
    long long i = 1;
    long long z = 2;
    char * q = malloc(sizeof(char)*2);
    strcpy(q, "2");

    short c = comp(index[0], val2);
    while(c == 2){
        half[i] = malloc(SIZE);
        index[i] = malloc(SIZE);
        half[i] = multiply(half[i - 1], half[i - 1], sys);
        index[i] = multiply(index[i-1], q, sys);
        c = comp(index[i], val2);
        i += 1;
        z *= 2;
    }

    long long o = i;
    i--;
    z=z/2;

    char * buf1 = malloc(SIZE);
    strcpy(buf1, "0");

    while(comp(buf1, val2) != 0) { // 8, 0->8. 8 9
        char * temp_con = addition(index[i], buf1, sys);
        if (comp(temp_con, val2) == 2 || comp(temp_con, val2) == 0){
            char * temp_sum = multiply(half[i], solution, sys);
            strcpy(solution, temp_sum);
            free(temp_sum);
            temp_sum = addition(buf1, index[i], sys);
            strcpy(buf1, temp_sum);
            free(temp_sum);
        }else{
            i-=1;
            z=z/2;
        }
        free(temp_con);
    }
    for (int x = 0; x < o; x++){
        free(half[x]);

    }
    free(buf1);
    free(q);
    return solution;
}

char *divide(char *val1, char *val2, int sys) {
    char * solution = malloc(SIZE);
    char * comp_var = malloc(SIZE);
    char * one = malloc(sizeof(char)*2);
    strcpy(one, "1");
    strcpy(solution, "0");
    strcpy(comp_var, val2);

    while(comp(val1, comp_var) == 1 || comp(val1,comp_var)==0){
        char * temp1 = malloc(SIZE);
        char * temp2 = malloc(SIZE);
        temp1 = addition(comp_var, val2, sys);
        temp2 = addition(solution, one, sys);
        strcpy(comp_var, temp1);
        strcpy(solution, temp2);
        free(temp1);
        free(temp2);
    }
    free(one);
    free(comp_var);
    return solution;
}

char *divide_modulo(char *val1, char *val2, int sys) {
    char * limit = malloc(SIZE);
    char * comp_var = malloc(SIZE);
    strcpy(limit, val2);
    strcpy(comp_var, "0");

    while(comp(val1, limit) == 1){
        char * temp1 = malloc(SIZE);
        char * temp2 = malloc(SIZE);
        temp1 = addition(comp_var, val2, sys);
        temp2 = addition(temp1, val2, sys);
        strcpy(comp_var, temp1);
        strcpy(limit, temp2);
        free(temp1);
        free(temp2);
    }

    char * solution = malloc(SIZE);
    char * one = malloc(sizeof(char)*2);
    strcpy(solution, "0");
    strcpy(one, "1");

    if (comp(comp_var, val1) == 0){
        return solution;
    }
    while(comp(comp_var, val1)!=0){
        char * temp1 = malloc(SIZE);
        char * temp2 = malloc(SIZE);
        temp1 = addition(comp_var, one, sys);
        temp2 = addition(solution, one, sys);
        strcpy(comp_var,temp1);
        strcpy(solution, temp2);
        free(temp1);
        free(temp2);
    }
    free(one);
    free(comp_var);
    return solution;
}
