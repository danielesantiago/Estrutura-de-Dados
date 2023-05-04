#include<stdio.h>
#include <stdlib.h>
#include <time.h> 
#define MAX 10000

int main(){
  
    long long signed int n, i, v[MAX], aux, j, comparacao=0, trocaPosicao=0;
  scanf("%lld", &n);


  clock_t begin = clock();
  for(i=0; i<n; i++){
  v[i] = rand() % MAX;}
  
       for(i=1; i<n ; i++){
               comparacao++;
              //(n - 1) interações -> Linear
			for(j = i; j>0 && v[j-1] > v[j]; j--){
                comparacao++;
              // Pior caso -> n*(n-1)/2 comparações 
				aux = v[j];
				v[j] = v[j-1];
				v[j-1] = aux;
                trocaPosicao++;
              // Melhor caso: constante -> 0, vetor ordenado
              // Pior caso -> n*(n-1)/2 trocas de posicao 
			}	
		}

  
clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("%lf %lld %lld\n", time_spent, comparacao, trocaPosicao);

    for(i=0; i<n; i++){
    printf("%lld ", v[i]);	
	}
	printf("\n");	
	
	return 0;
}
