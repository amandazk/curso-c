#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

// variáveis globais
char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

void Abertura() {
    
    printf("*******************\n");
    printf("*  Jogo de Forca  *\n");
    printf("*******************\n\n");
}

void Chuta() {
    
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

int JaChutou(char letra) {

    int achou = 0; // preciso do achou fora da função tambék

    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}
void DesenhaForca() {

    for(int i = 0; i < strlen(palavrasecreta); i++) {
            
        int achou = JaChutou(palavrasecreta[i]);

        if(achou) {
            printf("%c ", palavrasecreta[i]);
        } 
        else {
            printf("_ ");
        }
    }
    
    printf("\n");
}

void AdicionaPalavra () {

    char opcao;

    printf("Voce deseja adicionara uma nova palavra ao jogo? S/N\n");
    scanf(" %c", &opcao);

    if(opcao == 'S') {
        
        char novapalavra[TAMANHO_PALAVRA];

        printf("Qual a nova palavra? ");
        scanf("%s", &novapalavra);

        FILE* f;
        f = fopen("palavras.txt", "r+"); // r+ é leitura e escrita
        if(f == 0) {
            printf("Desculpe, banco de dados não disponível\n\n");
            exit(1);
        }
        
        // lendo o número de palavras que existem no arquivo
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        // posicionar no começo do arquivo
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        // posicionando no final do arquivo
        fseek(f, 0, SEEK_END); 
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
}

void EscolhePalavra() {
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

int Acertou() {

    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(!JaChutou(palavrasecreta[i])) {
            return 0;
        }
    }

    return 1;
}

int Enforcou() {

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

    EscolhePalavra();
    Abertura();

    do {

        DesenhaForca();
        Chuta();

    } while (!Acertou() && !Enforcou());

    if(Acertou()) {
        printf("Parabéns! Você ganhou!\n\n");
    } else {
        printf("Poxa, não foi dessa vez. A palavra era --- %s ---\n\n", palavrasecreta);
    }

    AdicionaPalavra();
}
