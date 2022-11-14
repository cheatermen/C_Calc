#ifndef C_CALC_SYSTEMS_H
#define C_CALC_SYSTEMS_H

#include <glob.h>
static const size_t SIZE = sizeof(char) * 99999;

/*Converts num to its char analogue*/
char numToChar(int);
char *decToSys(long long, int);
long long sysToDec(char*, int);
/*Reverses a string*/
char *reverse(char*);
/*Converts a char to its numeral analogue*/
int charToNum(char);
/*Checks len of string*/
int checkLength(const char*);
/*Adds val2 to val1, returns new var*/
char *addition(char*, char*, int);
char *recursive_addition(char* val1, char digit1, int pos, int sys);
/*Multiplies val1 by val2, returns new var*/
char *multiply(char* val1, char*val2, int sys);
/*Multiplies val1 by digit1, returns new var*/
char *multi_by_one(char* digit, char num,int pos, int sys);
/*Adds 0 to end of string, returns new var*/
char *add_zero(char* num);
/*Compares 2 strings, returns 0 if equal, 1 if s1 > s2, 2 if s1 < s2 and 3 for no solution*/
short comp(char * num1, char * num2);
/*Raises val1 to the power of val2, returns new var*/
char * power(char * val1, char * val2, int sys);
/*Divides val1 by val2, if undefined, returns lower val, returns new var*/
char * divide(char* val1, char*val2, int sys);
/*Returns the remainder of val1 by val2 division, returns new var*/
char *divide_modulo(char *val1, char *val2, int sys);
char * slice (char * val, int x, int y);

#endif //C_CALC_SYSTEMS_H
