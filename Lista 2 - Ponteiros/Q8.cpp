#include <iostream>
#include <windows.h>

using namespace std;

void preenche(char *vetor[5], char elemento)
{
    
    elemento = 'a';

    *vetor = &elemento;

    vetor++;

    *vetor[1] = 'b';
    
    cout << vetor;
}

void imprime(char *vetor)
{

}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    char *vetor, elemento;

    preenche(&vetor, elemento);

    cout << endl;
    return 0;
}