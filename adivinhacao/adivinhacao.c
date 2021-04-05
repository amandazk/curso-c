#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("------------------------------------\n");
    printf("Bem vindo(a) ao jogo de adivinhação\n");
    printf("------------------------------------\n");

    int segundos = time(0);
    srand(segundos);

    int numeroaleatorio = rand();

    int numerosecreto = numeroaleatorio % 100;
    int chute;
    int tentativas = 1;    
    double pontos = 1000;
    int acertou = 0;

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("1 - Fácil\n2 - Médio\n3 - Difícil\n");
    printf("Faça a sua escolha: ");
    scanf("%d", &nivel);

    int numerotentativas;
    switch(nivel) {
        case 1:
            numerotentativas = 15;
            break;
        case 2:
            numerotentativas = 10;
            break;
        default:
            numerotentativas = 5;
    }
 
    for(int i = 1; i <= numerotentativas; i++) {

        printf("Tentativa %d de %d\n", tentativas, numerotentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi: %d\n", chute);

        if (chute < 0) {
            printf("O número deve ser positivo!\n");
            
            continue;
        }
        
        acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;

        if(acertou) {
            break;
        } 

        else if(maior) {
            printf("Seu chute foi maior que o número secreto\n");
        } 
        
        else {
            printf("Seu chute foi menor que o número secreto\n");
        }

        tentativas ++;

        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }

    printf("Fim de jogo!\n");

    if(acertou) {
        printf("Você acertou!\n");
        printf("Você acertou em %d tentativas\n", tentativas);
        printf("Você fez %.1f pontos\n", pontos);
    } else {
        printf("Você perdeu!\n");
    }
}