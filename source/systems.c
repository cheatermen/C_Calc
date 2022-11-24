#include "systems.h"
#include <string.h>
#include <malloc.h>
#include "stdio.h"



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
int sysCharToInt(char *sys_char) {
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
char sysCharToChar(char *sys_char) {
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

short isValidNumber(char *val, int sys) {
    for (int i = 0; i < checkLength(val)+1; i++){
        int x = charToNum(val[i]);
        if(charToNum(val[i])>=sys){
            return 0;
        }
    }
    return 1;
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


char *deleteEndl(char *string) {
    long max = checkLength(string);
    for(int i = 0; i<max+1;i++){
        if (string[i]=='\n'){
            string[i] = '\0';
            break;
        }
    }
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

char *addZero(char *num) {
    char * buf = malloc(SIZE);
    strcpy(buf, num);
    int i = checkLength(buf);
    buf[i+1] = '0';
    buf[i+2] = '\0';
    return buf;
}

void *deleteZeros(char *num) {
    reverse(num); // 00001 // 1000 00231 13200 231
    for (int i = checkLength(num); i >= 0; i--){
        if (num[i] != '0'){
            num[i+1] = '\0';
            reverse(num);
            break;
        }
    }
    return 0;
}

char * slice(char *val, int x, int y) {
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
    char * solution = malloc(SIZE);
    if(strcmp(val, "-1")==0){
        strcpy(solution, "-1");
        return solution;
    }
    char * sys_char= malloc(4*sizeof(char));
    char * buf = malloc(SIZE);
    char * buf2;
    char * buf3;
    char * zero = malloc(sizeof(char)*2);
    sprintf(zero, "%d", 0);
    sprintf(sys_char, "%d", sys);
    strcpy(buf, val);
    int i = 0;
    while(comp(buf,zero)!=0){
        buf3 = divideModulo(buf, sys_char, 10);
        buf2 = divide(buf,sys_char,10);
        strcpy(buf, buf2);
        solution[i] = sysCharToChar(buf3);
        free(buf2);
        free(buf3);
        i+=1;
    }
    solution[i]='\0';
    reverse(solution);
    free(zero);
    free(buf);
    free(sys_char);
    return solution;
}


char *sysToDec(char *val, int sys) {
    char * solution = malloc(SIZE);
    if(strcmp(val, "-1")==0){
        strcpy(solution, "-1");
        return solution;
    }
    reverse(val);
    char * buf;
    char * buf2;
    char * multiplier = malloc(SIZE);
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
    free(p);
    reverse(val);
    return solution;
}

char* addition(char* val1, char*val2, int sys){
    char* buf1 = malloc(SIZE);
    if(strcmp(val1, "-1") == 0 || strcmp(val2, "-1") == 0){
        strcpy(buf1, "-1");
        return buf1;
    }
    char* buf2 = malloc(SIZE);
    reverse(strcpy(buf1, val1));
    reverse(strcpy(buf2, val2));

    int length = checkLength(buf2);

    for (int i = 0; i <= length; i++) {
        buf1 = recursiveAddition(buf1, buf2[i], i, sys);
    }
    free(buf2);
    return reverse(buf1);
}

char *recursiveAddition(char *val1, char digit1, int pos, int sys) {
    int sum = charToNum(val1[pos]) + charToNum(digit1);
    if (pos > checkLength(val1)){
        val1[pos + 1] = '\0';
    }
    if (sum >= sys){
        val1[pos] = numToChar(sum % sys); // 12 02
        val1 = recursiveAddition(val1, numToChar(sum / sys), pos + 1, sys);
    }else{
        val1[pos] = numToChar(sum);
    }
    return val1;
}

char *multiByOne(char *digit, char num, int pos, int sys) {
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

    for(i=0;i<=o;i++){
        free(half[i]);
    }
    for (i=0;i<pos;i++){
        char * temp = sum;
        sum = addZero(temp);
        free(temp);
    }
    return sum;
}

char *multiply(char *val1, char *val2, int sys) {
    char * sum = malloc(SIZE);
    if(strcmp(val1, "-1") == 0 || strcmp(val2, "-1") == 0){
        strcpy(sum, "-1");
        return sum;
    }
    if(strcmp(val1, "0") == 0 || strcmp(val2, "0") == 0){
        strcpy(sum, "0");
        return sum;
    }
    char * buf = malloc(SIZE);
    strcpy(buf, val2);
    reverse(buf);
    strcpy(sum, "0");

    int lim = checkLength(val2);
    for (int i=0;i<=lim;i++){
        char * temp = multiByOne(val1, buf[i], i, sys);
        char * temp2 = addition(sum, temp, sys);
        strcpy(sum, temp2);
        free(temp);
        free(temp2);
    }
    free(buf);
    return sum;
}

char *power(char *val1, char *val2, int sys) {
    char * solution = malloc(SIZE);
    strcpy(solution, "1");

    if(strcmp(val1, "-1") == 0 || strcmp(val2, "-1") == 0){
        strcpy(solution, "-1");
        return solution;
    }
    if (strcmp(val2, "0") == 0){
        if(strcmp(val1, "0") == 0){
            strcpy(solution, "0");
            return solution;
        }
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
    if(strcmp(val1, "-1") == 0 || strcmp(val2, "-1") == 0){
        strcpy(solution, "-1");
        return solution;
    }
    if(comp(val2,"1")==0){
        strcpy(solution, val1);
        return solution;
    }
    if(comp(val2,"0")==0){
        strcpy(solution, "0");
        return solution;
    }
    char * buf;
    char * sum = malloc(SIZE);
    char * buf2;
    char * power_i = malloc(SIZE);
    char * one = malloc(SIZE);
    char ** powers = malloc(SIZE);
    char ** powers_i = malloc(SIZE);

    strcpy(solution, "0");
    strcpy(sum, "0");
    strcpy(power_i, "1");
    strcpy(one, "1");
    buf = addition(power_i, one, sys);
    strcpy(power_i, buf);
    free(buf);

    powers[0] = malloc(SIZE);
    powers_i[0] = malloc(SIZE);
    powers_i[1] = malloc(SIZE);
    strcpy(powers[0], val2);
    strcpy(powers_i[0],  "1");
    strcpy(powers_i[1], power_i);


    long i = 1;
    long o = 0;
    while (comp(val1,powers[i-1])==1){
        powers[i] = power(val2, powers_i[i], sys);
        powers_i[i+1] = addition(powers_i[i], one, sys);
        i+=1;
    }i-=1;
    o = i;
    while(i!=-1){
       buf2 = addition(sum, powers[i], sys);
       if(comp(val1, buf2)==1 || comp(val1, buf2)==0){
           strcpy(sum, buf2);
           free(buf2);
           if(i>0){
               buf = power(val2, powers_i[i-1], sys);
               buf2 = addition(solution, buf, sys);
               strcpy(solution, buf2);
               strcpy(solution, buf2);
               free(buf);
               free(buf2);
           }else{
               buf2 = addition(solution, one, sys);
               strcpy(solution, buf2);
               free(buf2);
           }
       }else{
           i-=1;
       }
    }
    free(sum);
    free(power_i);
    free(one);
    free(powers_i[0]);
    for (i = 0; i <= o; i++){
        free(powers[i]);
        free(powers_i[i+1]);
    }
    free(powers);
    free(powers_i);
    return solution;
}

char *divideModulo(char *val1, char *val2, int sys) {
    char * solution = malloc(SIZE);
    if(strcmp(val1, "-1") == 0 || strcmp(val2, "-1") == 0){
        strcpy(solution, "-1");
        return solution;
    }
    if(strcmp(val2,"0")==0){
        strcpy(solution, "0");
        return solution;
    }
    if(strcmp(val2,"0")==0){
        strcpy(solution, val1);
        return solution;
    }
    if(comp(val2,val1)==1){
        strcpy(solution, val1);
        return solution;
    }
    if(comp(val2,val1)==0){
        strcpy(solution, "0");
        return solution;
    }
    char * buf;
    char * sum = malloc(SIZE);
    char * buf2;
    char * power_i = malloc(SIZE);
    char * one = malloc(SIZE);
    char ** powers = malloc(SIZE);
    char ** powers_i = malloc(SIZE);

    strcpy(solution, "0");
    strcpy(sum, "0");
    strcpy(power_i, "1");
    strcpy(one, "1");
    buf = addition(power_i, one, sys);
    strcpy(power_i, buf);
    free(buf);

    powers[0] = malloc(SIZE);
    powers_i[0] = malloc(SIZE);
    powers_i[1] = malloc(SIZE);
    strcpy(powers[0], val2);
    strcpy(powers_i[0],  "1");
    strcpy(powers_i[1], power_i);


    long i = 1;

    while (comp(val1,powers[i-1])==1){
        powers[i] = power(val2, powers_i[i], sys);
        powers_i[i+1] = addition(powers_i[i], one, sys);
        i+=1;
    }i-=1;
    long o = i;
    while(i!=-1){
        buf2 = addition(sum, powers[i], sys);
        if(comp(val1, buf2)==1 || comp(val1, buf2)==0){
            strcpy(sum, buf2);
        }else{
            i-=1;
        }
        free(buf2);
    }
    buf2 = malloc(SIZE);
    strcpy(buf2, sum);
    if(comp(buf2, val1)==0){
        free(buf2);
        strcpy(solution, "0");
        return solution;
    }
    while(comp(buf2, val1)!=0){
        buf = addition(solution, one, sys);
        strcpy(solution, buf);
        free(buf);
        buf = addition(buf2, one, sys);
        strcpy(buf2, buf);
        free(buf);
    }

    free(buf2);
    free(sum);
    free(one);
    free(power_i);
    free(powers_i[0]);
    for (i = 0; i <= o; i++){
        free(powers[i]);
        free(powers_i[i+1]);
    }
    free(powers);
    free(powers_i);
    return solution;
}

