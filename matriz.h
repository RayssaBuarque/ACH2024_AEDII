#ifndef MATRIZ_H
#define MATRIZ_H

#include "grafo.h"
#define v 5

bool inicializarMatriz(int m[(v+1)][(v+1)]);
bool exibirMatriz(int m[(v+1)][(v+1)]);
bool inserirAresta_M(int m[(v+1)][(v+1)], int i, int j);

#endif