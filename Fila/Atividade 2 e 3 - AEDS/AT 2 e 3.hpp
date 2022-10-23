#ifndef AT3_H
#define AT3_H

typedef struct EstruturaEleitor
{
    char nome[50];
    int idade;
    int deficiencia;
    bool prioridade = false;
};

typedef struct Elemento *Apontador;

typedef struct Elemento
{
    EstruturaEleitor item;
    Apontador prox;
};

typedef struct EstruturaFila
{
    Apontador inicio, fim;
    int tamanho;
};

bool VerificaVazia(EstruturaFila *fila);
void IniciaFila(EstruturaFila *fila);
void Adiciona(EstruturaFila *fila, EstruturaEleitor item);
void Prioridade(EstruturaFila *fila, EstruturaEleitor item);
void ImprimeFila(EstruturaFila *fila);
void Liberar(EstruturaFila *fila, EstruturaEleitor *item);


#endif