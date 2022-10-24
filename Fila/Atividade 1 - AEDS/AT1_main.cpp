#include <iostream>
#include <windows.h>
#include "AT1.cpp"
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  int opcao;

  CallCenter fila;
  Informacoes itens;
 
  IniciaFila(&fila);

  do
  {
    system("cls");
    Menu();
    cout << "\n Digite oq deseja acessar: ";
    cin >> opcao;

    switch(opcao)
    {
        case 1:
            system("cls");
            cout << "\n Digite o seu nome: ";
            cin.ignore();
            cin.getline(itens.nome, 50);

            cout << "\n Digite a sua idade: ";
            cin >> itens.idade;

            cout << "\n Digite o seu número de telefone: ";
            cin >> itens.telefone;

            Inserir(&fila, itens);

            cout << "\n Voçê será atendido em breve!" << endl;
            system("pause");
        break;

        case 2:
            
            if (VerificaFilaVazia(&fila))
            {
                cout << "\n A fila de atendimento está vazia!" << endl;
                system("pause");
                break;
            }

            system("cls");
            cout << "\n FILA DE ATENDIMENTO ";
            cout << "\n --------------------" << endl;

            cout << "\n Clientes em espera para atendimento: " << endl;

            ImprimeFila(&fila);
            system("pause");
        break;

        case 3:
            if (VerificaFilaVazia(&fila))
            {
                cout << "\n A fila de atendimento está atualmente vazia!" << endl;
                system("pause");
                break;
            }
            system("cls");
            Retirar(&fila, &itens);
            cout << "\n Atendendo o seguinte cliente: " << itens.nome << endl;
            Sleep(2000);
            cout << "\n Cliente atendido com sucesso!" << endl;
            system("pause");
        break;
    }

  }while(opcao != 0);
 
  cout << endl;
  return 0;
}