#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha{
    int *v;
    int max,top;
}Pilha;

Pilha * newPilha(int max){
    Pilha * aux = (Pilha *)malloc(sizeof(Pilha));
    aux->v = (int *)malloc(sizeof(int)*max);
    aux->max=max;
    aux->top=0;
    return aux;
}

void push(Pilha *p,int x){
    if((p->top) <= 2) {
        p->v[p->top++]=x;
    }
    if((p->top) >= 2) {
        for(int i = p->top-1; i > 1; i--) {
            p->v[i] = p->v[i-1];
        }
        p->v[1] = x;
        p->top++;
    } 
}

int pop(Pilha *p){
    if(p->top >= 2) {
        for(int i = 1; i < p->top-1; i++) {
            p->v[i] = p->v[i+1];
        }
        p->top--;
    }
    else {
        return p->v[p->top--];
    }
}

int main() {
    Pilha * p = newPilha(5);
    push(p, 3);
    push(p, 5);
    push(p, 1);
    push(p, 2);
    push(p, 4);
    pop(p);
    pop(p);
    pop(p);
    pop(p);
    pop(p);
}