#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define v 5
#include "../grafo.h"
#include "../matriz.h"

/**************** EXERCÍCIO ******************
    Seja G = (V;A) um grafo simples e Ḡ = (V; V2-A) seu complemento, onde V2 é o conjunto de todos
    os pares de vértices em V . Escreva um método que, dado um grafo simples G, retorne seu
    complemento Ḡ.

    RESPOSTA --> gcc exercicios/complemento.c estruturas/grafo.c estruturas/matriz.c -o programa -I.
*/
VERTICE *complemento(VERTICE *g){
    VERTICE *g2 = (VERTICE*) malloc(sizeof(VERTICE)*(v+1));
    inicializarGrafo(g2);

    int i, j;
    for(i=1; i<=v; i++){
        for(j=1; j<=v; j++){
            if(!arestaExiste(g, i, j)){
                if(i != j)
                    inserirAresta(g2, i, j);
            }
        }
    }

    return g2;
}

void complemento_M(int m[(v+1)][(v+1)], int m2[(v+1)][(v+1)]){
    int i, j;
    for(i=1; i<=v; i++){
        for(j=1; j<=v; j++){
            if(m[i][j] == 0 && i != j){
                m2[i][j] = 1;
            }
            else{
                m2[i][j] = 0;
            }
        }
    }
}

/**************** FUNÇÃO DO MAIN ******************/
void main(){
    VERTICE *g = (VERTICE*) malloc(sizeof(VERTICE)*(v+1));
    inicializarGrafo(g);
    
    inserirAresta(g, 1, 2);
    inserirAresta(g, 2, 4);
    inserirAresta(g, 1, 5);
    inserirAresta(g, 5, 3);
    inserirAresta(g, 2, 5);
    
    printf("GRAFO:\n");
    exibirGrafo(g);
    VERTICE *g2 = complemento(g); 
    printf("GRAFO COMPLEMENTO:\n");
    exibirGrafo(g2);
    
    printf("\n\n\n");
    
    int m[(v+1)][(v+1)];
    inicializarMatriz(m);
    
    inserirAresta_M(m, 1, 2);
    inserirAresta_M(m, 2, 4);
    inserirAresta_M(m, 1, 5);
    inserirAresta_M(m, 5, 3);
    inserirAresta_M(m, 2, 5);

    printf("MATRIZ:\n");
    exibirMatriz(m);

    int m2[(v+1)][(v+1)];
    complemento_M(m, m2);

    printf("MATRIZ COMPLEMENTO:\n");
    exibirMatriz(m2);

    free(g);
    free(g2);

}