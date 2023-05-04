#include <stdio.h>
#include <stdlib.h>
#include "sentinela.h"



int main(void) {
  Lista *l = (Lista*)malloc(sizeof(Lista));
  Iterador i;
  i.l = l;
  Item temp;
  char caractere, texto[10];
  int aux, flag;
  inicializa(l, menor_igual_maior);

  while(scanf("%s%*c", texto) == 1){
 
      if(texto[0] == 'i' && texto[1] == 'm'){
        if(vazia(l)){
          printf("vazia\n");
        } else {
            for(i.no = i.l->sentinela->prox; flag = acabou(i) != 1; proximo(&i)){
                    if(i.no->prox != i.l->sentinela){
                        printf("%c ", i.no->dado.dado);}
                    else{
                        printf("%c\n", i.no->dado.dado);}
                }   
        }
      }

      else if(texto[0] == 'i' && texto[5] == 'e'){
        scanf(" %c", &caractere);
        temp.dado = caractere;
        insere(l, temp);
      }

      else if(texto[0] == 'r' && texto[5] == 'e'){
        scanf(" %c", &caractere);
        temp.dado = caractere;
        retira(l, temp);
      }
    }

  return 0;
}
