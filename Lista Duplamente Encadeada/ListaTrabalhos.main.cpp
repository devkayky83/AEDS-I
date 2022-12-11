#include <iostream>
#include <windows.h>
#include "ListaTrabalhos.cpp"
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int opcao, cod, ret, opcao2;
 
  EstruLista Lista; 
  Trabalho itens;

  IniciarFila(&Lista);

  do 
  {
    Menu();
    cout << "\n Digite oque deseja acessar: ";
    cin >> opcao;

    switch (opcao)
    {
        case 1:
            system("cls");
            
            cout << "\n Digite o código: ";
            cin >> itens.codigo;
            cout << "\n Digite o titulo: ";
            cin.ignore();
            cin.getline(itens.titulo, 30);
            cout << "\n Digite a descrição: ";
            cin.getline(itens.descricao, 50);
            cout << "\n Digite o dia: ";
            cin >> itens.data.dia;
            cout << "\n Digite o mês: ";
            cin >> itens.data.mes;
            cout << "\n Digite o ano: ";
            cin >> itens.data.ano;
            cout << " ---------------------" << endl;

            AdicionaUltimaPosicao(&Lista, &itens);
            cout << "\n Projeto adicionado com sucesso!";
            Sleep(1500);
        break;

        case 2:
            cout << "\n 1. Remover Primeiro";
            cout << "\n 2. Remover Ultimo";
            cout << "\n 3. Remover por código";
            cout << "\n ----------------------" << endl;
            cout << "\n Digite oque deseja fazer: ";
            cin >> opcao2;

            if (opcao2 == 1)
            {
                RetiraPrimeiraPosicao(&Lista);

                cout << "\n Removido com sucesso!";
                Sleep(1500);
            }
            else if (opcao2 == 2)
            {
                RetiraUltimaPosicao(&Lista);

                cout << "\n Removido com sucesso!";
                Sleep(1500);
            }
            else if (opcao2 == 3)
            {
                system("cls");
                cout << "\n Digite o código que deseja procurar: ";
                cin >> cod;

                ret = PesquisaTrabalho(&Lista, cod);

                if (ret == -1)
                {
                   cout << "\n Trabalho não encontrado: ";
                   Sleep(1500);
                } 
                else
                {
                cout << "\n Removendo trabalho...";
                RetiraPorId(&Lista, cod);

                cout << "\n Removido com sucesso!";
                Sleep(1500);
                }
            }
        break;

        case 3:
            system("cls");
            Navegar(&Lista);
        break;

        case 4:
            system("cls");
            cout << "\n Digite o código do trabalho: ";
            cin >> cod;
            ret = PesquisaTrabalho(&Lista, cod);

            if (ret == -1)
            {
                cout << "\n Trabalho não encontrado!";
                Sleep(1500);
                break;
            }
            ImprimeTrabalho(&Lista, ret);
            system("pause");
        break;
    }
  }while(opcao != 0);
  
 
  cout << endl;
  return 0;
}