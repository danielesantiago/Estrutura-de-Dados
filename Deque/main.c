#include<stdio.h>
#include<stdlib.h> 
#include "deque.h"

int main(){

	Deque d;
	int numOperacoes, limite, valor, retorno;
	char texto[10];
	scanf("%d %d", &numOperacoes, &limite);
	start(&d, limite);
	for(int r = 0; r < numOperacoes; r++){
		
		scanf("%s", texto);
		if(texto== "\n"){
			scanf("%s", texto);
		}else{	//Verificamos qual foi o camando feito e entao chamamos a respectiva funcao
			if(texto[0] == 'i' && texto[6] == 'I'){
				scanf("%d", &valor); 
					pushIni(&d, valor);
			}else if(texto[0] == 'i' && texto[6] == 'F'){
				scanf("%d", &valor);
					pushFim(&d, valor);
			}else if(texto[0] == 'r' && texto[6] == 'I'){
				if(isEmpty(&d)){
					printf("vazia\n");
				}else{
					retorno = popIni(&d);
					printf("%d\n", retorno);
				}			
			}else if(texto[0] == 'r' && texto[6] == 'F'){
				if(isEmpty(&d)){
					printf("vazia\n");
				}else{
					retorno = popFim(&d);			
					printf("%d\n", retorno);
				}
			}
		}

	}

	return(0);
}
