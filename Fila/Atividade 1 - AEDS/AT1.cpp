#include <iostream>
#include "AT1.hpp"

using namespace std;


void Menu()
{
    cout << "\n Fila - CALL-CENTER" << endl;
    cout << "\n ---------------------";
    cout << "\n 1. Recebe uma pessoa";
    cout << "\n 2. Imprime Fila";
    cout << "\n 3. Libera uma pessoa do atendimento";
    cout << "\n 0. Sair";
    cout << "\n ---------------------" << endl;
}

void IniciaFila(CallCenter *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

bool VerificaFilaVazia(CallCenter *fila)
{
    return (fila->tamanho == NULL);
}

void Inserir(CallCenter *fila, Informacoes itens)
{
    Apontador alvo;

    alvo = new Elemento;
    alvo->itens = itens;
    alvo->prox = NULL;

    if (VerificaFilaVazia(fila))
    {
        fila->inicio = alvo;
    }else
    {
        fila->fim->prox = alvo;
    }
    fila->fim = alvo;
    fila->tamanho++;
}

void Retirar(CallCenter *fila, Informacoes *itens)
{
    Apontador alvo;

    if (VerificaFilaVazia(fila))
    {
        cout << "\n A fila de atendimentos atualmente já está vazia!";
    }

    alvo = fila->inicio;
    *itens = alvo->itens;
    fila->inicio = alvo->prox;
    delete alvo;
    fila->tamanho--;
}

void ImprimeFila(CallCenter *fila)
{
    Apontador aux;
    int atualiza = 0;

    aux = fila->inicio;

    while (aux != NULL)
    {
        atualiza = atualiza + 1;
        cout << "\n Nº " << atualiza << " - Nome: " << aux->itens.nome << " | Idade: " << aux->itens.idade << " | Telefone: " << aux->itens.telefone;
        aux = aux->prox;
    }
    cout << endl;
}
