#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define v 5
#include "busca.h"
#include "matriz.h"
#include "grafo.h"

// RESPOSTA --> gcc exercicios/buscaLargura.c estruturas/grafo.c estruturas/fila.c estruturas/matriz.c buscas/largura.c -o programa -I.

void main(){
    VERTICE *g = (VERTICE*)malloc((v+1)*sizeof(VERTICE));
    inicializarGrafo(g);

    int m[(v+1)][(v+1)];
    inicializarMatriz(m);
        int flags[(v+1)];
        zerarFlags_M(flags);

    // Adicionando arestas
    inserirAresta_M(m, 1, 2);
    inserirAresta_M(m, 1, 4);
    inserirAresta_M(m, 4, 5);
    inserirAresta(g, 1, 2);
    inserirAresta(g, 1, 4);
    inserirAresta(g, 4, 5);
    
    // Exibindo matriz
    exibirMatriz(m);
    
    // Executando busca em profundidade
    zerarFlags_M(flags);
    largura_M(m, 1, flags);
    exibirFlags_M(flags);

    printf("\n\n\n");
    // Exibindo grafo
    exibirGrafo(g);

    // Executando busca em profundidade no grafo
    zerarFlags(g);
    largura(g, 1);
    exibirFlags(g);

    // Liberando memória
    free(g);
}