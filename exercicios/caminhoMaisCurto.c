#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

// CABEÇALHOS IMPORTANTES
#include "../fila.h"
#include "../grafo.h"
#include "../deque.h"

#define v 5 // Número de vértices do grafo


/**************** EXERCÍCIO ******************
    Dado um i e um j, crie uma função que retorne o caminho mais rápido de acesso a um vértice j a partir de um vértice i.
    RESPOSTA --> gcc exercicios/caminhoMaisCurto.c estruturas/fila.c estruturas/grafo.c estruturas/deque.c -o programa -I.
*/

void buscaLargura(VERTICE *g, int i){
    // Preparação para Busca
    zerarFlags(g);
    zerarVias(g);

    FILA f;
    inicializar_fila(&f);

    enfileirar(&f, i);
    g[i].flag = 1; // DESCOBERTO
    g[i].via = 0; // inicio do caminho
    
    while(f.inicio){
        i = desenfileirar(&f);
        g[i].flag = 2; // CONCLUÍDO

        NO *p = g[i].inicio;
        while(p){ 
            if(g[p->adj].flag == 0){
                g[p->adj].flag = 1; // DESCOBERTO
                enfileirar(&f, p->adj);

                g[p->adj].via = i; // o último ponto visitado antes desse
			}
			p = p->prox;
		}
    }
}

bool caminhoMaisCurto(VERTICE *g, int i, int j){
    // Caso i e j sejam iguais
    if(i == j) return false;
    // Caso não exista caminho de i a j
    if(j == -1) return false;
    
    buscaLargura(g, i);

    DEQUE d; // Armazenando o caminho mais curto
    inicializar_deque(&d);
    inserirComeco_deque(&d, j);
    
    while(j != i && j != -1){
        inserirComeco_deque(&d, g[j].via);
        j = g[j].via; // Atualizando o vértice j para o último ponto visitado
    }
    
    exibirDeque(d);
    return true;
}


/**************** FUNÇÃO DO MAIN ******************/
void main(){
    // Incluindo os quatro vértices numa instância de grafo
    VERTICE *g = (VERTICE*) malloc(sizeof(VERTICE)*(v+1));
    
    inicializarGrafo(g);

    // Inserindo arestas
    inserirAresta(g, 1, 5);
    inserirAresta(g, 1, 3);
    inserirAresta(g, 3, 4);
    inserirAresta(g, 5, 4);
    inserirAresta(g, 5, 2);
    inserirAresta(g, 5, 3);

    caminhoMaisCurto(g, 5, 2);
    caminhoMaisCurto(g, 1, 4);
    
}