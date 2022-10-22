#include <iostream>
#include <windows.h>
#include "Fila-P.cpp"
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

    int opcao;
 
    EstruturaFila fila;
    EstruturaItem item;

    IniciaFila(&fila);

    do
    {
        system("cls");
        Menu_Fila();
        cout << "\n Digite a opção que deseja acessar: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            system("cls");

            cout << "\n Atenção! Pessoas com mais de 60 anos ou igual serão priorizadas!";
            cout << "\n Desde já agradecemos pelo entendimento!";
            cout << "\n -----------------------------------------------------------------" << endl;

            cout << "\n Digite o nome do cliente: ";
            cin.ignore();
            cin.getline(item.nome, 50);
            
            cout << "\n Digite a idade do cliente: ";
            cin >> item.idade;

            if (item.idade >= 60)
            {
                item.prioridade = true;
                Prioridade(&fila, item);
            }else if (item.idade < 60)
            {
                Infileirar(&fila, item);
            }
            cout << "\n Adicionado a fila com sucesso!" << endl;
            system("pause");
        break;

        case 2:
            system("cls");
            cout << "\n Situação atual da fila do banco: " << endl;
            ImprimeFila(&fila);
            system("pause");
        break;

        case 3:
             if (VerificaVazia(&fila))
            {
            cout << "\n A fila está vazia atualmente!" << endl;
            system("pause");
            }else
            {
            system("cls");
            Desenfileira(&fila, &item);
            cout << "\n Cliente liberado da fila: " << item.nome << endl;
            system("pause");
            }
        break;

        case 4:

            if (fila.tamanho == 0)
            {
                cout << "\n A fila do banco está atualmente vazia!" << endl;
                system("pause");
            }
                else
                {
                    system("cls");
                    Esvazia(&fila);
                    cout << "\n Liberando todas as pessoas da fila..." << endl;
                    Sleep(2000);
                    cout << "\n Fila esvaziada com sucesso!" << endl;
                    system("pause");
                }
            break;
        
        }

    }while(opcao != 0);



 
 
  cout << endl;
  return 0;
}