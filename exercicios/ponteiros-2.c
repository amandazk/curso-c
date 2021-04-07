#include <stdio.h>
#include <conio.h>

int main() {

    // valor é a variável que será apontada pelo ponteiro
    int valor = 27;

    // declaração de variável ponteiro
    int *ptr;

    // atribuindo o endereço da variável valor ao ponteiro
    ptr = &valor;

    printf("Utilizando ponteiros\n\n");
    printf("Conteudo da variavel valor: %d\n", valor); // 27
    printf("Endereco da variavel valor: %x \n", &valor); // 61ff18
    printf("Conteudo da variavel ponteiro prt: %x", ptr); // 61ff18
}