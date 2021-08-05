#include "include.h"

char* linha(FILE* fp) {
    char* temp = (char *)malloc(sizeof(char));
    char c = 0;
    int posicao = 0;
        
    while(c != ',' && c != '\n' && c != EOF) {
        c = fgetc(fp);
        if(c != ',')
            temp[posicao++] = c;
        temp = realloc(temp, (posicao+1)*sizeof(char));
    }
    temp[posicao] = '\0';

    return temp;
}
