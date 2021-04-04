#include <stdio.h>

int main() {

    printf("------------------------------------\n");
    printf("Bem vindo(a) ao jogo de adivinhação\n");
    printf("------------------------------------\n");

    int numerosecreto = 42;
    int chute;
    int tentativas = 1;

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
    }

    printf("Fim de jogo!\n");
    printf("Você acertou em %d tentativas", tentativas);
}