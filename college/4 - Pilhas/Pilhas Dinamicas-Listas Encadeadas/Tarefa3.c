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

int isEmpty(Pilha * p){
    return p->raiz==NULL;
}

No * newNo(int valor){
    No * aux = (No*)malloc(sizeof(No));
    aux->valor=valor;
    aux->prox=NULL;
    return aux;
}

void push3(Pilha *p, int valor){
    No * no = newNo(valor);
    if(p->raiz == NULL) {
        no->prox = p->raiz;
        p->raiz = no;
    }
    else {
        no->prox = p->raiz->prox;
        p->raiz->prox = no;
    }
}

int pop(Pilha *p){
    
    if(isEmpty(p)){
        printf("Pilha Vazia\n");
        exit(6);
    }
    if(size(p) > 1) {
        No * aux = p->raiz->prox;
        p->raiz->prox = p->raiz->prox->prox;
        int valor = aux->valor;
        free(aux);
        return valor;
    }
    else {
        No * aux = p->raiz;
        p->raiz = aux->prox;
        int valor = aux->valor;
        free(aux);
        return valor;
    }
}

int size(Pilha *p){
    int size=0;
    No * aux = p->raiz;
    while(aux!=NULL){
        size++;
        aux=aux->prox;
    }
    return size;
}

void print(Pilha *p){
    No * aux = p->raiz;
    while(aux!=NULL){
        printf("%d",aux->valor);
        aux=aux->prox;
        if(aux!=NULL){
            printf("->");
        }
    }
    printf(" [%d]\n",size(p));
}

int main() {
    Pilha * p = newPilha();
    push3(p, 1);
    print(p);
    push3(p, 2);
    print(p);
    push3(p, 3);
    print(p);
    push3(p, 4);
    print(p);
    pop(p);
    print(p);
    pop(p);
    print(p);
    pop(p);
    print(p);
    pop(p);
    print(p);
}