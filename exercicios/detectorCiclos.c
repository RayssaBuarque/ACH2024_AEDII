#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define v 5
#include "../grafo.h"

/**************** EXERCÍCIO ******************
    Seja um grafo g não-dirigido. Escreva uma função para detectar ciclos em g,
    retornando true/false

    NOTA:: um grafo não-dirigido tem suas arestas registradas em ambas as direções.

    RESPOSTA --> gcc exercicios/detectorCiclos.c estruturas/grafo.c -o programa -I.
*/
bool detectorCiclos(VERTICE *g, int i, bool ciclos){
    // checando se o grafo existe mesmo
    if(g == NULL) return false;

    NO *p = g[i].inicio;
    g[i].flag = 1; // DESCOBERTO

    while(p){
        if(g[p->adj].flag == 0){
            g[p->adj].via = i; // guardando o caminho que viemos
            ciclos = detectorCiclos(g, p->adj, ciclos);
        }
        if(g[p->adj].flag == 1 && g[i].via != p->adj){
            ciclos = true;
        } 
        p = p->prox;
    }
    g[i].flag = 2; // CONCLUÍDO

    return ciclos;
}

/*
    VARIAÇÃO:
    Variação 1: remover as arestas que provocam ciclo.
*/
void eliminarCiclos(VERTICE *g, int i){
    if(g == NULL) return;

    NO *p = g[i].inicio;
    NO *ant = NULL;
    g[i].flag = 1; // DESCOBERTO
    
    while(p){
        if(g[p->adj].flag == 0){
            g[p->adj].via = i;
            eliminarCiclos(g, p->adj);
            ant = p;
            p = p->prox;
            continue;
        }
        if(g[p->adj].flag == 1 && g[i].via != p->adj){
            if(ant == NULL){
                g[i].inicio = p->prox; // remove o primeiro nó
                free(p);
                p = g[i].inicio;
                printf("\nremovendo conexão em %d\n", i);
                continue;
            }
            
            ant->prox = p->prox; // remove o nó atual
            free(p);
            p = ant->prox;
            continue;
        }
        ant = p;
        p = p->prox;
    }
}


/**************** FUNÇÃO DO MAIN ******************/
int main() {
    VERTICE *g = (VERTICE*) malloc(sizeof(VERTICE)*(v+1));
    inicializarGrafo(g);

    // inserirAresta(g, 1, 4);
    inserirAresta(g, 1, 3);
    inserirAresta(g, 2, 4);
    inserirAresta(g, 3, 4);
    inserirAresta(g, 3, 1);
    inserirAresta(g, 4, 1);
    inserirAresta(g, 4, 2);

    exibirGrafo(g);

    printf("Ha ciclo? %d\n", detectorCiclos(g, 1, false));

    zerarFlags(g);
    eliminarCiclos(g, 1);
    exibirGrafo(g);

    
    return 0;
}