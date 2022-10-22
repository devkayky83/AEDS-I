#include <iostream>
#include "Fila-P.hpp"

using namespace std;

void Menu_Fila()
{
    cout << "\n Fila de Prioridade - BANCO" << endl;
    cout << "\n ---------------------------";
    cout << "\n 1. Adicionar uma pessoa";
    cout << "\n 2. Imprime a fila";
    cout << "\n 3. Liberar uma pessoa";
    cout << "\n 4. Liberar todas as pessoas da fila";
    cout << "\n 0. Sair";
    cout << "\n ---------------------------" << endl;
}

void IniciaFila(EstruturaFila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

bool VerificaVazia(EstruturaFila *fila)
{
    return (fila->inicio == NULL);
}

void Infileirar(EstruturaFila *fila, EstruturaItem item)
{
    Apontador alvo;

    alvo = new EstruturaElemento;
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

void Prioridade(EstruturaFila *fila, EstruturaItem item)
{
    Apontador alvo, aux;

    alvo = new EstruturaElemento;
    alvo->item = item;
    alvo->prox = NULL;

    aux = fila->inicio;

    if (VerificaVazia(fila))
    {
        fila->inicio = alvo;
    }
    else
    {
        if (!aux->item.prioridade) // Se prioridade for false.
        {
            alvo->prox = aux;
            fila->inicio = alvo; // Recebe a prioridade.
        }else
        {
            while (aux->prox != NULL && aux->prox->item.prioridade)
            {
                aux = aux->prox;
            }
            alvo->prox = aux->prox;
            aux->prox = alvo;
        }
    }
    fila->tamanho++;
}

void Desenfileira(EstruturaFila *fila, EstruturaItem *item)
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

void Esvazia(EstruturaFila *fila)
{
    EstruturaItem item;

    while (!VerificaVazia(fila))
    {
        Desenfileira(fila, &item);
    }
}

void ImprimeFila(EstruturaFila *fila)
{
    Apontador aux;

    if (VerificaVazia(fila))
    {
        cout << "\n A fila está vazia!" << endl;
        return;
    }

    aux = fila->inicio;

    while (aux != NULL)
    {
        cout  << "\n Cliente: " << aux->item.nome << " | Idade: " << aux->item.idade;
        aux = aux->prox;
    }
    cout << endl;
    cout << "\n Total de pessoas na fila atualmente: " << fila->tamanho << endl;
    cout << endl;
}



