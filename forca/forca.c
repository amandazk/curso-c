#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

// variáveis globais
char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

void abertura() {
    
    printf("*******************\n");
    printf("*  Jogo de Forca  *\n");
    printf("*******************\n\n");
}

void chuta() {
    
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

int jachutou(char letra) {

    int achou = 0; // preciso do achou fora da função tambék

    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}
void desenhaforca() {

    for(int i = 0; i < strlen(palavrasecreta); i++) {
            
        int achou = jachutou(palavrasecreta[i]);

        if(achou) {
            printf("%c ", palavrasecreta[i]);
        } 
        else {
            printf("_ ");
        }
    }
    
    printf("\n");
}

void escolhepalavra() {
    FILE* f;

    f = fopen("palavras.txt", "r"); // lendo o arquivo de palavras
    if(f == 0) {
        printf("Desculpe, banco de dados não disponível\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for(int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

int acertou() {

    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }

    return 1;
}

int enforcou() {

    int erros = 0;
    for(int i = 0; i < chutesdados; i++) {
        int existe = 0;

        for (int j = 0; j < strlen(palavrasecreta); j++) {
            if (chutes[i] == palavrasecreta[j]) {

                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
    }
    return erros >= 5; // retorna verdadeiro ou falso
}

int main() {

    escolhepalavra();
    abertura();

    do {

        desenhaforca();
        chuta();

    } while (!acertou() && !enforcou());
}
