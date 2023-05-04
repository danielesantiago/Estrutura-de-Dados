#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


//Pilha.c
Pilha* start(){
  Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
  if(pi != NULL)
  *pi = NULL;
  return pi;
}

int fullPilha(Pilha* pi){
  return 0;
}

int emptyPilha(Pilha* pi){
  if(pi == NULL) return 1;
  if(*pi == NULL) return 1;
  return 0;
}

int inserirDados(Pilha* pi, struct caractere c){
  if(pi == NULL) return 0;
  Elem* no = (Elem*) malloc(sizeof(Elem));
  if(no == NULL) return 0;
  no->dados = c;
  no->prox = (*pi);
  *pi = no;
  return 1;
}
int removerDados(Pilha* pi){
  if(pi == NULL) return 0;
  if((*pi) == NULL) return 0;
  Elem *no = *pi;
  *pi = no->prox;
  free(no);
  return 1;
}

struct caractere consultaDados(Pilha *pi, struct caractere *c){
  *c = (*pi) -> dados;
  return *c;
}

void liberaPilha(Pilha* pi){
  if(pi!= NULL){
    Elem* no;
    while((*pi) != NULL){
      no = *pi;
      *pi = (*pi)->prox;
      free(no);
    }
    free(pi);
  }

}
