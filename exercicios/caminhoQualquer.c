#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define v 5
#include "../grafo.h"
#include "../deque.h"
#include "../fila.h"
#include "../matriz.h"

/**************** EXERCÍCIO ******************
    Seja um grafo g e dois vértices a e b. Verifique se há um caminho qualquer entre a e b
    e retorne uma lista dos vértices desse caminho.

    RESPOSTA --> gcc exercicios/caminhoQualquer.c estruturas/grafo.c estruturas/matriz.c estruturas/fila.c estruturas/deque.c -o programa -I.
*/

DEQUE *caminho(VERTICE *g, int a, int b){
    if(g == NULL) return NULL;
    if(a == b) return NULL;

    FILA f;
    inicializar_fila(&f);
    enfileirar(&f, a);
    g[a].flag = 1; // DESCOBERTO

    while(f.inicio){
        g[f.inicio->reg].flag = 2; // CONCLUÍDO
        NO *p = g[f.inicio->reg].inicio;
        while(p){
            if(g[p->adj].flag == 0){
                enfileirar(&f, p->adj);
                g[p->adj].flag = 1; // DESCOBERTO
                g[p->adj].via = f.inicio->reg; // guardando o caminho que viemos
            }
            p = p->prox;
        }

        desenfileirar(&f);
    }

    if(g[b].flag == 0) return NULL; // não há caminho entre a e b

    DEQUE *q = (DEQUE*) malloc(sizeof(DEQUE));
    inicializar_deque(q);

    while(b != a){
        inserirComeco_deque(q, b);
        b = g[b].via; // guardando o caminho que viemos
    }
    inserirComeco_deque(q, a);
    return q;
}

DEQUE *caminho_m(int m[(v+1)][(v+1)], int a, int b){
    if(a == b) return NULL;
    
    // inicializando vetores auxiliares
    int flags[(v+1)];
    int vias[(v+1)];
    int i;
    for(i=1; i<=v; i++){
        flags[i] = 0;
        vias[i] = -1;
    }

    FILA f;
    inicializar_fila(&f);
    enfileirar(&f, a);
    flags[a] = 1; // DESCOBERTO

    int ant;
    while(f.inicio){
        ant = f.inicio->reg;
        for(i = 1; i<=v; i++){
            if(m[ant][i] == 1 // se a conexão (aresta) existir
                && flags[i] == 0){ // se o vértice conectado não foi descoberto ainda
                flags[i] = 1;
                vias[i] = ant; // guardando o caminho que viemos
                enfileirar(&f, i);
            }
        }
        flags[ant] = 2; // CONCLUÍDO
        desenfileirar(&f);
    }

    if(flags[b] == 0) return NULL; // não há caminho entre a e b

    DEQUE *q = (DEQUE*) malloc(sizeof(DEQUE));
    inicializar_deque(q);
    while(a != b){
        inserirComeco_deque(q, b);
        b = vias[b];
    }
    inserirComeco_deque(q, a);
    return q;
}

/**************** FUNÇÃO DO MAIN ******************/
int main() {
    VERTICE *g = (VERTICE*) malloc(sizeof(VERTICE)*(v+1));
    inicializarGrafo(g);
    
    inserirAresta(g, 1, 2);
    inserirAresta(g, 2, 1);
    inserirAresta(g, 1, 5);
    inserirAresta(g, 5, 1);
    inserirAresta(g, 2, 5);
    inserirAresta(g, 5, 2);
    inserirAresta(g, 4, 5);
    inserirAresta(g, 5, 4);
    inserirAresta(g, 4, 3);
    inserirAresta(g, 3, 4);
    inserirAresta(g, 2, 3);
    inserirAresta(g, 3, 2);
    
    zerarFlags(g);
    exibirGrafo(g);
    
    DEQUE *q = caminho(g,4,3);
    exibirDeque(*q);
    
    /////// MATRIZ
    printf("\n***** EXIBINDO COM MATRIZES: *****\n");
    int m[(v+1)][(v+1)];
    inicializarMatriz(m);
    
    inserirAresta_M(m, 1, 2);
    inserirAresta_M(m, 2, 1);
    inserirAresta_M(m, 1, 5);
    inserirAresta_M(m, 5, 1);
    inserirAresta_M(m, 2, 5);
    inserirAresta_M(m, 5, 2);
    inserirAresta_M(m, 4, 5);
    inserirAresta_M(m, 5, 4);
    // inserirAresta_M(m, 4, 3);
    // inserirAresta_M(m, 3, 4);
    inserirAresta_M(m, 2, 3);
    inserirAresta_M(m, 3, 2);

    exibirMatriz(m);
    DEQUE *qM = caminho_m(m,4,3);
    exibirDeque(*qM);

    return 0;
}