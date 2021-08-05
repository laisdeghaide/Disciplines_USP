#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include.h"

int main() {
    char nome_arquivo[30];
    scanf("%s", nome_arquivo);

    FILE* fp = fopen(nome_arquivo, "rb");
    registro registro;

    if (fp == NULL)
    {
        fprintf(stderr, "Nao foi possivel abrir o arquivo.\n");
        return 1;
    }

    while(fread(&registro.id, sizeof(int), 1, fp) == 1) {
        fread(registro.nome, sizeof(char), 50, fp);
        fread(&registro.idade, sizeof(int), 1, fp);

        if(registro.idade >= 18) {
            if(strlen(registro.nome) > 0)
                printf("O usuario %s eh de maior.\n", registro.nome);
            
            else 
                printf("O usuario de identificacao %d eh de maior.\n", registro.id);
        }
    }

    fclose(fp);

    return 0;
}