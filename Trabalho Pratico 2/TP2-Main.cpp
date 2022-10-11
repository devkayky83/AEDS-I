#include <iostream>
#include <windows.h>
#include "TP2.hpp"
#include "TP2.cpp"
 
using namespace std;

double Precos[PRODUTOSMAX] = {8.00, 10.00, 15.00, 1.00, 3.00, 4.00, 6.00, 10.00};
 
string Produtos[PRODUTOSMAX] = {"Hambúrguer 1", "Hambúrguer 2", "Pizza", "Garrafa de água", "Suco de laranja", "Refrigerante", "Pudim", "Bolo de chocolate"};

int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  int opcao_menu, id = 1;

  PilhaEntrega Principal;

  CriaPilha(&Principal);

  do
  {
    Pilha_Menu();
    cout << "\n Digite o número da opção que deseja acessar: ";
    cin >> opcao_menu;

  switch (opcao_menu)
  {
    case 1:
      Pedidos(&Principal, &id, Precos);
    break;

    case 2:
      ListarPedidos(Principal, Produtos);
    break;

    case 3:
      VerCardapio(&Principal, &id, Precos);
    break;

    case 4:
      OrganizaEntrega(&Principal);
    break;

    case 5:
      EntregaPedido(&Principal, Produtos);
    break;
  }
  }while(opcao_menu != 0);

  cout << endl;
  return 0;
}