#include <iostream>
#include "TP2.hpp"

using namespace std;

void Pilha_Menu()
{
  system("cls");
  cout << "\n ----------------------------";
  cout << "\n         LANCHONETE ";
  cout << "\n ----------------------------";
  cout << "\n 1. Inclusão de novo pedido";
  cout << "\n 2. Listar Pedidos";
  cout << "\n 3. Ver Cardápio";
  cout << "\n 4. Imprimir Lista de Entrega";
  cout << "\n 5. Lançar Entrega";
  cout << endl;
}

void Lanchonete_Menu()
{
  system("cls");
  cout << "\n -------------------------------------------------";
  cout << "\n                    CARDAPIO       ";
  cout << "\n -------------------------------------------------";
  cout << "\n LANCHES:";
  cout << "\n ------------";
  cout << "\n 1. Hambúrguer 1 - - - - - - - - - - - R$ 8,00";
  cout << "\n 2. Hambúrguer 2 - - - - - - - - - - - R$ 10,00";
  cout << "\n 3. Pizza - - - - - - - - - - - - - - - R$ 15,00" << endl;
  cout << "\n BEBIDAS:";
  cout << "\n -----------";
  cout << "\n 4. Garrafa de água - - - - - - - - - - R$ 1,00";
  cout << "\n 5. Suco de laranja - - - - - - - - - - R$ 3,00";
  cout << "\n 6. Refrigerante - - - - - - - - - - - R$ 4,00" << endl;
  cout << "\n SOBREMESAS:";
  cout << "\n --------------";
  cout << "\n 7. Pudim - - - - - - - - - - - - - - - R$ 6,00";
  cout << "\n 8. Bolo de chocolate - - - - - - - - - R& 10,00";
  cout << "\n -------------------------------------------------" << endl;
}

bool CriaPilha(PilhaEntrega *entrega)
{
  if (entrega->tamanho == 0)
  {
    return false;
  }
  entrega->tamanho = 0;
  return true;
}

bool VerificaPilhaCheia(PilhaEntrega *entrega)
{
  if (entrega->tamanho == MAXTAM)
  {
    return true;
  }
    return false;
}

bool VerificaPilhaVazia(PilhaEntrega *entrega)
{
  if (entrega->tamanho == 0)
  {
    return true;
  }
    return false;
}

bool Pilha(PilhaEntrega *entrega, Pedido aux)
{
  if (VerificaPilhaCheia(entrega))
  {
    return false;
  }
  entrega->itens[entrega->tamanho] = aux;
  entrega->tamanho++;
  return true;
}

Pedido retira(PilhaEntrega *entrega)
{
  Pedido aux;
  aux = entrega->itens[entrega->tamanho - 1];
  entrega->itens[entrega->tamanho - 1] = entrega->itens[entrega->tamanho];
  entrega->tamanho--;
  return aux;
}

void ImprimeProdutos(Pedido itens, string Produtos[])
{
  cout << "\n Pedido - Nº: " << itens.codigo;
  cout << "\n Distancia: " << itens.distancia << " KM";
  cout << "\n Produtos que foram cadastrados neste pedido: " << endl;

  for (int i = 0; i < itens.tamanho; i++)
  {
    cout << "\n - ";
    cout << Produtos[itens.produtos[i]];
  }
  cout << endl;
  cout << "\n Total: R$ " << itens.valor_total_pedido << ".00";
  cout << "\n ---------------------------" << endl;
}

void FazerPedidos(Pedido *itens, double Precos[])
{
  int escolha;

  itens->tamanho = 0;

  do 
  {
    Lanchonete_Menu();

    cout << "\n Digite o número do respectivo pedido que deseja, (0) para finalizar pedido:" << endl;
    cout << "\n - ";
    cin >> escolha;
    if (escolha != 0)
    {
    cout << "\n Adicionado com sucesso!" << endl;
    Sleep(1000);
    }

    if (escolha != 0)
    {
      itens->produtos[itens->tamanho] = escolha;
      itens->valor_total_pedido += Precos[escolha];
      itens->tamanho++;
    }
    else if (escolha >= PRODUTOSMAX || escolha < 0)
    {
      cout << "\n Não existe este produto na lanchonete!";
    }
  }while(escolha != 0 && itens->tamanho < MAXTAM); 
}

void Pedidos(PilhaEntrega *entrega, int *id, double Precos[])
{
  Pedido itens;

  itens.codigo = *id;
  itens.valor_total_pedido = 0;

  FazerPedidos(&itens, Precos);

  system("cls");
  Lanchonete_Menu();
  cout << "\n Digite a distancia: ";
  cin >> itens.distancia;

  Pilha(entrega, itens);
  *id += 1;

  cout << "\n Pedido feito com sucesso!" << endl;
  system("pause");
}

void ListarPedidos(PilhaEntrega entrega, string Produtos[])
{
  Pedido itens;

  while (entrega.tamanho != 0)
  {
    system("cls");
    itens = retira(&entrega);
    ImprimeProdutos(itens, Produtos);
  }
  if (entrega.tamanho == 0)
  {
    cout << "\n Nenhum pedido á mais foi cadastrado!" << endl;
    system("pause");
  }
}

int VerCardapio(PilhaEntrega *entrega, int *id, double Precos[])
{
  system("cls");
  int decisao;
  
  Lanchonete_Menu();

  cout << "\n Deseja fazer um pedido? (1) para sim, (2) para não: ";
  cin >> decisao;

  if (decisao == 1)
  {
    Pedidos(entrega, id, Precos);
  }
  else
  {
    return - 1;
  }
}

void OrganizaEntrega(PilhaEntrega *entrega)
{
    int tamPilha, TamDistancia, IDdistancia;

    PilhaEntrega alvo, alvo2;

    CriaPilha(&alvo);
    CriaPilha(&alvo2);

    Pedido itens;

    tamPilha = entrega->tamanho;

    while(entrega->tamanho != 0) 
    {
        Pilha(&alvo, retira(entrega));
    }

    for(int i = 0; i < tamPilha; i++) 
    {
        TamDistancia = - 1;
        IDdistancia = 0;

        
        while(alvo.tamanho != 0) 
        {
            itens = retira(&alvo);
            Pilha(&alvo2, itens);
            if(TamDistancia < itens.distancia) {
                TamDistancia = itens.distancia;
                IDdistancia = itens.codigo;
            }
        }

        
        while(alvo2.tamanho != 0) 
        {
            itens = retira(&alvo2);
            if(itens.codigo == IDdistancia) {
                Pilha(entrega, itens);
            } else {
                Pilha(&alvo, itens);
            }
        }
    }

    if (VerificaPilhaVazia(entrega)) 
    {
        cout << "\n Não há pedidos cadastrados!" << endl;
        system("pause");
        return;
    }
        cout << "\n Pilha de Entrega organizada!" << endl;
        system("pause");
}

void EntregaPedido(PilhaEntrega *entrega, string Produtos[])
{
  system("cls");
  Pedido itens;

  itens = retira(entrega);

  cout << "\n O seguinte pedido foi entregue com sucesso!" << endl;

  ImprimeProdutos(itens, Produtos);

  if (VerificaPilhaVazia(entrega))
  {
    cout << "\n Não há mais pedidos cadastrados!" << endl;
    system("pause");
    return;
  }
}









