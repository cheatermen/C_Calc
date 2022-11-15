#ifndef C_CALC_SYSTEMS_H
#define C_CALC_SYSTEMS_H

#include <glob.h>
static const size_t SIZE = sizeof(char) * 99999;

//biblioteka glownych funkcji

//Glowne funkcje:

//Dodawanie
char *addition(char*, char*, int);
char *recursiveAddition(char* val1, char digit1, int pos, int sys);
//Mnozenie
char *multiply(char* val1, char*val2, int sys);
char *multiByOne(char* digit, char num, int pos, int sys);
//Potegowanie
char * power(char * val1, char * val2, int sys);
//Dzielenie
char * divide(char* val1, char*val2, int sys);
//Dzielenie Modulo
char *divideModulo(char *val1, char *val2, int sys);

//Zamiana liczby w systemie dziesietnym na dowolny <2,16>
char *decToSys(char * val, int sys);
//Zamiana liczby w dowolnego systemie <2, 16> na dziesiętny
char * sysToDec(char * val, int sys);


//Funkcje pomocnicze:

//Konwersje z int na char, string na int, string na string
//potrzebne przy wykonywaniu programu
char numToChar(int);
int charToNum(char);
char sysCharToChar(char *sys_char);
int sysCharToInt(char*sys_char);

//odwrocenie stringa
char *reverse(char*);
//sprawdzenie dlugosci stringa
int checkLength(const char*);
//dodanie '0' na koniec stringa
char *addZero(char* num);
//porowananie dwoch liczb zapisanych jako stringi
//zwraca 0 jesli sa rowne, 1 jesli num1>num2, 2 jesli num1<num2, 3 jesli operacja sie nie powiodla
short comp(char * num1, char * num2);
//zwrocenie kawalka stringa od indeksu x do indeksu y
char *slice(char *val, int x, int y);
//zamienia znak \n na \0 w stringu
char * deleteEndl(char * string);

#endif //C_CALC_SYSTEMS_H
