#include<stdio.h>
#include<stdlib.h>
#include "fila.h"

//Fila.c

    Fila* criaFila() {
    Fila* fi = (Fila*)malloc(sizeof(Fila));
    fi->inicio = fi->final = NULL;
    return fi;
}

   int filaVazia(Fila* fi){
     if(fi == NULL) return 1;
     if(fi->inicio == NULL){
       return 1;
     }
     return 0;
}

void inserirFila(Fila* fi, int data) {
   Node* no = (Node*)malloc(sizeof(Node));
   no->dados = data;
   no->prox = NULL;
   if (fi->final != NULL)
       fi->final->prox = no;
   else
       fi->inicio = no;
       fi->final = no;
}

int retirarFila(Fila* fi){
    Node* no = fi->inicio;
    fi->inicio = no->prox;
    int data;
    data = no->dados;
    if (fi->inicio == NULL)
        fi->final = NULL;
    free(no);
    return data;
}

void liberarFila(Fila* fi) {
if(fi != NULL){
  Node* no;
  while(fi->inicio != NULL){
    no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    free(no);
  }
  free(fi);
}
}



void printar(Fila* f, int qtd) {
   Node* aux;
   int i;
   for (i = 0, aux = f->inicio; aux != NULL; aux = aux->prox, i++){
       printf("%d", aux->dados);
       if(i < qtd-1){
       printf(" ");
       }}
       printf("\n");
}

void inverteElementos(Node *no, Node *ant){
    if(no->prox != NULL)
        inverteElementos(no->prox, no);
    no->prox = ant;
}

void inverter (Fila *fi){
    inverteElementos(fi->inicio, NULL);
    Node *aux = fi->inicio;
    fi->inicio = fi->final;
    fi->final = aux;
}
