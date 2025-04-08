#include <stdio.h>
#include <stdbool.h>

#include "../grafo.h"
#define v 5

void prof(VERTICE *g, int i){
    if(g == NULL) return;

    g[i].flag = 1; // DESCOBERTO
    NO *p = g[i].inicio;

    while(p){
        if(g[p->adj].flag == 0)
            prof(g, p->adj);
        
        p = p->prox;
    }

    g[i].flag = 2; // CONCLUÍDO
}

void prof_M(int m[(v+1)][(v+1)], int i, int flags[(v+1)]){
    flags[i] = 1; // DESCOBERTO
    
    int j;
    for(j=1; j<=v; j++){
        if(m[i][j] == 1 && flags[j] == 0){
            prof_M(m, j, flags);
        }
    }

    flags[i] = 2; // CONCLUÍDO
}