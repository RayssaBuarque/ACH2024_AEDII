#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define v 5
#include "../grafoPonderado.h"


/**************** EXERCÍCIO ******************
    Seja um grafo g não-dirigido ponderado (com um peso inteiro associado a cada aresta).
    Escreva um algoritmo que, dado g e um custo mínimo int c, retorne uma cópia de g
    contendo apenas as arestas de custo maior do que c.
    RESPOSTA --> gcc exercicios/custoMinimo.c  estruturas/grafoPonderado.c -o programa -I.
*/
VERTICE_PONDERADO * grafoCustoMinimo(VERTICE_PONDERADO* g, int c){
    // Verificando se o grafo existe
    if(g == NULL)
        return NULL;
    
    VERTICE_PONDERADO *copia = (VERTICE_PONDERADO*) malloc(sizeof(VERTICE_PONDERADO)*(v+1));
    
    int i;
    for(i = 1; i<=v; i++){
        copia->flag = 0;
        copia->via = -1; // não sabemos ainda
        copia[i].inicio = NULL;

        NO_PONDERADO* p = g[i].inicio;
        while(p){
            if(p->peso > c){
                NO_PONDERADO *novo = (NO_PONDERADO*) malloc(sizeof(NO_PONDERADO));
                novo->adj = p->adj;
                novo->peso = p->peso;
                novo->prox = copia[i].inicio;
                copia[i].inicio = novo;
            }
            p = p->prox;
        }
    }

    return copia;
}


/**************** FUNÇÃO DO MAIN ******************/
int main(){
    // Incluindo os quatro vértices numa instância de grafo
    VERTICE_PONDERADO *g = (VERTICE_PONDERADO*) malloc(sizeof(VERTICE_PONDERADO)*(v+1));
    
    inicializarGrafo_p(g);

    inserirAresta_p(g, 1, 2, 4);
    inserirAresta_p(g, 1, 3, 2);
    exibirGrafo_p(g);

    printf("\n\n\n");
    VERTICE_PONDERADO *alternativo = grafoCustoMinimo(g, 3);
    exibirGrafo_p(alternativo);
}