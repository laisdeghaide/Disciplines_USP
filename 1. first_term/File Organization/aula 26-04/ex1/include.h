#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registro {
    int id;
    char *nome;
    int idade;
} Registro;

char* linha(FILE* fp);