
#ifndef C_CALC_IO_H
#define C_CALC_IO_H

//funkcja ktora wczytuje dany plik wejsciowy oraz tworzy plik wyjsciowy z uzupelnionymi odpowiedziami
int readfile(char *argv[]);
//wybranie i wykonanie odpowiedniej operacji na wczytanych liczbach
void operations(char *val1, char *val2, char *sys, char * operation);
size_t getline(char **lineptr, size_t *n, FILE *stream);

#endif //C_CALC_IO_H
