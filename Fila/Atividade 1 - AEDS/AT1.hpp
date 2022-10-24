#ifndef AT1_H
#define AT1_H

typedef struct Informacoes
{
    char nome[50];
    int idade;
    char telefone[9];
};

typedef struct Elemento *Apontador;

typedef struct Elemento
{
    Informacoes itens;
    Apontador prox;
};

typedef struct CallCenter
{
    Apontador inicio, fim;
    int tamanho;
};

void IniciaFila(CallCenter *fila);
bool VerificaFilaVazia(CallCenter *fila);
void Inserir(CallCenter *fila, Informacoes itens);
void Retirar(CallCenter *fila, Informacoes *itens);
void ImprimeFila(CallCenter *fila);


#endif