#ifndef DEQUE_H
#define DEQUE_H


/**************** ESTRUTURAS ******************/
typedef struct ELEMENTOD_{
    int reg;
    struct ELEMENTOD_* prox;
    struct ELEMENTOD_* ant;
} ELEMENTO_D;

typedef struct {
	ELEMENTO_D *cabeca;
} DEQUE;

/**************** PROTÓTIPOS ******************/
void inicializar_deque(DEQUE *d);
int tamanhoDeque(DEQUE *d);
bool inserirComeco_deque(DEQUE *d, int reg);
bool inserirFinal_deque(DEQUE *d, int reg);
int removerComeco_deque(DEQUE *d);
int removerFinal_deque(DEQUE *d);
void exibirDeque(DEQUE d);

#endif