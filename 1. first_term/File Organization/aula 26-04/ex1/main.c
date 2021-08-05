#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include.h"

int main() {
    char nome_arquivo[30];
    scanf("%s", nome_arquivo);

    FILE* fp = fopen(nome_arquivo, "r");
    Registro registro;

    if (fp == NULL)
    {
        fprintf(stderr, "Nao foi possivel abrir o arquivo.\n");
        return 1;
    }
    
    //ignorando o cabeçalho
    char c = fgetc(fp);
    while(c != '\n') {
        c = fgetc(fp);
    }

    while(!feof(fp)) {
        registro.id = atoi(linha(fp));
        registro.nome = linha(fp);
        registro.idade = atoi(linha(fp));

        if(registro.idade >= 18) {
            if(strlen(registro.nome) > 1)
                printf("O usuario %s eh de maior.\n", registro.nome);
            else 
                printf("O usuario de identificacao %d eh de maior.\n", registro.id);
        }
    }

    fclose(fp);
    return 0;
}