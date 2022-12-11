#include <iostream>
#include <windows.h>
#include "ListaTrabalhos.hpp"

using namespace std;


void Menu()
{
    system("cls");
    cout << "\n     TRABALHOS PRÁTICOS      " << endl;
    cout << "\n -----------------------------";
    cout << "\n 1. Incluir Novo Trabalho";
    cout << "\n 2. Remover Trabalho";
    cout << "\n 3. Navegar Trabalho";
    cout << "\n 4. Pesquisar Trabalho";
    cout << "\n 0. Sair";
    cout << "\n -----------------------------" << endl;
}

void IniciarFila(EstruLista *lista)
{
    if (!listacriada)
    {
        lista->primeiro = new TipoCel;
        lista->ultimo = lista->primeiro;
        lista->primeiro->prox = NULL;
        lista->ultimo->ant = NULL;
        lista->tamanho = 0;
        listacriada = true;

        cout << "\n Lista criada com sucesso!";
        Sleep(1500);
    }
    else
    {
        cout << "\n A lista já existe!";
        Sleep(1500);
    }
}

bool VerificaListaVazia(EstruLista *lista)
{
    return lista->primeiro == lista->ultimo;
}

void AdicionaUltimaPosicao(EstruLista *lista, Trabalho *item)
{
    Apontador aux;

    aux = new TipoCel;
    aux->item = *item;
    aux->prox = NULL;
    aux->ant = lista->ultimo;
    lista->ultimo->prox = aux;
    lista->ultimo = aux;
    lista->tamanho++;
}

void RetiraPrimeiraPosicao(EstruLista *lista)
{
    Apontador aux;

    if (VerificaListaVazia(lista))
    {
        cout << "\n A lista está vazia!";
        Sleep(1500);
        return;
    }

    aux = lista->primeiro->prox;

    lista->primeiro->prox = aux->prox;

    if (aux != NULL)
    {
        aux->prox->ant = lista->primeiro;
    }
    else
    {
        lista->ultimo = lista->primeiro;
    }
    delete aux;
    lista->tamanho--;
}

void RetiraUltimaPosicao(EstruLista *lista)
{
    Apontador aux;

    if (VerificaListaVazia(lista))
    {
        cout << "\n A lista está vazia!";
        Sleep(1500);
        return;
    }

    aux = lista->ultimo;
    lista->ultimo = aux->ant;
    aux->prox = NULL;
    delete aux;
    lista->tamanho--;
}

void RetiraPorId(EstruLista *lista, int cod)
{
    Apontador aux;

    aux = lista->primeiro->prox;

    while (aux != NULL && aux->item.codigo != cod)
    {
        aux = aux->prox;
    }

    if (aux != NULL)
    {
        aux->ant->prox = aux->prox;
        if (aux->prox != NULL)
        {
            aux->prox->ant = aux->ant;
        }
        else
        {
            lista->ultimo = aux->ant;
        }
        delete aux;
        lista->tamanho--;
    }
    else
    {
        cout << "\n Trabalho não encontrado!";
        Sleep(1500);
    }
}

void Navegar(EstruLista *lista)
{
    int decisao;

    Apontador aux;

    aux = lista->primeiro->prox;

    cout << "\n Código: " << aux->item.codigo;
    cout << "\n Titulo: " << aux->item.titulo;
    cout << "\n Descrição: " << aux->item.descricao;
    cout << "\n Data: " << aux->item.data.dia << "/" 
    << aux->item.data.mes << "/" << aux->item.data.ano;
    cout << "\n ---------------------" << endl;

    cout << "\n 1. Proximo trabalho" 
    << "\n 2. Trabalho anterior"  
    << "\n 0. Sair" << "\n\n - ";
    cin >> decisao;

while (decisao != 0)
{
    if (decisao == 1)
    {
        aux = aux->prox;

        system("cls");
        cout << "\n Código: " << aux->item.codigo;
        cout << "\n Titulo: " << aux->item.titulo;
        cout << "\n Descrição: " << aux->item.descricao;
        cout << "\n Data: " << aux->item.data.dia << "/" 
        << aux->item.data.mes << "/" << aux->item.data.ano << endl;

            if (aux->prox == NULL)
            {
                cout << "\n Não há proximos trabalhos cadastrados! (Fim da lista)" << endl;
                Sleep(1500);
            }

        cout << "\n 1. Proximo trabalho" 
        << "\n 2. Trabalho anterior"  
        << "\n 0. Sair" << "\n\n - ";
        cin >> decisao;

    }
    else if (decisao == 2)
    {
        aux = aux->ant;

        system("cls");
        cout << "\n Código: " << aux->item.codigo;
        cout << "\n Titulo: " << aux->item.titulo;
        cout << "\n Descrição: " << aux->item.descricao;
        cout << "\n Data: " << aux->item.data.dia << "/" 
        << aux->item.data.mes << "/" << aux->item.data.ano << endl;

            if (aux->ant == lista->primeiro && decisao == 2)
            {
                cout << "\n Não há trabalhos anteriores cadastrados a frente! (Começo da lista)" << endl;
                Sleep(1500);
            }

        cout << "\n 1. Proximo trabalho" 
        << "\n 2. Trabalho anterior"  
        << "\n 0. Sair" << "\n\n - ";
        cin >> decisao;
    }
}
}

int PesquisaTrabalho(EstruLista *lista, int c)
{
    Apontador aux;

    aux = lista->primeiro->prox;

    while(aux != NULL && aux->item.codigo != c)
    {
        aux = aux->prox;
    }
    if (aux != NULL)
    {
        return aux->item.codigo;
    }
    else
    {
        return -1;
    }
}

void ImprimeTrabalho(EstruLista *lista, int c)
{
    Apontador aux;

    aux = lista->primeiro->prox;

    while (aux != NULL && aux->item.codigo != c)
    {
        aux = aux->prox;
    }
    if (aux != NULL)
    {
        cout << "\n Código: " << aux->item.codigo;
        cout << "\n Titulo: " << aux->item.titulo;
        cout << "\n Descrição: " << aux->item.descricao;
        cout << "\n Data: " << aux->item.data.dia << "/" 
        << aux->item.data.mes << "/" << aux->item.data.ano << endl;
        Sleep(1500);
    }
}




