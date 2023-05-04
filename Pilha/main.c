#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Main.c
int main() {
int numOperacoes;
  char texto;
  struct caractere c;
  struct caractere d;
  int flag;
  
  scanf("%d", &numOperacoes);
  scanf("%*c");
  for(int r = 0; r < numOperacoes; r++){
    Pilha *pi;
    pi = start();
    int x;

    while(1){
    scanf("%c", &texto);

    if(texto == '\n')
      break;
      
      flag = 1;

      if(texto == '('){
        c.data = texto;
        x = inserirDados(pi, c);
      }

      if(texto == ')'){
        if(emptyPilha(pi)){
          flag = 0;
          break;
        } else {
          d = consultaDados(pi, &c);
          if(d.data == '('){
            x = removerDados(pi);
          } else {
            x = inserirDados(pi, c);
          }
        }
      }

            if(texto == '['){
        c.data = texto;
        x = inserirDados(pi, c);
      }

      if(texto == ']'){
        if(emptyPilha(pi)){
          flag = 0;
          break;
        } else {
          d = consultaDados(pi, &c);
          if(d.data == '['){
            x = removerDados(pi);
          } else {
            x = inserirDados(pi, c);
          }
        }
      }

            if(texto == '{'){
        c.data = texto;
        x = inserirDados(pi, c);
      }

      if(texto == '}'){
        if(emptyPilha(pi)){
          flag = 0;
          break;
        } else {
          d = consultaDados(pi, &c);
          if(d.data == '{'){
            x = removerDados(pi);
          } else {
            x = inserirDados(pi, c);
          }
        }
      } 

    }

    if(emptyPilha(pi) && flag){
      printf("S\n"); 
    } else {
      printf("N\n");
    }
    
    liberaPilha(pi);


  }



    return 0;
}
  