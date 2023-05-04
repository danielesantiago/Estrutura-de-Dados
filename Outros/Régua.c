/* ================================================================== *
 *  Universidade Federal de SÃƒÆ’Ã‚Â£o Carlos - UFSCar, Sorocaba
 *
 * ================================================================== *
 *  Dados do aluno:
 *
 *  RA: 792175
 *  Nome: Daniele Santiago
 *
 * ================================================================== */
 
#include <stdio.h>
void tracosDois(int qtd);

int main() {
    int tamanhoRegua, qtdTracos, i;
   scanf("%d %d", &tamanhoRegua, &qtdTracos);
   for(i=0; i<tamanhoRegua; i++){
     for(int j = 0; j<qtdTracos; j++){
       printf("-");
     }
     printf(" %d\n", i);
     if(qtdTracos>1){
     tracosDois(qtdTracos-1);}
   }
     for(int j = 0; j<qtdTracos; j++){
       printf("-");
     }
     printf(" %d\n", i);
   return 0;
}


void tracosDois(int qtd){
  if(qtd == 1){
    printf("-\n");
   } else {
    tracosDois(qtd-1);
    for(int i = 0; i<qtd; i++){
      printf("-");
    }
    printf("\n");
    tracosDois(qtd-1);
   }
}