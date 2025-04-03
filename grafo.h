#ifndef GRAFO_H
#define GRAFO_H


// Estrutura geral de NÓ (que representa um aresta)
typedef struct n{
    int adj;
    int id;
    struct n* prox;
}NO;

// Estrutura geral que segura a informação de um vértice
typedef struct s{
    NO* inicio;
    int flag;
    int via;
} VERTICE;

void zerarFlags(VERTICE *g);
void exibirFlags(VERTICE *g);
void zerarVias(VERTICE *g);
void exibirVias(VERTICE *g);
void inicializarGrafo(VERTICE *g);
void exibirGrafo(VERTICE *g);
bool arestaExiste(VERTICE *g, int i, int j);
bool inserirAresta(VERTICE* g, int i, int j);
bool esvaziarGrafo(VERTICE *g);

#endif