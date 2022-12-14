#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha {
    int *v;
    int max,top;
} Pilha;

Pilha * newPilha(int max){
    Pilha * aux = (Pilha *)malloc(sizeof(Pilha));
    aux->v = (int *)malloc(sizeof(int)*max);
    aux->max=max;
    aux->top=0;
    return aux;
}

void push(Pilha *p,int x){
    p->v[p->top--]=x;
}

int pop(Pilha *p){
    return p->v[p->top++];
}

void print(Pilha *p){
    for(int i=p->top+1; i<=p->max;i++){
        printf(" ");
        printf("%d",p->v[i]);
    }
    printf("\n");
}

int main() {
    Pilha * p = newPilha(5);
    while(p->top != p->max && p->v[p->top] != NULL) {
        p->top++;
    }
    push(p, 3);
    print(p);
    push(p, 5);
    print(p);
    push(p, 1);
    print(p);
    push(p, 2);
    print(p);
    push(p, 4);
    print(p);
    pop(p);
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