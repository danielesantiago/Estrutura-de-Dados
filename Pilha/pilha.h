// Pilha.h
struct caractere{
  char data;
} Caractere;

typedef struct elemento* Pilha;

struct elemento{
  struct caractere dados;
  struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* start();
int fullPilha(Pilha* pi);
int emptyPilha(Pilha* pi);
int inserirDados(Pilha* pi, struct caractere c);
int removerDados(Pilha* pi);
struct caractere consultaDados(Pilha *pi, struct caractere *c);
void liberaPilha(Pilha* pi);
