#ifndef BUSCA_H
#define BUSCA_H

#include "grafo.h"
#define v 5

void prof(VERTICE *g, int i);
void prof_M(int m[(v+1)][(v+1)], int i, int flags[(v+1)]);
void largura(VERTICE *g, int i);
void largura_M(int m[(v+1)][(v+1)], int i, int flags[(v+1)]);

#endif
