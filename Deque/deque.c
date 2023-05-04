/* Deque.c */
#include<stdio.h>
#include<stdlib.h> 
#include "deque.h"

//Criacao do deque
void start(Deque *d, int max){
	d->size = 0;
	d->maxSize = max;
	d->ini = NULL;
	d->fim = NULL;
}

//verifica se é vazio
int isEmpty(Deque *d){
	if(d->size == 0){
		return(1);
	}else{
		return(0);
	}
}

//verifica se está cheio
int isFull(Deque *d){
	if(d->size == d->maxSize){
		return(1);
	}else{
		return(0);
	}
}

// Insere no inicio
void pushIni(Deque *d, int numero){
	if(!isFull(d)){
		if(isEmpty(d)){
			Node *new = (Node*)malloc(sizeof(Node));
			new->data = numero;
			new->ant = NULL;
			new->prox = NULL;
			d->ini = new;
			d->fim = new;
			d->size = d->size+1;
		}else{
			Node *new = (Node*)malloc(sizeof(Node));
			new->data = numero;
			new->ant = NULL;
			new->prox = d->ini;
			d->ini->ant = new;
			d->ini = new;
			d->size = d->size+1;
		}
	}else{
		printf("cheia\n");
	}
}

//Insere no fim
int pushFim(Deque *d, int numero){
	if(!isFull(d)){
	Node *new = (Node*)malloc(sizeof(Node));
	new->data = numero;
    new->prox = NULL;
    if(isEmpty(d)){
      new->ant = NULL;
      d->ini = new;
    } else{
     new->ant = d->fim; 
     d->fim->prox = new;
    }
    d->fim = new;
    d->size = d->size+1; 
	}else{
		printf("cheia\n");
	}
}

//Remove do inicio
int popIni(Deque *d){
	int data;
	Node *aux;
	aux = d->ini;
	if(aux->prox == NULL){
		data = aux->data;
		d->ini = NULL;
		d->size = d->size-1;
		free(aux);	
	}else{
		aux->prox->ant = NULL;
		d->ini=aux->prox;
		data = aux->data;
		d->size = d->size-1;
		free(aux);
	}
	return(data);
}

//Remove do fim
int popFim(Deque *d){
    int data;
	Node *aux;
	aux = d->fim;
    if(aux == d->ini){ //removendo o primeiro item
      data = aux->data;
      d->ini = NULL;
      d->fim = NULL;
    } else {
      aux->ant->prox = NULL;
      d->fim = aux->ant;
      data = aux->data;
    }
  d->size = d->size-1;
  free(aux);
  return(data);
}
