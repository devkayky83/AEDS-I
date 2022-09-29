#include <iostream>
#include <windows.h>
#include <fstream>

// Verificação da existencia de um arquivo criado no sistema.

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    string x;

    cout << "\n Digite o nome do arquivo que deseja procurar: ";
    cin >> x;

    ifstream arquivo1S(x);

    arquivo1S.open(x);

    if (arquivo1S.is_open())
    {
        cout << "\n O arquivo existe!" << endl;
    }   else
        {
            cout << "\n O arquivo não existe" << endl;
        }

    arquivo1S.close();

    cout << endl;
    return 0;
}