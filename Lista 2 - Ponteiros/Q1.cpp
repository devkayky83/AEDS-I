#include <iostream>
#include <windows.h>

// Imprimindo conteudo de variáveis com manipulação com ponteiros

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int a = 30, *x;
    float b = 105.6, *y;
    char c = 'f', *z;

    cout << "\n Conteudo de a: " << a;
    cout << "\n Conteudo de b: " << b;
    cout << "\n Conteudo de c: " << c << endl;

    x = &a;
    y = &b;
    z = &c;



    *x = 15; 
    *y = 59.9;
    *z = 't';

    cout << endl;
    cout << "\n Conteudo após manipulação: " << *x;
    cout << "\n Conteudo após manipulação: " << *y;
    cout << "\n Conteudo após manipulação: " << *z << endl;

    return 0;
}