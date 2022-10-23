#include <iostream>
#include "AT 2 e 3.hpp"

using namespace std;



void Menu_Eleicao()
{
    cout << "\n FILA DE ELEIÇÃO" << endl;
    cout << "\n ----------------";
    cout << "\n 1. Adicionar uma pessoa";
    cout << "\n 2. Imprimir a fila";
    cout << "\n 3. Liberar uma pessoa";
    cout << "\n 0. Sair";
    cout << "\n ----------------" << endl;
}

bool VerificaVazia(EstruturaFila *fila)
{
    return (fila->tamanho == NULL);
}

void IniciaFila(EstruturaFila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

void Adiciona(EstruturaFila *fila, EstruturaEleitor item)
{
    Apontador alvo;

    alvo = new Elemento;
    alvo->item = item;
    alvo->prox = NULL;

    if (VerificaVazia(fila))
    {
        fila->inicio = alvo;
    }else
    {
        fila->fim->prox = alvo;
    }

    fila->fim = alvo;
    fila->tamanho++;
}

void Prioridade(EstruturaFila *fila, EstruturaEleitor item)
{
    Apontador alvo, aux;
    aux = fila->inicio;

    alvo = new Elemento;
    alvo->item = item;
    alvo->prox = NULL;

    if (VerificaVazia(fila))
    {
        fila->inicio = alvo;
    }
    else
    {
        if (!aux->item.prioridade)
        {
            alvo->prox = aux;
            fila->inicio = alvo; 
        }else
        {
            while(aux->prox != NULL && aux->prox->item.prioridade)
            {
                aux = aux->prox;
            }
            alvo->prox = aux->prox;
            aux->prox = alvo;
        }
    }
    fila->tamanho++;
}

void ImprimeFila(EstruturaFila *fila)
{
    Apontador aux;
    int conta = 0;

    aux = fila->inicio;

    while(aux != NULL)
    {
        conta = conta + 1;
        cout << "\n Eleitor " << conta << ": Nome: " << aux->item.nome 
        << " | Idade: " << aux->item.idade << " | Deficiênte? " << aux->item.deficiencia;
        aux = aux->prox; 
    }
    cout << endl;
}

void Liberar(EstruturaFila *fila, EstruturaEleitor *item)
{
    Apontador alvo;

    if (VerificaVazia(fila))
    {
        cout << "\n A fila está vazia!";
    }

    alvo = fila->inicio;
    *item = alvo->item;
    fila->inicio = alvo->prox;
    delete alvo;
    fila->tamanho--;
}
