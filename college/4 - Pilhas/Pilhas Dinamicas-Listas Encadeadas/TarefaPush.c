#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    int valor;
    struct No * prox;
}No;

typedef struct Pilha{
    No * raiz;
}Pilha;

Pilha * newPilha(){
    Pilha * aux = (Pilha *)malloc(sizeof(Pilha));
    aux->raiz = NULL;
    return aux;
}

No * newNo(int valor){
    No * aux = (No*)malloc(sizeof(No));
    aux->valor=valor;
    aux->prox=NULL;
    return aux;
}

void push(Pilha *p, int valor){
    if(p->raiz == NULL) {
        No * no = newNo(valor);
        p->raiz = no;
    }
    else {
        No * no = newNo(valor);
        No * no2 = p->raiz;
        while(no2->prox != NULL) {
            no2 = no2->prox;
        }
        no2->prox = no;
    }
}

int pop(Pilha *p){
    No * aux = p->raiz;
    p->raiz = p->raiz->prox;
    int valor = aux->valor;
    free(aux);
    return valor;
}

int main() {
    Pilha * p = newPilha();
    push(p, 1);
    push(p, 2);
    push(p, 3);
}