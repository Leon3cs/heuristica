#include <stdlib.h>
#include <malloc.h>

#define MAXNUMVERTICES  100
#define MAXNUMARESTAS   100

typedef long TipoPeso;

typedef int TipoVertice;

typedef int TipoChave;

typedef struct TipoGrafo {
  TipoPeso Mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
  int NumVertices;
  int NumArestas;
} TipoGrafo;

int INFINITO = __INT_MAX__;

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
    TipoVertice V0=0, V1=1, V2=2, V3=3, V4=4, V5=5;
    TipoPeso Peso3 = 3, Peso4 = 4, Peso5 = 5, Peso7 = 7, Peso8 = 8, Peso9 = 9,
            Peso10 = 10, Peso11 = 11, Peso12 = 12, Peso15 = 15, Peso18 = 18,
            Peso20 = 20, Peso25 = 25, Peso26 = 26;

    InsereAresta(&V0, &V1, &Peso3, Grafo);
    InsereAresta(&V0, &V2, &Peso10, Grafo);
    InsereAresta(&V0, &V3, &Peso11, Grafo);
    InsereAresta(&V0, &V4, &Peso7, Grafo);
    InsereAresta(&V0, &V5, &Peso25, Grafo);

    InsereAresta(&V1, &V0, &Peso3, Grafo);
    InsereAresta(&V1, &V2, &Peso8, Grafo);
    InsereAresta(&V1, &V3, &Peso12, Grafo);
    InsereAresta(&V1, &V4, &Peso9, Grafo);
    InsereAresta(&V1, &V5, &Peso26, Grafo);

    InsereAresta(&V2, &V0, &Peso10, Grafo);
    InsereAresta(&V2, &V1, &Peso8, Grafo);
    InsereAresta(&V2, &V3, &Peso9, Grafo);
    InsereAresta(&V2, &V4, &Peso4, Grafo);
    InsereAresta(&V2, &V5, &Peso20, Grafo);

    InsereAresta(&V3, &V0, &Peso11, Grafo);
    InsereAresta(&V3, &V1, &Peso12, Grafo);
    InsereAresta(&V3, &V2, &Peso9, Grafo);
    InsereAresta(&V3, &V4, &Peso5, Grafo);
    InsereAresta(&V3, &V5, &Peso15, Grafo);

    InsereAresta(&V4, &V0, &Peso7, Grafo);
    InsereAresta(&V4, &V1, &Peso9, Grafo);
    InsereAresta(&V4, &V2, &Peso4, Grafo);
    InsereAresta(&V4, &V3, &Peso5, Grafo);
    InsereAresta(&V4, &V5, &Peso18, Grafo);

    InsereAresta(&V5, &V0, &Peso25, Grafo);
    InsereAresta(&V5, &V1, &Peso26, Grafo);
    InsereAresta(&V5, &V2, &Peso20, Grafo);
    InsereAresta(&V5, &V3, &Peso15, Grafo);
    InsereAresta(&V5, &V4, &Peso18, Grafo);
}

void ImprimirMatriz(int NumVertices, TipoPeso Matriz[NumVertices][NumVertices])
{
    for (int i = 0; i < NumVertices; i++)
    {
        printf("\n");
        for (int j = 0; j < NumVertices; j++)
        {
            printf("%3ld\t", Matriz[i][j]);
        }
    }
}

void ImprimirCaminho(int NumVertices, int Caminho[NumVertices])
{
    for (int i = 0; i < NumVertices; i++)
    {
        if(i < NumVertices-1)
        {
            printf("%d -> ", Caminho[i]);
        }
        else
        {
            printf("%d -> %d", Caminho[i], Caminho[i-(NumVertices-1)]);
        }
        
    }
}

void GerarAGM(int NumVertices, int Caminho[NumVertices], TipoPeso Matriz[NumVertices][NumVertices], TipoGrafo* AGM)
{
    AGM->NumVertices = NumVertices;

    GerarGrafoVazio(AGM);

    for(int i=0; i<NumVertices; i++){
        if(i < NumVertices-1)
        {
            TipoVertice VA = Caminho[i];
            TipoVertice VB = Caminho[i+1];
            TipoPeso Peso = Matriz[Caminho[i]][Caminho[i+1]];

            InsereAresta(&VA, &VB, &Peso, AGM); 
        }
        else
        {
            TipoVertice VA = Caminho[i];
            TipoVertice VB = Caminho[i-(NumVertices-1)];
            TipoPeso Peso = Matriz[Caminho[i]][Caminho[i-(NumVertices-1)]];

            InsereAresta(&VA, &VB, &Peso, AGM);
        }
    }

    printf("AGM Gerada: ");
    putchar('\n');
    ImprimeGrafo(AGM);
}


