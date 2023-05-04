/* ================================================================== *
 *  Universidade Federal de São Carlos - UFSCar, Sorocaba
 *
 * ================================================================== *
 *  Dados do aluno:
 *
 *  RA: 792175
 *  Nome: Daniele Santiago
 *
 * ================================================================== */
#include <stdio.h>
#define MAX 10000
#define MAXGARRAFA 1000000

void ordenarLista(long unsigned int v[], long unsigned int tamanho); //InsertionSort
void buscaBinaria(long unsigned int listaBusca[], long unsigned int tamanhoListaBusca, long unsigned int numeroProcurado);

int main() {
    long unsigned int qtdEmbalagem, tamanhosEmbalagem[MAX], qtdGarrafa, tamanhosGarrafas[MAXGARRAFA];
    scanf("%ld", &qtdEmbalagem);
    for(int i= 0; i<qtdEmbalagem; i++){
      scanf("%ld", &tamanhosEmbalagem[i]);}
    ordenarLista(tamanhosEmbalagem, qtdEmbalagem);
    scanf("%ld", &qtdGarrafa);
    for(int i = 0; i<qtdGarrafa; i++){
      scanf("%ld", &tamanhosGarrafas[i]);}

     for(int i = 0; i<qtdGarrafa; i++){
     buscaBinaria(tamanhosEmbalagem, qtdEmbalagem, tamanhosGarrafas[i]);}
  
        
    return 0;
}

void ordenarLista(long unsigned int v[], long unsigned int tamanho){
int aux;
  for(int i=1; i<tamanho ; i++){
	 for(int j = i; j>0 && v[j-1] > v[j]; j--){
				aux = v[j];
				v[j] = v[j-1];
				v[j-1] = aux;
	 }	
  }
}

void buscaBinaria(long unsigned int listaBusca[], long unsigned int tamanhoListaBusca, long unsigned int numeroProcurado){
    long long int indice = -1, inicio = 0, fim = tamanhoListaBusca - 1, meio;

	while(inicio <= fim){
		meio = (inicio + fim)/2;		
		if(listaBusca[meio] == numeroProcurado){
			indice = meio;
            break;
		}
        if(listaBusca[meio] > numeroProcurado){
          indice = meio;
        }
		if (listaBusca[meio] < numeroProcurado){
			inicio = meio+1;
		}
      else{ 
		fim = meio - 1;
	}
		
	}
	
	if(indice>=0)
	printf("%ld\n", listaBusca[indice]);
	else
	printf("descartar\n");
}