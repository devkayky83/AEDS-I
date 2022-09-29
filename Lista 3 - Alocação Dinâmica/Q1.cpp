#include <iostream>
#include <windows.h>
 
using namespace std;

void Aloc(int numero, char elemento)
{
    char *vetor;
    cout << "\n De quantos elementos será o vetor: ";
    cin >> numero;

    vetor = new char [numero];

    for (int i = 0; i < numero; i++){
    system("cls");
    cout << "\n Digite uma letra para o vetor: ";
    cin >> vetor[i];
}

    cout << "\n Sequencia criada: ";

    for (int i = 0; i < numero; i++)
    {
        cout << vetor[i];
    }

    free(vetor);
}
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  int numero, elemento;

  Aloc(numero, elemento);
 
  cout << endl;
  return 0;
}