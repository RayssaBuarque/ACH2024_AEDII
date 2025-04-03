#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../grafo.h"

#define v 5 // Número de vértices do grafo


void zerarFlags(VERTICE *g){
    // Verificando se o grafo existe
    if(g == NULL)
        return;

    int i;
    for(i = 1; i<=v; i++)
        g[i].flag = 0;
}

void exibirFlags(VERTICE *g){
    // Verificando se o grafo existe
    if(g == NULL)
        return;

    printf("\nEXIBINDO FLAGS:\n");

    int i;
    for(i=1; i<=v; i++){
        printf("V %d -> %d\n", i, g[i].flag);
    }
}

void zerarVias(VERTICE *g){
    // Verificando se o grafo existe
    if(g == NULL)
        return;

    int i;
    for(i = 1; i<=v; i++)
        g[i].via = -1;
}

void exibirVias(VERTICE *g){
    // Verificando se o grafo existe
    if(g == NULL)
        return;

    printf("\nEXIBINDO VIAS:\n");

    int i;
    for(i=1; i<=v; i++){
        printf("V %d -> %d\n", i, g[i].via);
    }
}

void inicializarGrafo(VERTICE *g){
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

bool arestaExiste(VERTICE *g, int i, int j){
    // Verificando se o grafo existe
    if(g == NULL)
        return false;
    // Identificando um vértice que corresponde a i
    NO* aux = g[i].inicio;

    // Percorrendo aux até o final da lista de adjacências
    while(aux){
        if(aux->adj == j)
            return true;
        aux = aux->prox;
    }

    return false;
}

void exibirGrafo(VERTICE *g){
    // se o grafo não existir
    if(g == NULL)
        return;

    int i;
    for(i = 1; i<=v; i++){
        NO *atual = g[i].inicio;
        printf("V%d -> ", i);

        while(atual){
            printf("%d -> ", atual->adj);
            atual = atual->prox;
        }
        printf("\n");
    }
}

bool inserirAresta(VERTICE* g, int i, int j){
    // Verificando se o grafo existe
    if(g == NULL)
        return false;
    // vendo se a aresta é possível
    if(i == 0 || j == 0)
        return false;
    // vendo se a aresta já existe
    if(arestaExiste(g, i, j))
        return false;

    NO* novo = (NO*) malloc(sizeof(NO));
    novo->adj = j;
    novo->prox = g[i].inicio;
    g[i].inicio = novo;    
    return true;
}

// Escreva um algoritmo para destruir as arestas de um grafo, tornando-o vazio.
bool esvaziarGrafo(VERTICE *g){
    // Verificando se o grafo existe
    if(g == NULL)
        return false;
    
    int i;
    for(i=1; i<=v;i++){
        NO *aux = g[i].inicio;
        while(aux){
            NO *removido = aux;
            aux = removido->prox;
            printf("aux: %p\n", aux);
            free(removido);
        }
    }

    return true;
}