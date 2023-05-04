/* ================================================================== *
 *  Universidade Federal de SÃ£o Carlos - UFSCar, Sorocaba
 *
 * ================================================================== *
 *  Dados do aluno:
 *
 *  RA: 792175
 *  Nome: Daniele Santiago
 *
 * ================================================================== */

#include <stdio.h>
#define MAX 500


long int somar( long int v[],  long int n);
long int definirMaior( long int v[],  long int n);
long int definirMenor( long int v[], long int n);
long int descobrirCrescente( long int v[], long int n);
long int descobrirDecrescente( long int v[], long int n);
long int descobrirEspelhada( long int v[], long int n, int aux);



int main() {
 long int n, v[MAX], soma, maior, menor, crescente, decrescente, espelhada;
 int i;

  scanf("%ld", &n);
  for(i = 0; i<n; i++){
      scanf("%ld", &v[i]);
  }

  soma = somar(v, n);
  printf("Soma: %ld\n", soma);
  maior = definirMaior(v, n);
  printf("Maior: %ld\n", maior);
  menor = definirMenor(v, n);
  printf("Menor: %ld\n", menor);
  crescente = descobrirCrescente(v, n-1);
  if(crescente){
    printf("Crescente: sim\n");
  } else {
    printf("Crescente: nao\n");
  }

  decrescente = descobrirDecrescente(v, n-1);
  if(decrescente){
    printf("Decrescente: sim\n");
  } else {
    printf("Decrescente: nao\n");
  }

  espelhada = descobrirEspelhada(v, n-1,0);
  if(!espelhada){
    printf("Espelhada: sim\n");
  } else {
    printf("Espelhada: nao\n");
  }

return 0;
}


/* FunÃ§Ãµes recursivas */


long int somar( long int v[],  long int n){
  if(n == 0){
    return 0;
  } else {
    return v[n-1] + somar(v,n-1);
  }
}

long int definirMaior( long int v[],  long int n){
 long int maior;
  if(n == 0){
    maior = v[0];
  } else {
    maior = definirMaior(v, n-1);
    if( maior < v[n-1]){
    maior = v[n-1];
    }
  }
return maior;
}

long int definirMenor( long int v[],  long int n){
 long int menor;
  if(n == 0){
    menor = v[0];
  } else {
    menor = definirMenor(v, n-1);
    if( menor > v[n-1]){
    menor= v[n-1];
    }
  }
return menor;
}

long int descobrirCrescente( long int v[], long int n){
  int temp;
  if(n == 0){
    return 1;
  } else{
  if(v[n] > v[n-1]){
    temp =  descobrirCrescente(v, n-1);
  } else {
    return 0;
    }
  } 
  return temp;
}

long int descobrirDecrescente( long int v[], long int n){
  int temp;
  if(n == 0){
    return 1;
  } else {
  if(v[n] > v[n-1] ){
    return 0;
  } else {
     temp = descobrirDecrescente(v, n-1);
    }
  }
  return temp;
}

long int descobrirEspelhada( long int v[], long int n, int aux){
  int temp = 0;
  if(n < 0){
    return 0;
  } 
  if(v[aux] != v[n]){
    return 1;
  } else{
    temp = descobrirEspelhada(v, n-1,aux+1);
  }
  return temp;
}