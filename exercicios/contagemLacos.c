#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../grafo.h"
#define v 5 // Número de vértices do grafo

/**************** EXERCÍCIO ******************
    Escreva um algoritmo para contar a quantidade de laços em um grafo.
    Variação: Remover todos os laços encontrados.
    RESPOSTA --> gcc exercicios/contagemLacos.c  estruturas/grafo.c -o programa -I.
*/
int contarLacos(VERTICE *g){
    int contador = 0;
    int i = 0;

    for(i=1; i<=v; i++){
        if(arestaExiste(g, i, i))
            contador++;
    }

    return contador;
}

// OPÇÃO SEM O USO DE 'ARESTAEXISTE()'
int contarLacos_v2(VERTICE *g){
    int contador = 0;
    int i = 0;

    for(i=1; i<=v; i++){
        NO *atual = g[i].inicio;
        while(atual){
            if(atual->adj == i)
                contador++;
            atual = atual->prox;
        }
    }

    return contador;
}

// VARIAÇÃO QUE REMOVE LAÇOS ENCONTRADOS -- O(n^2)
int contarLacos_var(VERTICE *g){
    int contador = 0;
    int i = 0;

    for(i=1; i<=v; i++){
        NO *atual = g[i].inicio;

        if(atual == NULL)
            continue; // não há arestas para remover

        // Caso o primeiro nó da lista seja o laço
        if(atual->adj == i){
            contador++;
            NO *removido = atual;
            g[i].inicio = removido->prox;
            printf("%p %p -- ", g[i].inicio, removido);
            free(removido);
            continue; // não há mais arestas para remover
        }
        
        // usar um anterior definido fora do while
        // e um if que checa se o anterior foi definido ou não
        
        while(atual->prox){
            if(atual->prox->adj == i){
                contador++;
                NO *removido = atual->prox;
                atual->prox = removido->prox;
                free(removido);
                break; // não há mais arestas para remover
            }
            atual = atual->prox;
        }
    }

    return contador;
}
int contarLacos_var2(VERTICE *g){ // NAO FUNCIONA
    if(g == NULL) // se o grafo não existir
        return -1;

    int contador = 0;
    int i = 0;

    for(i=1; i<=v; i++){
        NO *atual = g[i].inicio;
        NO *anterior = g[i].inicio;
        
        // usar um anterior definido fora do while
        // e um if que checa se o anterior foi definido ou não
        
        while(atual){
            if(atual->adj == i){
                contador++;

                NO *removido = atual;
                atual = removido->prox;

                if(!anterior){
                    g[i].inicio = atual;  
                }

                free(removido);
                break; // não há mais arestas para remover
            }
            anterior = atual;
            atual = atual->prox;
        }
    }

    return contador;
}

/**************** FUNÇÃO DO MAIN ******************/
int main(){

    // Incluindo os quatro vértices numa instância de grafo
    VERTICE *g = (VERTICE*) malloc(sizeof(VERTICE)*(v+1));
    
    inicializarGrafo(g);

    // Inserindo arestas
    inserirAresta(g, 5, 5); // LAÇO
    inserirAresta(g, 1, 1); // LAÇO
    inserirAresta(g, 4, 4); // LAÇO
    inserirAresta(g, 2, 2); // LAÇO
    inserirAresta(g, 4, 4); // 'LAÇO'
    inserirAresta(g, 1, 5);
    inserirAresta(g, 1, 3);
    inserirAresta(g, 3, 4);
    inserirAresta(g, 5, 4);
    inserirAresta(g, 5, 2);
    inserirAresta(g, 5, 3);

    // Exercício:
    int numero_lacos = contarLacos(g);
    printf("V1 Esse grafo contem %d laco(s).\n", numero_lacos);
    numero_lacos = contarLacos_v2(g);
    printf("V2 Esse grafo contem %d laco(s).\n", numero_lacos);
    
    // Variação:
    numero_lacos = contarLacos_var2(g);
    printf("Os lacos foram removidos.\n");
    printf("VAR Esse grafo continha %d laco(s).\n", numero_lacos);
    numero_lacos = contarLacos(g);
    printf("VAR Esse grafo contem %d laco(s).\n", numero_lacos);

    return 0;
}