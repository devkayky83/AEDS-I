#include <iostream>
#include <windows.h>
#include "AT 2 e 3.cpp"
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  int opcao;

  EstruturaFila fila;
  EstruturaEleitor item;
  
  IniciaFila(&fila);

  do
  {
    system("cls");
    Menu_Eleicao();
    cout << "\n Digite oque deseja acessar: ";
    cin >> opcao;

    switch(opcao)
    {
        case 1:
            system("cls");
            cout << "\n BEM VINDO A ZONA ELEITORAL!";
            cout << "\n ----------------------------" << endl;
            cout << "\n Digite o seu nome: ";
            cin.ignore();
            cin.getline(item.nome, 50);

            cout << "\n Digite a sua idade: ";
            cin >> item.idade;

            cout << "\n É portador de deficiência? (1) para sim, (2) para não: ";
            cin >> item.deficiencia;

            if (item.idade >= 60 || item.deficiencia == 1)
            {
                item.prioridade = true;
                Prioridade(&fila, item);
            }else if (item.idade < 60)
            {
                Adiciona(&fila, item);
            }
            cout << "\n Coletá de informações finalizada!" << endl;
            system("pause");
        break;

        case 2:
            system("cls");
            cout << "\n Situação atual da fila de eleição:";
            cout << "\n ----------------------------------" << endl;
            cout << "\n Informações: 1 = Sim, 2 = Não" << endl;
            ImprimeFila(&fila);
            system("pause");
        break;

        case 3:
            if (VerificaVazia(&fila))
            {
                cout << "\n A fila de eleição está atualmente vazia!" << endl;
                system("pause");
                break;
            }
            system("cls");
            Liberar(&fila, &item);
            cout << "\n O seguinte eleitor está votando: " << item.nome << endl;
            Sleep(2000);
            cout << "\n Voto confirmado com sucesso!" << endl;
            system("pause");
        break;
    }

  }while(opcao != 0);
 
  cout << endl;
  return 0;
}