#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define v 5
#include "../grafo.h"

/**************** EXERCÍCIO ******************
    Dados dois grafos g1 e g2, escreva um algoritmo que retorne um grafo g3
    cujas arestas estejam presentes em g1 mas não em g2.

    RESPOSTA --> gcc exercicios/arestasAusentes.c estruturas/grafo.c -o programa -I.
*/
VERTICE *arestasAuxentes(VERTICE *g1, VERTICE *g2){
    // Checando se os grafos existem
    if(g1 == NULL || g2 == NULL)
        return false;
    
    VERTICE *g3 = (VERTICE *) malloc(sizeof(VERTICE)*(v+1));
    
    int i;
    for(i=1; i<=v; i++){
        // Inicializando o vertice correspondente em g3
        g3[i].inicio = NULL;
        g3[i].flag = 0;
        g3[i].via = -1;

        // Iterando os vértices do g1
        NO *p = g1[i].inicio;
        while(p){
            bool existeAresta = false;
            NO *q = g2[i].inicio;

            // Iterando os vértices do g2
            while(q){
                if(q->adj == p->adj){
                    existeAresta = true;
                    break; // A aresta já existe 
                }
                q = q->prox;
            }

            if(!existeAresta){
                NO *novo = (NO*) malloc(sizeof(NO));
                novo->adj = p->adj;
                novo->prox = g3[i].inicio;
                g3[i].inicio = novo;
            }
            p = p->prox;
        }
    }
    
    return g3;
}

/**************** FUNÇÃO DO MAIN ******************/
int main() {
    // Incluindo os quatro vértices numa instância de grafo
    VERTICE *g1 = (VERTICE*) malloc(sizeof(VERTICE)*(v+1));
    VERTICE *g2 = (VERTICE*) malloc(sizeof(VERTICE)*(v+1));
    
    inicializarGrafo(g1);
    inicializarGrafo(g2);

    // Inserindo arestas
    inserirAresta(g1, 5, 5); // LAÇO
    inserirAresta(g2, 5, 5); // LAÇO
    inserirAresta(g1, 1, 1); // LAÇO
    inserirAresta(g2, 1, 1); // LAÇO
    inserirAresta(g1, 1, 5);
    inserirAresta(g2, 1, 5);
    inserirAresta(g1, 1, 3);
    inserirAresta(g2, 1, 3);
    inserirAresta(g1, 3, 4);
    // inserirAresta(g2, 3, 4);
    inserirAresta(g1, 5, 4);
    inserirAresta(g2, 5, 4);
    inserirAresta(g1, 5, 2);
    // inserirAresta(g2, 5, 2);
    inserirAresta(g1, 5, 3);
    inserirAresta(g2, 5, 3);

    VERTICE *g3 = arestasAuxentes(g1, g2);
    exibirGrafo(g1);
    printf("\n");
    exibirGrafo(g3);

    return 0;
}