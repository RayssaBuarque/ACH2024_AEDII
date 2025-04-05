#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define v 5
#include "../grafo.h"

/**************** EXERCÍCIO ******************
    Seja um grafo g não-dirigido. Escreva uma função para detectar ciclos em g,
    retornando true/false

    NOTA:: um grafo não-dirigido tem suas arestas registradas em ambas as direções.

    RESPOSTA --> gcc exercicios/detectorCiclos.c estruturas/grafo.c -o programa -I.
*/
bool detectorCiclos(VERTICE *g, int i, bool ciclos){
    // checando se o grafo existe mesmo
    if(g == NULL) return false;

    NO *p = g[i].inicio;
    g[i].flag = 1; // DESCOBERTO

    while(p){
        if(g[p->adj].flag == 0){
            g[p->adj].via = i; // guardando o caminho que viemos
            ciclos = detectorCiclos(g, p->adj, ciclos);
        }
        if(g[p->adj].flag == 1 && g[i].via != p->adj){
            ciclos = true;
        } 
        p = p->prox;
    }
    g[i].flag = 2; // CONCLUÍDO

    return ciclos;
}

/*
    VARIAÇÃO:
    Variação 1: remover as arestas que provocam ciclo.
*/
void eliminarCiclos(VERTICE *g, int i){
    if(g == NULL) return;

    NO *p = g[i].inicio;
    NO *ant = NULL;
    g[i].flag = 1; // DESCOBERTO
    
    while(p){
        if(g[p->adj].flag == 0){
            g[p->adj].via = i;
            eliminarCiclos(g, p->adj);
            ant = p;
            p = p->prox;
            continue;
        }
        if(g[p->adj].flag == 1 && g[i].via != p->adj){
            if(ant == NULL){
                g[i].inicio = p->prox; // remove o primeiro nó
                free(p);
                p = g[i].inicio;
                printf("\nremovendo conexão em %d\n", i);
                continue;
            }
            
            ant->prox = p->prox; // remove o nó atual
            free(p);
            p = ant->prox;
            continue;
        }
        ant = p;
        p = p->prox;
    }
}

/*
    VARIAÇÃO:
    Variação 2: retornar o comprimento (i.e., a quantidade de arestas) do maior ciclo encontrado.
*/
int tamanhoCiclo(VERTICE *g, int i, int f){
    int contador = 1;
    
    // Percorrendo as vias do ciclo até o "início"
    while(f != i){
        contador++;
        f = g[f].via;
    }
    return contador;
}
void maiorCiclo(VERTICE *g, int i, int *maior){ // maior é inicializado como zero
    if(g == NULL) return;
    
    NO *p = g[i].inicio;
    g[i].flag = 1; // DESCOBERTO

    while(p){
        if(g[p->adj].flag == 0){
            g[p->adj].via = i;
            maiorCiclo(g, p->adj, maior);
        }
        if(
            (g[p->adj].flag == 1 || g[p->adj].flag == -1) // se a flag do próximo elemento for 1 ou -1, então ele já passou por aq antes (ciclo)
            && (g[i].via != p->adj && g[p->adj].via != i)){ // é importante verificar se os dois não são diretamente conectados por ambos os lados (visto q o grafo é não-dirigido)
            int tamanho = tamanhoCiclo(g, p->adj, i);
            // printf("tamanho do ciclo atual: %d\n", tamanho); -- DEBUG
            if(tamanho > *maior) *maior = tamanho; // se o tamanho do ciclo identificado for maior q o maior, atualize
        }
        p = p->prox;
    }

    g[i].flag = 2;
}


/**************** FUNÇÃO DO MAIN ******************/
int main() {
    VERTICE *g = (VERTICE*) malloc(sizeof(VERTICE)*(v+1));
    inicializarGrafo(g);
    
    inserirAresta(g, 1, 2);
    inserirAresta(g, 2, 1);
    inserirAresta(g, 1, 5);
    inserirAresta(g, 5, 1);
    inserirAresta(g, 2, 5);
    inserirAresta(g, 5, 2);
    inserirAresta(g, 4, 5);
    inserirAresta(g, 5, 4);
    inserirAresta(g, 4, 3);
    inserirAresta(g, 3, 4);
    inserirAresta(g, 2, 3);
    inserirAresta(g, 3, 2);
    
    zerarFlags(g);
    exibirGrafo(g);
    
    printf("Ha ciclo? %d\n", detectorCiclos(g, 1, false));

    // Testando cada um dos nós, para ver se há ciclos diferentes partindo de alcances diferentes
    int maior = 0;
    int i;
    for(i = 1; i<=v; i++){
        zerarFlags(g);
        zerarVias(g);
        maiorCiclo(g, i, &maior);
    }
    printf("O tamanho do maior ciclo e %d\n", maior);

    zerarFlags(g);
    eliminarCiclos(g, 1);
    exibirGrafo(g);

    return 0;
}