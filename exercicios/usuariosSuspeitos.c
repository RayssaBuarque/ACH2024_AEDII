#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define v 5
#include "../grafo.h"

bool inserirAresta_suspeita(VERTICE* g, int i, int j, int x){
    // Verificando se o grafo existe
    if(g == NULL)
        return false;
    // vendo se a aresta é possível
    if(i == 0 || j == 0)
        return false;
    // vendo se a aresta já existe
    if(arestaExiste(g, i, j))
        return false;

    NO* novo = (NO*) malloc(sizeof(NO));
    novo->adj = j;
    novo->id = x;
    novo->prox = g[i].inicio;
    g[i].inicio = novo;    
    return true;
}

/**************** EXERCÍCIO ******************
    Considere um grafo dirigido em lista de adjacências representando uma rede de troca de emails,
    onde cada vértice representa um usuário, e cada aresta representa um email enviado. Cada aresta
    possui um campo int id que representa o conteúdo da mensagem (ou seja, o campo id faz parte da
    definição do nó das listas de adjacências). Problema: circula pela rede uma mensagem x do tipo
    spam. Escreva um algoritmo para exibir os usuários suspeitos de iniciar a propagação de x. Um
    usuário é considerado suspeito se ele próprio não recebeu a mensagem x nenhuma vez

    RESPOSTA --> gcc exercicios/usuariosSuspeitos.c estruturas/grafo.c -o programa -I.
*/
bool usuariosSuspeitos(VERTICE *g, int x){
    if(g == NULL) // checagem padrao
        return false;
    int i;
    
    // inicializando a matriz
    int emailsRecebidos[(v+1)];
    for(i = 1; i<=v; i++){
        emailsRecebidos[i] = 0; // inicializando o vetor - de inicio, ngm recebe nada
    }

    // fazendo a checagem dos usuarios
    for(i = 1; i<=v; i++){
        NO *p = g[i].inicio;
        while(p){
            if(p->id == x)
                emailsRecebidos[p->adj]++;
            p = p->prox;
        }
    }

    // printando os suspeitos
    printf("Lista de usuários suspeitos de mandar spam: \n {");
    for(i = 1; i<=v; i++){
        if(emailsRecebidos[i] == 0)
            printf(" %d", i);
    }
    printf(" }\n");
    return true;
}

/**************** FUNÇÃO DO MAIN ******************/
int main() {
    VERTICE *g = (VERTICE*) malloc(sizeof(VERTICE)*(v+1));
    inicializarGrafo(g);

    inserirAresta_suspeita(g, 1, 3,1);
    inserirAresta_suspeita(g, 1, 4,1);
    inserirAresta_suspeita(g, 1, 5,1);
    inserirAresta_suspeita(g, 4, 5,1);
    inserirAresta_suspeita(g, 2, 1,4);

    usuariosSuspeitos(g, 1);

}