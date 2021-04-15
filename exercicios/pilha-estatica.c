#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 100

typedef struct 
{
    int Item[MAXTAM];
    int Topo; // retorna o índice do último vetor inserido
} Pilha; 

void pilhaInicia (Pilha *p) {
    p->Topo = -1; // indica que a pilha está vazia
}

// verificar se a pilha está vazia
int pilhaVazia(Pilha *p) {
    if (p->Topo == -1) {
        return 1; // está vazia
    } else {
        return 0; // não está vazia
    }
}

int pilhaCheia(Pilha *p) {
    if (p->Topo == MAXTAM-1) { // -1 porque começa com 0
        return 1;
    } else {
        return 0; // pilha não está cheia
    }
}

void pilhaInsere(Pilha *p, int x) {
    if (pilhaCheia(p) == 1) {
        printf("Pilha cheia!");
    } else {
        p->Topo++; // inserir novo valor sempre depois do topo
        p->Item[p->Topo] = x; // o x vai ser inserido no topo
    }
}

int pilhaRetira(Pilha *p) {
    int aux;
    if (pilhaCheia(p) == 1) {
        printf("Pilha vazia");
    } else { 
        aux = p->Item[p->Topo];
        p->Topo--; // colocando o topo para o índice anterior
        return aux;
    }
}


int main()
{
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    pilhaInicia(p);

    pilhaInsere(p, 2);
    pilhaInsere(p, 3);
    pilhaInsere(p, 4);
    
    int aux;
    aux = pilhaRetira(p);
    printf("\n Removido: %d \n", aux);

    return 0;
}