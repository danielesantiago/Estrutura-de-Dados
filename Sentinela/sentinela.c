#include <stdio.h>
#include <stdlib.h>
#include "sentinela.h"
int menor_igual_maior(Item a, Item b){
  if(a.dado == b.dado){
    return 0;
  } else{
    if(a.dado > b.dado){
      return 1;
    } else {
      return -1;
    }
  }
}

void inicializa(Lista *l, int(*menor_igual_maior) (Item i1, Item i2)){
   Node *no = (Node*)malloc(sizeof(Node));
   l->sentinela = no;
   l->quantidade=0;
   l->menor=menor_igual_maior;
   no->prox = no;
   no->ant = no;
}

void insere(Lista *l, Item i){
  int x,j=0;
  Node *no = (Node*)malloc(sizeof(Node));
  Node *aux;
  aux = l->sentinela->prox;
  while(j < l->quantidade){
    x = l->menor(i, aux->dado);
    j++;
    if(x == 0 || x ==1){
      aux = aux->prox;
    }
  }

  no->dado = i;
  no->prox = aux;
  l->quantidade++;
  no->ant = aux->ant;
  aux->ant->prox=no;
  aux->ant = no;
}

int vazia(Lista *l){
return l->sentinela->prox == l->sentinela;
}

int acabou(Iterador i){
  return i.no == i.l->sentinela;
}

void retira(Lista *l, Item item){
  Node *retirar = (Node*)malloc(sizeof(Node));
  int qtd = 0, aux;
  retirar = l->sentinela->prox;
  aux = l->quantidade;

  for(int i = 0; i<aux; i++){
    if(retirar->dado.dado == item.dado){
      retirar->ant->prox = retirar->prox;
      retirar->prox->ant = retirar->ant;
      qtd = qtd+1;
    }
     retirar = retirar->prox;
  }
  l->quantidade=l->quantidade - qtd;
}

Iterador primeiro(Lista *l){
  Iterador i;
  i.no = l->sentinela->prox;
  return i;
}

Iterador ultimo(Lista *l){
  Iterador i;
  i.no = l->sentinela->ant;
  return i;
}

int proximo(Iterador* i){
  if(acabou(*i)){
    return 0;
  } else {
    i->no = i->no->prox;
    return 1;
  }
}

int ant(Iterador* i){
  if(acabou(*i)){
    return 0;
  } else {
    i->no = i->no->ant;
    return 1;
  }
}

void destroi(Lista* l){
    Node *aux = l->sentinela->prox;
    Node *aux1;
    while(aux != l->sentinela){
        aux1 = aux;
        aux = aux->prox;
        free(aux1);
    }
    l->sentinela->prox = l->sentinela;
    l->sentinela->ant = l->sentinela;
    free(l);
}

int elementov(Iterador i, Item* item){
    if(i.no == i.l->sentinela )
        return 0;
    else{
        *item = i.no->dado;
        return 1;
    } 
}

Item elemento(Iterador i){
    return i.no->dado;
}
