#ifndef C_CALC_SYSTEMS_H
#define C_CALC_SYSTEMS_H

#include <glob.h>

static const size_t SIZE = sizeof(char) * 41;

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
/*Adds 2 vals together, returns new var*/
char *addition(char*, char*, int);
char *recursive_addition(char* num, char digit, int pos, int sys);
/*Multiplies 2 vals, returns new var*/
char *multiply(char* num1, char*num2, int sys);
/*Multiplies val by digit, returns new var*/
char *multi_by_one(char* digit, char num,int pos, int sys);
/*Adds 0 to end of string, returns new var*/
char *add_zero(char* num);

#endif //C_CALC_SYSTEMS_H
