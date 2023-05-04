typedef struct No{
	int data; //onde guardo os dados
	struct No *prox; // aponta pro próx elemento
	struct No *ant;  // aponta pro elemento anterior
}Node;

typedef struct De{
	int size;
	int maxSize;
	Node *ini; 
	Node *fim;
}Deque;

void start(Deque *d, int max);
int isEmpty(Deque *d);
int isFull(Deque *d);
void pushIni(Deque *d, int numero);
int pushFim(Deque *d, int numero);
int popIni(Deque *d);
int popFim(Deque *d);