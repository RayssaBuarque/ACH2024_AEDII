#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../grafo.h"
#define v 5

/**************** EXERCÍCIO ******************
    Seja um grafo g dirigido. Escreva um algoritmo para retornar o grafo transposto de g.
    RESPOSTA --> gcc exercicios/grafoTransposto.c  estruturas/grafo.c -o programa -I.
*/
VERTICE *transposto_list(VERTICE *g){
    // Se o grafo não existir, retornamos ele mesmo
    if(g == NULL)
        return g;

    VERTICE *transposto = (VERTICE*) malloc(sizeof(VERTICE)*(v+1));
    inicializarGrafo(transposto);

    int i;
    for(i=1; i<=5; i++){
        NO *p = g[i].inicio;

        while(p){
            // Criando o novo nó a ser adicionado invertido
            NO *novo = (NO*) malloc(sizeof(NO));
            novo->adj = i; 
            novo->prox = transposto[p->adj].inicio;

            transposto[p->adj].inicio = novo;
            p = p->prox;
        }
    }

    return transposto;
}


/**************** FUNÇÃO DO MAIN ******************/
int main(){

     // Incluindo os quatro vértices numa instância de grafo
     VERTICE *g = (VERTICE*) malloc(sizeof(VERTICE)*(v+1));
    
     inicializarGrafo(g);
 
     // Inserindo arestas
     inserirAresta(g, 5, 5); // LAÇO
     inserirAresta(g, 1, 1); // LAÇO
     inserirAresta(g, 1, 5);
     inserirAresta(g, 1, 3);
     inserirAresta(g, 3, 4);
     inserirAresta(g, 5, 4);
     inserirAresta(g, 5, 2);
     inserirAresta(g, 5, 3);

     VERTICE *t = transposto_list(g);

     exibirGrafo(g);
     exibirGrafo(t);

}