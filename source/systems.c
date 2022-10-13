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

char *decToSys(long long num, int sys){
    char *string = malloc(SIZE);
    int i = 0;

    while (num != 0){
        if (i > 40){
            printf("Num too long");
            return 0;
        }
        string[i] = numToChar(num % sys);
        num = num / sys;
        i+=1;
    }
    string[i] = '\0';

    string = reverse(string);
    return string;
}

long long sysToDec(char * string,int sys){
    long long dec = 0;
    int sup=0;
    while (string[sup]!='\0'){
        sup+=1;
    }
    sup--;
    for(int i = sup; i >= 0; i--){
        int buf = charToNum(string[i]);
        dec+=pow(sys,sup - i)*buf;
    }
    return dec;
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
char* addition(char* a,char*b, int sys){
    char* buf1 = malloc(SIZE);
    char* buf2 = malloc(SIZE);
    reverse(strcpy(buf1,a));
    reverse(strcpy(buf2,b));

    int length = checkLength(buf2);

    for (int i = 0; i <= length; i++) {
        buf1 = recursive_addition(buf1, buf2[i], i, sys);
    }
    free(buf2);
    return reverse(buf1);
}

char *recursive_addition(char *num, char digit, int pos, int sys) {
    int sum = charToNum(num[pos])+ charToNum(digit);
    if (pos > checkLength(num)){
        num[pos+1] = '\0';
    }
    if (sum >= sys){
        num[pos] = numToChar(sum % sys); // 12 02
        num = recursive_addition(num, numToChar(sum/sys), pos+1, sys);
    }else{
        num[pos] = numToChar(sum);
    }
    return num;
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

char *multiply(char *num1, char *num2, int sys) {
    char * sum = malloc(SIZE);
    char * buf = malloc(SIZE);
    strcpy(buf, num2);
    reverse(buf);
    strcpy(sum, "0");

    int lim = checkLength(num2);
    for (int i=0;i<=lim;i++){
        char * temp = multi_by_one(num1, buf[i], i, sys);
        char * temp2 = addition(sum, temp, sys);
        free(sum);
        free(temp);
        sum = temp2;
    }
    return sum;
}

char *add_zero(char *num) {
    char * buf = malloc(SIZE);
    strcpy(buf, num);
    int i = checkLength(buf);
    buf[i+1] = '0';
    buf[i+2] = '\0';
    return buf;
}

char *power(char *num1, char *num2, int sys) {
    char * solution = malloc(SIZE);
    strcpy(solution, "1");
    if (strcmp(num2, "0") == 0){
        return solution;
    }
    char * half[SIZE];
    half[0] = malloc(SIZE);
    char * index[SIZE];
    index[0] = malloc(SIZE);
    strcpy(index[0], "1");
    strcpy(half[0], num1);
    long long i = 1;
    long long z = 2;
    char * q = malloc(sizeof(char)*2);
    strcpy(q, "2");

    short c = comp(index[0], num2);
    while(c == 2){
        half[i] = malloc(SIZE);
        index[i] = malloc(SIZE);
        half[i] = multiply(half[i - 1], half[i - 1], sys);
        index[i] = multiply(index[i-1], q, sys);
        c = comp(index[i], num2);
        i += 1;
        z *= 2;
    }
    long long o = i;
    i--;
    z=z/2;
    printf("\n%lld, %lld\n", i, z);
    char * buf1 = malloc(SIZE);
    strcpy(buf1, "0");
    while(comp(buf1, num2) != 0) { // 8, 0->8. 8 9
        char * temp_con = addition(index[i], buf1, sys);
        if ((comp(temp_con, num2)) == 2 || comp(temp_con, num2) == 0){
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
        printf("\n%s", half[x]);
        free(half[x]);

    }
    free(buf1);
    free(q);
    return solution;
}


short comp(char *num1, char *num2) {
    if (strcmp(num1, num2) == 0){
        return 0;
    }
    int i =  checkLength(num1);
    int i2 = checkLength(num2);
    if (i > i2){
        return 1;
    }else if (i < i2){
        return 2;
    }else{
        for (int x = 0; x < i+1; x++){
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
