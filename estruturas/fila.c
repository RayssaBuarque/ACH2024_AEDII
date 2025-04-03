#include <stdio.h>
#include <stdlib.h>
#include "../fila.h"


void inicializar_fila(FILA *f){
    f->inicio = NULL;
    f->fim = NULL;
}

bool enfileirar(FILA *f, int reg){
    ELEMENTO *novo = malloc(sizeof(ELEMENTO));
    // checando se o espaço foi realmente atribuído (cond. de falha)
    if(novo == NULL)
        return false;
    
    // criando novo elemento com o registro
    novo->reg = reg;
    novo->prox = NULL;

    // acertando os ponteiros
    if(f->fim == NULL) // se ele for o primeiro a entrar na fila:
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}

int desenfileirar(FILA *f){
    // condição de falha: se a fila estiver vazia
    if(f->inicio == NULL)
        return -1;

    // removendo o espaço ocupado originalmente pelo primeiro início
    ELEMENTO *antigo_inicio = f->inicio;
    f->inicio = f->inicio->prox;

    // caso a fila tenha ficado vazia
    if(f->fim == antigo_inicio)
        f->fim = NULL;

    int retorno = antigo_inicio->reg;
    free(antigo_inicio);
    return retorno;
}

void exibirFila(FILA *f){
    ELEMENTO *p = f->inicio;
    printf("FILA: ");
    while(p){
        printf("%d ",p->reg);
        p = p->prox;
    }
    printf("\n");
}