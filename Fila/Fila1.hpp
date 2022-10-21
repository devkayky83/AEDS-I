#ifndef FILA1_H
#define FILA1_H

typedef struct TipoItem
{
    int valor;
};

typedef struct TipoElemento *Apontador;

typedef struct TipoElemento
{
    TipoItem item;
    Apontador prox;
};

typedef struct TipoFila
{
    Apontador inicio, fim;
    int tamanho;
};


void IniciaFila(TipoFila *fila);
bool VerificaFilaVazia(TipoFila *fila);
void Infileira(TipoFila *fila, TipoItem item);
void EsvaziarFila(TipoFila *fila);
void ImprimeFila(TipoFila *fila);




#endif