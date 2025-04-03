#ifndef GRAFOPONDERADO_H
#define GRAFOPONDERADO_H

typedef struct np{
    int adj;
    int peso;
    struct np *prox;
}NO_PONDERADO;

typedef struct vp{
    NO_PONDERADO * inicio;
    int flag;
    int via;
}VERTICE_PONDERADO;


void zerarFlags_p(VERTICE_PONDERADO *g);
void exibirFlags_p(VERTICE_PONDERADO *g);
void zerarVias_p(VERTICE_PONDERADO *g);
void exibirVias_p(VERTICE_PONDERADO *g);
void inicializarGrafo_p(VERTICE_PONDERADO *g);
bool arestaExiste_p(VERTICE_PONDERADO *g, int i, int j);
void exibirGrafo_p(VERTICE_PONDERADO *g);
bool inserirAresta_p(VERTICE_PONDERADO* g, int i, int j, int peso);

#endif