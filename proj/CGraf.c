#include "CGraf.h"
#include <stdlib.h>
#include <stdio.h>

TipoGrafo geraGrafoVazio() {
    TipoGrafo grafo;

    for(int i = 0; i<TOTAL_VERTICES; i++){
        for(int j = 0; j<TOTAL_VERTICES; j++){
            grafo.Mat[i][j] = 0;
        }
    }

    return grafo;
}

void imprimeGrafo(TipoGrafo grafo) {
    for(int i = 0; i<TOTAL_VERTICES; i++){
        for(int j = 0; j<TOTAL_VERTICES; j++){
            printf("%d\t", grafo.Mat[i][j]);
        }
        printf("\n");
    }
}

TipoGrafo conectarVertices(TipoVertice V1, TipoVertice V2, TipoPeso peso, TipoGrafo grafo){
    grafo.Mat[V1][V2] = peso;
    return grafo;
}

int existeAresta(TipoGrafo grafo, TipoVertice V1, TipoVertice V2){
    if(grafo.Mat[V1][V2] != 0){
        return 1;
    }else{
        return -1;
    }
}
