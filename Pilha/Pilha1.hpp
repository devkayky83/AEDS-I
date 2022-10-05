#ifndef ATVIDADE1
#define ATIVIDADE1


typedef struct TipoItem
{
    int id;
    char nome[50];
};

typedef struct TipoElemento *Apontador;

typedef struct TipoElemento
{
    TipoItem item;
    Apontador prox;
};

typedef struct TipoPilha
{
    Apontador topo;
    int tamanho;
};







#endif