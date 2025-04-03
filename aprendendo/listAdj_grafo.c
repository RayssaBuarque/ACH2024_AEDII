#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

#define v 5

#include "../grafo.h"
#include "../fila.h"
#include "../deque.h"


/**************** FUNÇÃO DO MAIN ******************/
void main(){
    // Incluindo os quatro vértices numa instância de grafo
    VERTICE *g = (VERTICE*) malloc(sizeof(VERTICE)*(v+1));
    
    inicializarGrafo(g);

    // Inserindo arestas
    inserirAresta(g, 1, 5);
    inserirAresta(g, 1, 3);
    inserirAresta(g, 3, 4);
    inserirAresta(g, 5, 3);
    inserirAresta(g, 5, 2);
    inserirAresta(g, 5, 4);
    
    printf("%p\n", g[5].inicio);
    esvaziarGrafo(g);

    int i;
    for(i=1; i<=v; i++){
        printf("Vertice %d -> %p com Flag %d\n", i, g[i].inicio, g[i].flag);
    }
    printf("%p\n", g[5].inicio);

}