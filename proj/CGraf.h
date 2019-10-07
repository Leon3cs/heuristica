#ifndef CGRAF_H_INCLUDED
#define CGRAF_H_INCLUDED

#define TOTAL_VERTICES 7

typedef int TipoVertice;
typedef int TipoPeso;
typedef struct TipoGrafo {
    int Mat[TOTAL_VERTICES][TOTAL_VERTICES];
}TipoGrafo;

TipoGrafo geraGrafoVazio(); //Cria um TipoGrafo vazio
void imprimeGrafo(TipoGrafo grafo);
TipoGrafo conectarVertices(TipoVertice V1, TipoVertice V2, TipoPeso peso, TipoGrafo grafo);
int existeAresta(TipoGrafo grafo, TipoVertice V1, TipoVertice V2);

#endif // CGRAF_H_INCLUDED
