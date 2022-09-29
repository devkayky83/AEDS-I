#include <iostream>
#include <windows.h>

// Comparando maior endereço
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  int var1, var2, *pont1, *pont2;

  cout << "\n Digite um número: ";
  cin >> var1;

  cout << "\n Digite um número: ";
  cin >> var2;

  pont1 = &var1;
  pont2 = &var2;

  if (&pont1 > &pont2)
  {
    cout << "\n " << pont1 << var1 << endl << " " << pont2 << var2;
  }else
  {
    cout << "\n " << var2 << pont2 << endl << var1 << var2;
  }

 
 
  cout << endl;
  return 0;
}