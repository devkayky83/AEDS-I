#include <iostream>
#include "Pilha1.hpp"

using namespace std;


void InicalizaPilha(TipoPilha *pilha)
{
    pilha->topo = NULL;
    pilha->tamanho = 0; 
}

bool verificaPilhaVazia(TipoPilha pilha)
{
    if (pilha.tamanho == 0 || pilha.topo == NULL)
    {
        return true;
    }
    else{
        return false;
    }
} 

void empilha(TipoPilha *pilha, TipoItem itens)
{
    if (verificaPilhaVazia)
    {
        cout << "\n A pilha está vazia!";
    }
    else{
        Apontador alvo = new TipoElemento;
        alvo->item = itens;
        alvo->prox = pilha->topo;
        pilha->topo = alvo;
        pilha->tamanho++;
    }
}

void desempilha(TipoPilha *pilha, TipoItem *itens)
{
    Apontador alvo;

    alvo = pilha->topo;
    pilha->topo = alvo->prox;
    delete alvo;
    pilha->tamanho--;
}

void ImprimePiha(TipoPilha *pilha)
{
    Apontador alvo;

    if (verificaPilhaVazia)
    {
        cout << "\n A pilha está vazia!";
    }

    alvo = pilha->topo;

    while (alvo != NULL)
    {
        cout << alvo->item.id << " , " << alvo->item.nome;
        alvo = alvo->prox;
    }

}

int getTamanho(TipoPilha *pilha)
{
    return pilha->tamanho;
}



