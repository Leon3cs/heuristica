#include <stdlib.h>
#include <malloc.h>

#define MAXNUMVERTICES  100
#define MAXNUMARESTAS   100

typedef long TipoPeso;

typedef int TipoVertice;

typedef struct TipoGrafo {
  TipoPeso Mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
  int NumVertices;
  int NumArestas;
} TipoGrafo;

typedef TipoGrafo* TipoApontador;

void GerarGrafoVazio(TipoGrafo *Grafo)
{
    long i, j;

    for (i = 0; i <= Grafo->NumVertices; i++)
    {
        for (j = 0; j <= Grafo->NumVertices; j++)
        {
            Grafo->Mat[i][j] = 0;
        }
    }
}

void InsereAresta(TipoVertice *V1, TipoVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo)
{
    Grafo->Mat[*V1][*V2] = *Peso;
}

void ImprimeGrafo(TipoGrafo *Grafo)
{
    long i, j;

    printf("   ");

    for (i = 0; i < Grafo->NumVertices; i++)
    {
        printf("%3ld", i);
    }

    putchar('\n');

    for (i = 0; i < Grafo->NumVertices; i++)
    {
        printf("%3ld", i);
        for (j = 0; j < Grafo->NumVertices; j++)
        printf("%3ld", Grafo->Mat[i][j]);
        putchar('\n');
    }
}

void Visita(long Vertice, TipoGrafo *Grafo, long *Passo, long *Visitados)
{
    long j;

    (*Passo)++;
    Visitados[Vertice] = *Passo;
    for (j = 0; j < Grafo->NumVertices; j++)
    {
        if (Grafo->Mat[Vertice][j] > 0)
        {
            if (Visitados[j] == 0)
            { 
                printf(" Visita:%2ld", j);
                Visita(j, Grafo, Passo, Visitados);
            }
        }
    }
    printf("\n Desmarcando vertice:%2ld\n", Vertice);
    *Passo--;  Visitados[Vertice] = 0;
}

void BuscaProfundidade(TipoGrafo *Grafo)
{
    long Passo, i, Visitados[MAXNUMVERTICES + 1];

    Passo = 0;

    for (i = 0; i < Grafo->NumVertices; i++){
        Visitados[i] = 0;
    }

    i = 0;

    printf(" Raiz:%2ld\n", i);
    Visita(i, Grafo, &Passo, Visitados);
}

void CarregarGrafo(TipoGrafo *Grafo)
{
    TipoVertice V0=0, V1=1, V2=2, V3=3, V4=4, V5=5, V6=6;
    TipoPeso Peso1 = 1, Peso2 = 2, Peso4 = 4, Peso6 = 6;

    InsereAresta(&V0, &V5, &Peso2, Grafo);
    InsereAresta(&V0, &V1, &Peso1, Grafo);
    InsereAresta(&V0, &V6, &Peso6, Grafo);
    InsereAresta(&V5, &V0, &Peso2, Grafo);
    InsereAresta(&V5, &V3, &Peso1, Grafo);
    InsereAresta(&V5, &V4, &Peso2, Grafo);
    InsereAresta(&V3, &V5, &Peso1, Grafo);
    InsereAresta(&V3, &V4, &Peso2, Grafo);
    InsereAresta(&V3, &V1, &Peso2, Grafo);
    InsereAresta(&V1, &V0, &Peso1, Grafo);
    InsereAresta(&V1, &V3, &Peso2, Grafo);
    InsereAresta(&V1, &V2, &Peso1, Grafo);
    InsereAresta(&V1, &V4, &Peso4, Grafo);
    InsereAresta(&V2, &V1, &Peso1, Grafo);
    InsereAresta(&V2, &V4, &Peso4, Grafo);
    InsereAresta(&V6, &V0, &Peso6, Grafo);
    InsereAresta(&V6, &V4, &Peso4, Grafo);
    InsereAresta(&V4, &V5, &Peso2, Grafo);
    InsereAresta(&V4, &V3, &Peso2, Grafo);
    InsereAresta(&V4, &V1, &Peso4, Grafo);
    InsereAresta(&V4, &V2, &Peso4, Grafo);
    InsereAresta(&V4, &V6, &Peso1, Grafo);

}

int main(){
    TipoGrafo Grafo;
    Grafo.NumVertices = 7;

    TipoApontador Apontador = &Grafo;

    CarregarGrafo(Apontador);
    printf("=========Grafo========\n");
    ImprimeGrafo(Apontador);
    printf("======================\n");
    printf("~~~~~~Resultados~~~~~~\n");
    BuscaProfundidade(Apontador);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~\n");
}
