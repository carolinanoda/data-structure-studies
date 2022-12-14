// Tarefa 1) Faça um programa que verifica se uma sequencia de parênteses,
// chaves e colchetes está balanceada.

// Exemplo de strings balanceadas:
// {[()]}
// [({[()]})]
// []{}()
// if(i==2){v[(i+2)/((2+2)*(2))] = (3*(3*3+3))}

// Exemplos de string não balanceadas
// [(])
// {([]})
// [{[]]
// [{[]}}]
// if(i==2){v[(I+2)}/(2+2)] = (3*(3*3+3))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Pilha {
  char p[MAX];
  int topo;
} Pilha;

void push(char item) {
  if (Pilha.topo == (MAX - 1))
    printf("Pilha cheia\n");
  else {
    Pilha.topo += 1;
    Pilha.p[Pilha.topo] = item;
  }
}

void pop() {
  if (Pilha.topo == -1) {
    printf("Pilha vazia\n");
  }
  else {
    Pilha.topo -= 1;
  }
}

int checarPar(char val1,char val2){
    return (( val1=='(' && val2==')' )||( val1=='[' && val2==']' )||( val1=='{' && val2=='}' ));
}

int checarBalanceado(char letra[], int len){
      
    for (int i = 0; i < len; i++) { 
        if (letra[i] == '(' || letra[i] == '[' || letra[i] == '{') {  
          push(letra[i]); 
        } 
        else
        {
          if (Pilha.topo == -1) {
              return 0;
          }
          else if(checarPar(Pilha.p[Pilha.topo],letra[i])) {
              pop();
              continue;
          }
          return 0;
        }
    }    
    return 1; 
}
int main() {
  char str[MAX];
  printf("Digite uma sequencia de parenteses, chaves e colchetes:\n");
  scanf("%s", str);
  for (int i = 0, j; str[i] != '\0'; i++) {
    while (!(str[i] >= '(' && str[i] <= ')') && !(str[i] >= '[' && str[i] <= ']') && !(str[i] >= '{' && str[i] <= '}')) {
      for (j = i; str[j] != '\0'; j++) {
        str[j] = str[j + 1];
      }
      str[j] = '\0';
    }
  }
  int i = 0;
  Pilha.topo = -1;

  int len = strlen(str);
  if(checarBalanceado(str, len)){
    printf("Esta balanceada");
  }
  else {
    printf("Nao esta balanceada"); 
  }

  return 0;
}