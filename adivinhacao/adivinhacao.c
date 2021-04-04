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

    while (1) {

        printf("Tentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi: %d\n", chute);

        if (chute < 0) {
            printf("O número deve ser positivo!\n");
            
            continue;
        }
        
        int acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;

        if(acertou) {
            printf("Você acertou!\n");
            
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
    printf("Você acertou em %d tentativas\n", tentativas);
    printf("Você fez %.1f pontos\n", pontos);
}