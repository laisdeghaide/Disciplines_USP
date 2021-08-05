#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include.h"

int main() {
    char nome_arquivo[30];
    int N;

    scanf("%s", nome_arquivo);
    scanf("%d", &N);

    FILE* fp = fopen(nome_arquivo, "wb");
    registro registro;

    for(int i=0; i<N; i++) {
        scanf("%d", &registro.id);
        scanf("%s", registro.nome);
        scanf("%d", &registro.idade);

        fwrite(&registro.id, sizeof(int), 1, fp);
        fwrite(registro.nome, sizeof(char), strlen(registro.nome)+1, fp);
        fwrite(&registro.idade, sizeof(int), 1, fp);
    }

    fclose(fp);
    binarioNaTela(nome_arquivo);

    return 0;
}