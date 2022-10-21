#include <iostream>
#include "Fila1.hpp"
 
using namespace std;


void Menu()
{
    cout << "\n Fila" << endl;
    cout << "\n ---------------";
    cout << "\n 1. Infileirar";
    cout << "\n 2. Imprime";
    cout << "\n 3. Desinfileirar";
    cout << "\n 4. Esvazia Fila";
    cout << "\n 0. Sair";
    cout << "\n ---------------" << endl;
}

void IniciaFila(TipoFila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

bool VerificaFilaVazia(TipoFila *fila)
{
    return (fila->inicio == NULL);
}

void Infileira(TipoFila *fila, TipoItem item)
{
    Apontador alvo;

    alvo = new TipoElemento;
    alvo->item = item;
    alvo->prox = NULL;

    if (VerificaFilaVazia(fila))
    {
        fila->inicio = alvo; // Caso a fila esteja vazia, a primeira posição receberá esse novo item.
    }
    else
    {
        fila->fim->prox = alvo; // Caso o contrario, o item sera colocado na frente do ultimo item.
    }

    fila->fim = alvo;
    fila->tamanho++;
}

void Desinfileira(TipoFila *fila, TipoItem *item)
{
    Apontador alvo;

    if (VerificaFilaVazia(fila))
    {
        cout << "\n A fila está vazia!";
    }

    alvo = fila->inicio;
    *item = alvo->item; 
    fila->inicio = alvo->prox;
    delete alvo;
    fila->tamanho--;
}

void EsvaziarFila(TipoFila *fila)
{
    TipoItem item;

    while (!VerificaFilaVazia(fila))
    {
        Desinfileira(fila, &item);
    }
}

void ImprimeFila(TipoFila *fila)
{
    Apontador alvo;

    if (VerificaFilaVazia(fila))
    {
        cout << "\n A fila está vazia!";
        return;
    }
    
        alvo = fila->inicio;

        while (alvo != NULL)
        {
            cout << "\n Número: " << alvo->item.valor << " ";
            alvo = alvo->prox;
        }
    cout << endl;
}




