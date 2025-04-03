#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define v 5

bool inicializarMatriz(int m[(v+1)][(v+1)]){
    // verificando se matriz existe
    if(m == NULL)
        return false;
    
    int i, j;
    for(i = 1; i<=v; i++){
        for(j = 1; j<=v; j++){
            m[i][j] = 0; // inicializando a matriz com 0
        }
    }
    return true;
}

bool exibirMatriz(int m[(v+1)][(v+1)]){
    // verificando se matriz existe
    if(m == NULL)
        return false;
    
    int i, j;
    for(i = 1; i<=v; i++){
        printf("V%d ", i);
        for(j = 1; j<=v; j++){
            printf("%d ", m[i][j]); // inicializando a matriz com 0
        }
        printf("\n");
    }
    return true;
}

bool inserirAresta_M(int m[(v+1)][(v+1)], int i, int j){
    // verificando se matriz existe
    if(m == NULL)
        return false;
    
    m[i][j] = 1;
    return true;
}