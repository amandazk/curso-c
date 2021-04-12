#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

char** mapa;
int linhas;
int colunas;

void LiberaMapa() {
    for(int i = 0; i < linhas; i++) {
        free(mapa[i]);
    }
    free(mapa);
}

void AlocaMapa() {
    mapa = malloc(sizeof(char*) * linhas);
    for(int i = 0; i < linhas; i++) {
        mapa[i] = malloc(sizeof(char) * (colunas+1));
    }
}

void LeMapa() {
    FILE* f;
    f = fopen("mapa.txt", "r");
    if (f == 0) {
        printf("Erro na leitura do mapa");
        exit(1);
    }

    fscanf(f, "%d %d", &linhas, &colunas);

    AlocaMapa();

    for (int i = 0; i < 5; i++) {
        fscanf(f, "%s", mapa[i]);
    }
    fclose(f);
}

int main() {

    LeMapa();

    for (int i = 0; i < 5; i++) {
        printf("%s\n", mapa[i]);
    }

    LiberaMapa();
}