void CopiarMatrizGrafo(TipoGrafo* Grafo, int NumVertices, TipoPeso Matriz[NumVertices][NumVertices])
{
    for (int i = 0; i < NumVertices; i++)
    {
        
        for (int j = 0; j < NumVertices; j++)
        {
            if(Grafo->Mat[i][j] != 0)
            {
                Matriz[i][j] = Grafo->Mat[i][j];
            }
            else if(i == j)
            {
                Matriz[i][j] = 0;
            }
            else
            {
                Matriz[i][j] = 4294967295;
            }
            
        }
    }
}

TipoPeso CalculaCustoCaminho(int NumVertices, int Caminho[NumVertices], TipoPeso Matriz[NumVertices][NumVertices])
{
    TipoPeso CustoCaminho = 0;

    for(int i = 0; i<NumVertices; i++){
        if(i < NumVertices-1)
        {
            CustoCaminho += Matriz[Caminho[i]][Caminho[i+1]];
        }
        else
        {
            CustoCaminho += Matriz[Caminho[i]][Caminho[i-(NumVertices-1)]];
        }
    }

    return CustoCaminho;
}

void ImprimeArestas(int NumVertices, int Caminho[NumVertices], TipoPeso Matriz[NumVertices][NumVertices])
{
    for(int i=0; i<NumVertices; i++){
        if(i<NumVertices-1)
        {
            printf("%d -> %d: %3ld", Caminho[i], Caminho[i+1], Matriz[Caminho[i]][Caminho[i+1]]);
            putchar('\n');
        }
        else
        {
            printf("%d -> %d: %3ld", Caminho[i], Caminho[i-(NumVertices-1)], Matriz[Caminho[i]][Caminho[i-(NumVertices-1)]]);
            putchar('\n');
        }
        
    }
}

void Dijkstra(TipoGrafo *Grafo)
{
    TipoGrafo AGM;
    int NumVertices = Grafo->NumVertices;
    TipoPeso Matriz[NumVertices][NumVertices];

    CopiarMatrizGrafo(Grafo, NumVertices, Matriz);

    putchar('\n');
    printf("Matriz obtida: ");
    putchar('\n');
    ImprimirMatriz(NumVertices, Matriz);
    putchar('\n');

    int Visitados[NumVertices];
    int Caminho[NumVertices];
    TipoPeso CustoCaminho = 0;

    for (int i = 0; i < NumVertices; i++)
    {
        Visitados[i] = -1;
        Caminho[i] = 0;
    }

    for (int i = 0; i < NumVertices; i++)
    {
        int min = -1;
        TipoPeso MinValor = INFINITO;

        for (int j = 0; j < NumVertices; j++)
        {
            if( Visitados[j] != 1 && Matriz[0][j] < MinValor)
            {
                min = j;
                MinValor = Matriz[0][j];
            }
        }
        
        Visitados[min] = 1;
        Caminho[i] = min;

        for (int j = 0; j < NumVertices; j++)
        {
            if((Matriz[0][min] + Matriz[j][min]) < Matriz[0][j])
            {
                Matriz[0][j] = Matriz[0][min] + Matriz[j][min];
            }
        }
        
    }

    printf("Caminho a ser percorrido: ");
    ImprimirCaminho(NumVertices, Caminho);
    putchar('\n');
    CustoCaminho = CalculaCustoCaminho(NumVertices, Caminho, Matriz);
    printf("Custo total do caminho: %3ld", CustoCaminho);
    putchar('\n');
    printf("Arestas da AGM:");
    putchar('\n');
    ImprimeArestas(NumVertices, Caminho, Matriz);
    putchar('\n');
    GerarAGM(NumVertices, Caminho, Matriz, &AGM);
    putchar('\n');
    printf("Percorrendo AGM: ");
    putchar('\n');
    BuscaProfundidade(&AGM);
}

int main(){
    TipoGrafo Grafo;
    Grafo.NumVertices = 6;

    TipoApontador Apontador = &Grafo;

    CarregarGrafo(Apontador);
    printf("=========Grafo========\n");
    ImprimeGrafo(Apontador);
    printf("======================\n");
    printf("~~~~~~Resultados~~~~~~\n");
    Dijkstra(Apontador);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~\n");
}