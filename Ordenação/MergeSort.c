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
#include <stdlib.h>


void mergesort(long long int *v, long long int *c, long long int inicio, long long int fim);
void merge(long long int *v, long long int *c, long long int inicio, long long int meio, long long int fim);
void buscaBinaria(long long int listaBusca[],  long long int tamanhoListaBusca, long unsigned int numeroProcurado);

int main() {
    long long int qtdEmbalagem,  qtdGarrafa;
    static long long int tamanhosEmbalagem[1000000];
    static long long int tamanhosGarrafas[1000000];
    scanf("%lld", &qtdEmbalagem);
     for(int i= 0; i<qtdEmbalagem; i++){
       scanf("%lld", &tamanhosEmbalagem[i]);}
  
  long long int *c = malloc(sizeof(long long int) * qtdEmbalagem);
  mergesort(tamanhosEmbalagem, c, 0, qtdEmbalagem-1);
  free(c);
  
   scanf("%lld", &qtdGarrafa);
    for(int i = 0; i<qtdGarrafa; i++){
      scanf("%lld", &tamanhosGarrafas[i]);}

    for(int i = 0; i<qtdGarrafa; i++){
       if(tamanhosGarrafas[i] < tamanhosEmbalagem[0]){
          printf("descartar\n");
       } else if(tamanhosGarrafas[i] >= tamanhosEmbalagem[qtdEmbalagem-1]){
          printf("%lld\n", tamanhosEmbalagem[qtdEmbalagem-1]);
       } else{
          buscaBinaria(tamanhosEmbalagem, qtdEmbalagem, tamanhosGarrafas[i]);}
       }
        
    return 0;
}


void mergesort(long long int *v, long long int *c, long long int inicio, long long int fim) {
 
  if (inicio >= fim){
    return;
    }

  int meio = (inicio + fim) / 2;

  mergesort(v, c, inicio, meio);
  mergesort(v, c, meio + 1, fim);

  if (v[meio] <= v[meio + 1]){
    return;
  }

  merge(v, c, inicio, meio, fim);
}


void merge(long long int *v, long long int *c, long long int inicio, long long int meio, long long int fim) {
 long long int aux,
 iniciov = inicio, inicioc = meio + 1;

  for (aux = inicio; aux <= fim; aux++){ 
    c[aux] = v[aux];
    }
    aux = inicio;

  while (iniciov <= meio && inicioc <= fim) {
    if (c[iniciov] <= c[inicioc]){
      v[aux] = c[iniciov];
      aux++;
      iniciov++;
    }
    else{
       v[aux] = c[inicioc];
      aux++;
      inicioc++;
      }
  }

  while (iniciov <= meio){
    v[aux] = c[iniciov];
    aux++;
    iniciov++;
  } 

  while (inicioc <= fim){
    v[aux] = c[inicioc]; 
    aux++;
    inicioc++;
  }
}

void buscaBinaria( long long int listaBusca[],  long long int tamanhoListaBusca, long unsigned int numeroProcurado){
    long long int indice = -1, inicio = 0, fim = tamanhoListaBusca - 1, meio;

	while(inicio <= fim){
		meio = (inicio + fim)/2;		
		if(listaBusca[meio] == numeroProcurado){
			indice = meio;
            break;
		}
        if(listaBusca[meio] < numeroProcurado){
          indice = meio;
          inicio = meio+1;
        } 
      if(listaBusca[meio] > numeroProcurado){
          fim = meio-1;
        }
	}
	
	if(indice>=0)
	printf("%lld\n", listaBusca[indice]);
	else
	printf("descartar\n");
}