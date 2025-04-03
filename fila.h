#ifndef FILA_H
#define FILA_H

#include <stdbool.h>


/**************** ESTRUTURAS ******************/
typedef struct ELEMENTO_{
    int reg;
    struct ELEMENTO_* prox;
} ELEMENTO;

typedef struct{
    ELEMENTO *inicio;
    ELEMENTO *fim;
} FILA;


/**************** PROTÓTIPOS ******************/
void inicializar_fila(FILA *f);
bool enfileirar(FILA *f, int reg);
int desenfileirar(FILA *f);
void exibirFila(FILA *f);

#endif // FILA_H