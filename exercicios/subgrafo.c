#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define v 5
#include "../grafo.h"
#include "../matriz.h"

/**************** EXERCÍCIO ******************
    Sejam dois grafos g1 e g2 contendo exatamente os mesmos vértices.
    Verifique se g2 é um subgrafo de g1, retornando true/false conforme o caso.
    Para tornar o problema mais interessante, considere que um grafo é
    representado em listas e outro em matriz.

    NOTA:: um subgrafo seria um grafo com os mesmos vértices de outro
            e cujas >ARESTAS< também fazem parte do conjunto.

    RESPOSTA --> gcc exercicios/subgrafo.c estruturas/grafo.c estruturas/matriz.c -o programa -I.
*/
bool isSubgrafo(int g1[(v+1)][(v+1)], VERTICE *g2){
    // Checando se g2 existe
    if(g2 == NULL)
        return false;
    
    int i;
    bool resposta = true;
    for(i=1; i<=v; i++){
        NO *p = g2[i].inicio;
        while(p){
            if(g1[i][p->adj] != 1){
                resposta = false;
                break;
            }
            p = p->prox;
        }

        if(!resposta)
            break;
    }

    return resposta;

}

/**************** FUNÇÃO DO MAIN ******************/
int main() {
    int m[(v+1)][(v+1)];
    inicializarMatriz(m);

    VERTICE *g = (VERTICE*) malloc(sizeof(VERTICE)*(v+1));
    inicializarGrafo(g);

    inserirAresta_M(m, 1, 2);
    inserirAresta(g, 1, 2);
    inserirAresta(g, 1, 4);

    printf("resposta: %d\n", isSubgrafo(m, g));

    
    return 0;
}