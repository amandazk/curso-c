#include <stdio.h>

int main() {

    // Cabeçalho do jogo
    printf("------------------------------------\n");
    printf("Bem vindo(a) ao jogo de adivinhação\n");
    printf("------------------------------------\n");

    int numerosecreto = 42;
    int chute;
    
    printf("Qual é o seu chute? ");
    scanf("%d\n", &chute);
    printf("Seu chute foi: %d\n", chute);
}