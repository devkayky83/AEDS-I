#include <iostream>
#include <windows.h>
#include <time.h>
#include <fstream>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));

    int ordem = 0;
    int matriz[2][2];

    ofstream arquivoM;
    arquivoM.open("Q4.xls");

    cout << "\n Digite o tamanho da matriz: ";
    cin >> ordem;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "\n Digite para preencher a matriz: ";
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matriz[i][j] = rand();
            arquivoM << matriz[i][j] << " " << endl;
        }
    }

    arquivoM.close();

    return 0;
}
