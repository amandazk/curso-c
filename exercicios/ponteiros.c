#include <stdio.h>

void calcula(int* c) { // * significa que não vai vir um inteiro e sim um endereço de memória de um inteiro 

    // printf("calcula %d %d\n", c, &c);
    printf("calcula %d %d\n", (*c), c);
    (*c)++; // quero entrar no valor do endereço de memória, pegar o conteúdo
    printf("calcula %d %d\n", (*c), c);
}

// quero que a variável c da main aponte para o mesmo endereço da calcula
int main() {

    int c = 10;
    
    printf("main %d %d\n", c, &c);
    calcula(c);
    printf("main %d %d\n", c, &c);
}