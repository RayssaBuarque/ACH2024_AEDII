#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define v 5
#include "../grafo.h"
#include "../fila.h"

void buscaLargura(VERTICE *g, int i){
    // Preparação para Busca
    zerarFlags(g);
    // FILA *f = (FILA*) malloc(sizeof(FILA));
    FILA f;
    inicializar_fila(&f);

    enfileirar(&f, i);
    g[i].flag = 1; // DESCOBERTO
    exibirFila(&f);
    
    while(f.inicio){
        i = desenfileirar(&f);
        g[i].flag = 2; // CONCLUÍDO
        exibirFila(&f);
        
        NO *p = g[i].inicio;
        while(p){ 
            if(g[p->adj].flag == 0){
                g[p->adj].flag = 1; // DESCOBERTO
                enfileirar(&f, p->adj);
                exibirFila(&f);
			}
			p = p->prox;
		}
    }
}

/**************** EXERCÍCIO ******************
    Uma árvore enraizada é um grafo acíclico, conexo e dirigido, com um único vértice fonte de onde
    todas as arestas partem. Escreva um algoritmo que, dado um grafo g, verifique se é uma árvore
    enraizada ou não, retornando true/false conforme o caso.
    RESPOSTA --> gcc exercicios/isArvEnraizada.c  estruturas/grafo.c estruturas/fila.c -o programa -I.
*/
bool isArvEnraizada(VERTICE *g){ // O(n^2)
    // Se o grafo não existir
    if(g == NULL)
        return false;

    // Estratégia: se o grafo for uma a.e. então ao executar uma busca em largura,
    // em ao menos um de seus vértices, todos os flags serão marcados como 2
    int i, j;
    for(i=1; i<=v; i++){
        buscaLargura(g, i); // fazendo a busca a partir de todo vertice i
        int resposta = true;

        for(j=1; j<=v; j++){
            if(g[j].flag != 2){ // nesse caso, já podemos desconsiderar uma arv começando aq
                resposta = false; 
                break;
            }
        }

        if(resposta)
            return resposta;
        resposta = false;
    }
    return false; // se não for uma árvore enraizada em nenhum vertice, retorna false
}

/**************** FUNÇÃO DO MAIN ******************/
int main(){
    // Incluindo os quatro vértices numa instância de grafo
    VERTICE *g = (VERTICE*) malloc(sizeof(VERTICE)*(v+1));
    
    inicializarGrafo(g);

    // Inserindo arestas
    inserirAresta(g, 5, 5); 
    inserirAresta(g, 1, 1); 
    inserirAresta(g, 1, 5); // eliminando essa conexão, o grafo deixa de ser uma a.e.
    inserirAresta(g, 1, 3);
    inserirAresta(g, 3, 4);
    inserirAresta(g, 5, 4);
    inserirAresta(g, 5, 2);
    inserirAresta(g, 5, 3);

    printf("resposta: %d\n", isArvEnraizada(g));

}