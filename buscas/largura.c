#include <stdio.h>
#include <stdbool.h>

#include "../grafo.h"
#include "../matriz.h"
#include "../fila.h"
#define v 5

void largura(VERTICE *g, int i){
    if(g == NULL) return;
    zerarFlags(g);

    FILA f;
    inicializar_fila(&f);

    enfileirar(&f, i);
    g[i].flag = 1; // DESCOBERTO

    while(f.inicio){
        g[f.inicio->reg].flag = 2; // CONCLUÍDO
        i = f.inicio->reg;
        desenfileirar(&f);

        NO *p = g[i].inicio;
        while(p){
            if(g[p->adj].flag == 0){
                g[p->adj].flag = 1; // DESCOBERTO
                enfileirar(&f, p->adj);
            }
            p = p->prox;
        }
    }
}

void largura_M(int m[(v+1)][(v+1)], int i, int flags[(v+1)]){
    FILA f;
    inicializar_fila(&f);

    zerarFlags_M(flags);
    flags[i] = 1; // DESCOBERTO

    enfileirar(&f, i);
    while(f.inicio){
        flags[f.inicio->reg] = 2; // CONCLUÍDO
        i = f.inicio->reg;
        desenfileirar(&f);

        int j;
        for(j=1; j<=v; j++){
            if(m[i][j] == 1 && flags[j] == 0){
                enfileirar(&f, j);
                flags[j] = 1; // DESCOBERTO
            }
        }
    }
}