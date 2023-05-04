
#include<stdio.h>
#define MAX 200000

void swap(long long int *a, long long int *b);
long long int partition(long long int vetor[], long long int min, long long int max, long long int pivot);
void quickSort(long long int porcas[], long long int parafusos[], long long int min, long long int max);

int main(){
    long long int qtd, porcas[MAX], parafusos[MAX];
    scanf("%lld", &qtd);
    for(long long int i = 0; i<qtd; i++){
      scanf("%lld", &porcas[i]);
    }

   for(long long int i = 0; i<qtd; i++){
      scanf("%lld", &parafusos[i]);
    }
    quickSort(porcas, parafusos, 0, qtd-1);
     
for(long long int i=0; i<qtd; i++)
printf("%lld - %lld\n", porcas[i], parafusos[i]);

}

void swap(long long int *a, long long int *b){
    long long int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


long long int partition(long long int vetor[], long long int min, long long int max, long long int pivot){
    int i = min;
    
    for(long long int j = min; j < max; j++){
        if (vetor[j] < pivot) {
            swap(&vetor[i], &vetor[j]);
            i++;
          }
        else if(vetor[j] == pivot){
            swap(&vetor[j], &vetor[max]);
            j--;
        }
    }
    swap(&vetor[i], &vetor[max]);
    return i;
}
 

void quickSort(long long int porcas[], long long int parafusos[], long long int min, long long int max){
  if (min < max){
     long long int pivot = partition(porcas, min, max, parafusos[max]);
     partition(parafusos, min, max, porcas[pivot]);
     quickSort(porcas, parafusos, min, pivot - 1);
     quickSort(porcas, parafusos, pivot + 1, max);
    }
}
 