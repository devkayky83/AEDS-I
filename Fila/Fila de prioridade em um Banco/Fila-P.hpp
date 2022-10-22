#ifndef FILA-P_H
#define FILA-P_H

typedef struct EstruturaItem
{
    char nome[50];
    int idade;
    bool prioridade = false;
};

typedef struct EstruturaElemento *Apontador;

typedef struct EstruturaElemento
{
    EstruturaItem item;
    Apontador prox;
};

typedef struct EstruturaFila
{
    Apontador inicio, fim;
    int tamanho;
};

void IniciaFila(EstruturaFila *fila);
bool VerificaVazia(EstruturaFila *fila);
void Infileirar(EstruturaFila *fila, EstruturaItem item);
void Prioridade(EstruturaFila *fila, EstruturaItem item);
void Desenfileira(EstruturaFila *fila, EstruturaItem *item);
void Esvazia(EstruturaFila *fila);
void ImprimeFila(EstruturaFila *fila);


#endif