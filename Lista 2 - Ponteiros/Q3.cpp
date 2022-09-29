#include <iostream>
#include <windows.h>

// Comparando maior conteudo com ponteiros

using namespace std;

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int *x;
  int *y;

  int numero1, numero2;

  cout << "\n Digite um número: ";
  cin >> numero1;
  cout << "\n Digite um número: ";
  cin >> numero2;

  x = &numero1;
  y = &numero2;
  *x = numero1;
  *y = numero2;

  if (*x > *y)
  {
    cout << "\n " << *x << " é maior que " << *y;
  }
  else
  {
    cout << "\n " << *x << " é maior que " << *y;
  }

  cout << endl;
  return 0;
}