#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../grafo.h"
#include "../matriz.h"
#define v 5


/**************** EXERCÍCIO ******************
    Escreva um algoritmo que dado um grafo m representado em matriz,
    retorne o mesmo grafo em listas de adjacências.
    RESPOSTA --> gcc exercicios/matrizParaLista.c  estruturas/grafo.c estruturas/matriz.c -o programa -I.
*/
VERTICE *getListaAdj(int m[(v+1)][(v+1)]){
    VERTICE *g = (VERTICE*) malloc(sizeof(VERTICE)*(v+1));
    inicializarGrafo(g);

    int i, j;
    for(i = 1; i<=v; i++){
        for(j=1; j<=v; j++){

            if(m[i][j] == 1){
                NO *novo = (NO*) malloc(sizeof(NO));
                novo->adj = j;
                novo->prox = g[i].inicio;
                g[i].inicio = novo;
            }

        }
    }

    return g;
}


/**************** FUNÇÃO DO MAIN ******************/
int main(){
    int m[(v+1)][(v+1)];

    inicializarMatriz(m);
    inserirAresta_M(m, 5, 5);
    inserirAresta_M(m, 1, 1);
    inserirAresta_M(m, 1, 5);
    inserirAresta_M(m, 1, 3);
    inserirAresta_M(m, 3, 4);
    inserirAresta_M(m, 5, 4);
    inserirAresta_M(m, 5, 2);
    inserirAresta_M(m, 5, 3);

    VERTICE *g = getListaAdj(m);
    exibirGrafo(g);
    exibirMatriz(m);

}