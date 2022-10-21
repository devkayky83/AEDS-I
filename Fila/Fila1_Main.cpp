#include <iostream>
#include <windows.h>
#include "Fila1.cpp"
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

    int numero;

    TipoFila fila;
    TipoItem item;

    
    IniciaFila(&fila);

    do
    {
      system("cls");
    Menu();
    cout << "\n Digite a opção que deseja acessar: ";
    cin >> numero;

    switch(numero)
    {
      case 1:
        system("cls");
          cout << "\n Digite um número: ";
          cin >> item.valor;
          Infileira(&fila, item);
      break;

      case 2:
        system("cls");
        ImprimeFila(&fila);
        system("pause");
      break;

      case 3:
        system("cls");
        Desinfileira(&fila, &item);
        cout << "\n Desinfileirou: " << item.valor << endl;
        system("pause");
      break;

      case 4:

        if (fila.tamanho == 0)
        {
           cout << "\n Não há elementos na fila!" << endl;
           system("pause");
           break;
        }else
        {
        system("cls");
        EsvaziarFila(&fila);
        cout << "\n Esvaziando a fila..." << endl;
        Sleep(2000);
        cout << "\n Fila esvaziada com sucesso!";
        system("pause");
        }
      break;
    }

    }while(numero != 0);

  cout << endl;
  return 0;
}