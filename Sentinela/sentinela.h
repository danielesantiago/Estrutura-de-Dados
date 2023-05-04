typedef struct{
  int dado;
}Item;

typedef  struct  elemento Node;

struct elemento{
  Item dado;
  Node *prox;
  Node *ant;
};

typedef struct{
   Node *sentinela;
   int quantidade;
   int (*menor)(Item i1, Item i2);
}Lista;

typedef struct{
  Node *no;
  Lista *l;
}Iterador;


void inicializa(Lista *l, int(*menor_igual_maior) (Item i1, Item i2));
void destroi(Lista* l);
int vazia(Lista *l);
void insere(Lista *l, Item i);
void retira(Lista *l, Item item);
Iterador primeiro(Lista *l);
Iterador ultimo(Lista *l);
int elementov(Iterador i, Item* item);
Item elemento(Iterador i);
int proximo(Iterador* i);
int anterior(Iterador* i);
int acabou(Iterador i);
int menor_igual_maior(Item a, Item b);