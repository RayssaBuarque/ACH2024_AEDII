#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../deque.h"


void inicializar_deque(DEQUE *d){
    d->cabeca = (ELEMENTO_D*) malloc(sizeof(ELEMENTO_D));

    // Como ponto central, a cabeça de um deque vazio retorna a si mesma
    d->cabeca->prox = d->cabeca;
    d->cabeca->ant = d->cabeca;
}

int tamanhoDeque(DEQUE *d){
    int tamanho = 0;
    ELEMENTO_D * atual = d->cabeca;

    while(atual->prox != d->cabeca){
        tamanho++;
        atual = atual->prox;
    }

    return tamanho;
}

bool inserirComeco_deque(DEQUE *d, int reg){
    ELEMENTO_D *novo = (ELEMENTO_D*) malloc(sizeof(ELEMENTO_D));
    if(novo == NULL)
        return false;

    novo->reg = reg;
    novo->ant = d->cabeca;
    novo->prox = d->cabeca->prox;

    d->cabeca->prox->ant = novo;
    d->cabeca->prox = novo;

    return true;
}

bool inserirFinal_deque(DEQUE *d, int reg){
    ELEMENTO_D *novo = (ELEMENTO_D*) malloc(sizeof(ELEMENTO_D));
    if(novo == NULL)
        return false;

    novo->reg = reg;
    novo->prox = d->cabeca;
    novo->ant = d->cabeca->ant;

    d->cabeca->ant->prox = novo;
    d->cabeca->ant = novo;

    return true;
}

int removerComeco_deque(DEQUE *d){
    // se não houverem itens no DEQUE
    if(d->cabeca->prox == d->cabeca)
        return -1;

    ELEMENTO_D *removido = d->cabeca->prox;
    int reg = removido->reg;

    d->cabeca->prox = removido->prox;
    d->cabeca->prox->ant = d->cabeca;
    free(removido);
    return reg;
}

int removerFinal_deque(DEQUE *d){
    // se não houverem itens no DEQUE
    if(d->cabeca->ant == d->cabeca)
        return -1;

    ELEMENTO_D *removido = d->cabeca->ant;
    int reg = removido->reg;

    d->cabeca->ant = removido->ant;
    d->cabeca->ant->prox = d->cabeca;
    free(removido);

    return reg;
}

void exibirDeque(DEQUE d){
    ELEMENTO_D *atual = (ELEMENTO_D*) malloc(sizeof(ELEMENTO_D));
    atual = d.cabeca->prox;

    printf("EXIBINDO DEQUE:\n");
    while(atual != d.cabeca){
        printf("%d ", atual->reg);
        atual = atual->prox;
    }
    printf("\n");
}
