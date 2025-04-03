#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 



/**************** ESTRUTURAS BASE ******************/

#define v 5 // Número de vértices do grafo

// Estrutura geral de NÓ (que representa um aresta)
typedef struct n{
    int adj;
    struct n* prox;
}NO;

// Estrutura geral que segura a informação de um vértice
typedef struct s{
    NO* inicio;
    int flag;
} VERTICE;



/**************** FUNÇÕES GERAIS ******************/

// Função que verifica se uma aresta existe
bool arestaExiste(VERTICE *g, int i, int j){
    // Identificando um vértice que corresponde a i
    NO* aux = g[i].inicio;

    // Percorrendo aux até o final da lista de adjacências
    while(aux){
        if(aux->adj == j)
            return true;
        aux = aux->prox;
    }

    return false;
}

// Zerando as flags de todos os vértices do grafo:
void zerarFlags(VERTICE *g){
    int i;
    for(i = 1; i<=v; i++)
        g[i].flag = 0;
}

// Inicializando um grafo do zero
void inicializarGrafo(VERTICE *g){
    int i;
    for(i=1; i<=v; i++){
        g[i].inicio = NULL;
        g[i].flag = 0;
    }
}

// Função que insere uma aresta no grafo
bool inserirAresta(VERTICE* g, int i, int j){
    // vendo se a aresta já existe
    if(arestaExiste(g, i, j))
        return false;

    NO* novo = (NO*) malloc(sizeof(NO));
    novo->adj = j;
    novo->prox = g[i].inicio;
    g[i].inicio = novo;    
    return true;
}

void exibirFlags(VERTICE *g){
    printf("\nEXIBINDO FLAGS:\n");

    int i;
    for(i=1; i<=v; i++){
        printf("V %d -> %d\n", i, g[i].flag);
    }
}


/**************** BUSCA EM LARGURA ******************/
typedef struct ELEMENTO_{
    int reg;
    struct ELEMENTO_* prox; // referenciando um ponteiro para um elemento
    // outros campos...
} ELEMENTO; // apelidando a struct pra facilitar nossa vida a partir daq

typedef struct{
    ELEMENTO *inicio;
    ELEMENTO *fim;
} FILA;

void inicializar_fila(FILA *f){
    f->inicio = NULL;
    f->fim = NULL;
}

bool enfileirar(FILA *f, int reg){
    ELEMENTO *novo = malloc(sizeof(ELEMENTO));
    // checando se o espaço foi realmente atribuído (cond. de falha)
    if(novo == NULL)
        return false;
    
    // criando novo elemento com o registro
    novo->reg = reg;
    novo->prox = NULL;

    // acertando os ponteiros
    if(f->fim == NULL) // se ele for o primeiro a entrar na fila:
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}
int desenfileirar(FILA *f){
    // condição de falha: se a fila estiver vazia
    if(f->inicio == NULL)
        return -1;

    // removendo o espaço ocupado originalmente pelo primeiro início
    ELEMENTO *antigo_inicio = f->inicio;
    f->inicio = f->inicio->prox;

    // caso a fila tenha ficado vazia
    if(f->fim == antigo_inicio)
        f->fim = NULL;

    int retorno = antigo_inicio->reg;
    free(antigo_inicio);
    return retorno;
}

void exibirFila(FILA *f){
    ELEMENTO *p = f->inicio;
    printf("FILA: ");
    while(p){
        printf("%d ",p->reg);
        p = p->prox;
    }
    printf("\n");
}

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

/**************** EXERCÍCIO ******************/
/*
    Dado um i e um j, crie uma função que retorne o caminho mais rápido de acesso a um vértice j a partir de um vértice i.
*/



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

    buscaLargura(g, 5);
    exibirFlags(g);
    
}