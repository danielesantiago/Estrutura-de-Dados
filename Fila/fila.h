struct no {
    int dados;
    struct no* prox;
};
typedef struct no Node;

struct fila{
    Node* inicio;
    Node* final;
};
typedef struct fila Fila;

Fila* criaFila();
int filaVazia(Fila* fi);
void inserirFila(Fila* fi, int data);
int retirarFila(Fila* fi);
void liberarFila(Fila* fi);
void printar(Fila* fi, int qtd);
int inverterFila(Fila *fi);
void inverter(Fila *fi);
void inverteElementos(Node *no, Node *ant);
