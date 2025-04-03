#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../grafoPonderado.h"

#define v 5

void zerarFlags_p(VERTICE_PONDERADO *g){
    // Verificando se o grafo existe
    if(g == NULL)
        return;

    int i;
    for(i = 1; i<=v; i++)
        g[i].flag = 0;
}

void exibirFlags_p(VERTICE_PONDERADO *g){
    // Verificando se o grafo existe
    if(g == NULL)
        return;

    printf("\nEXIBINDO FLAGS:\n");

    int i;
    for(i=1; i<=v; i++){
        printf("V %d -> %d\n", i, g[i].flag);
    }
}

void zerarVias_p(VERTICE_PONDERADO *g){
    // Verificando se o grafo existe
    if(g == NULL)
        return;

    int i;
    for(i = 1; i<=v; i++)
        g[i].via = -1;
}

void exibirVias_p(VERTICE_PONDERADO *g){
    // Verificando se o grafo existe
    if(g == NULL)
        return;

    printf("\nEXIBINDO VIAS:\n");

    int i;
    for(i=1; i<=v; i++){
        printf("V %d -> %d\n", i, g[i].via);
    }
}

void inicializarGrafo_p(VERTICE_PONDERADO *g){
    // Verificando se o grafo existe
    if(g == NULL)
        return;

    int i;
    for(i=1; i<=v; i++){
        g[i].inicio = NULL;
        g[i].flag = 0;
        g[i].via = -1; // não sabemos ainda
    }
}

bool arestaExiste_p(VERTICE_PONDERADO *g, int i, int j){
    // Verificando se o grafo existe
    if(g == NULL)
        return false;

    // Identificando um vértice que corresponde a i
    NO_PONDERADO* aux = g[i].inicio;

    // Percorrendo aux até o final da lista de adjacências
    while(aux){
        if(aux->adj == j)
            return true;
        aux = aux->prox;
    }

    return false;
}

void exibirGrafo_p(VERTICE_PONDERADO *g){
    // se o grafo não existir
    if(g == NULL)
        return;

    int i;
    for(i = 1; i<=v; i++){
        NO_PONDERADO *atual = g[i].inicio;
        printf("V%d -> ", i);

        while(atual){
            printf("%d -> ", atual->adj);
            atual = atual->prox;
        }
        printf("\n");
    }
}

bool inserirAresta_p(VERTICE_PONDERADO* g, int i, int j, int peso){
    // Verificando se o grafo existe
    if(g == NULL)
        return false;
    // vendo se a aresta é possível
    if(i == 0 || j == 0)
        return false;
    // vendo se a aresta já existe
    if(arestaExiste_p(g, i, j))
        return false;

    NO_PONDERADO* novo = (NO_PONDERADO*) malloc(sizeof(NO_PONDERADO));
    novo->adj = j;
    novo->peso = peso;
    novo->prox = g[i].inicio;
    g[i].inicio = novo;
    return true;
}