#include<stdio.h>
#include<stdlib.h>
#include "fila.h"

//Main
int main(){
	Fila *fi;
  fi = criaFila();
	int qtd, numero;
  scanf("%d", &qtd);
  for(int i =0; i<qtd; i++){
    scanf("%d",&numero);
    inserirFila(fi, numero);
  }
  
  inverter(fi);
  
  printar(fi, qtd);

	return(0);

}
