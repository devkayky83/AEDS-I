#ifndef P_2
#define P_2

typedef struct Data
{
    int dia;
    int mes;
    int ano;
};

typedef struct Trabalho
{
    int codigo;
    char titulo[30];
    char descricao[50];
    Data data;
};

typedef struct TipoCel *Apontador;

typedef struct TipoCel
{
    Trabalho item;
    Apontador ant;
    Apontador prox;
};

typedef struct EstruLista
{
    Apontador primeiro;
    Apontador ultimo;
    int tamanho = 0;
};


bool listacriada = false;








#endif