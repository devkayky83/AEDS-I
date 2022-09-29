#include <iostream>
#include <windows.h>
#include <fstream>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  string nome[50];
  int telefone[9];
  int opcao, dat;

  cout << "\n Digite quantas pessoas serão cadastradas: ";
  cin >> dat;

  ofstream arquivo2S;

  arquivo2S.open("Lista Telefônica.xls");
 
  for (int i = 0; i < dat; i++)
  {
  system("cls");
  cout << "\n Digite o nome: ";
  getline(cin >> ws, nome[i]);
  cout << "\n Digite o telefône: ";
  cin >> telefone[i];
  }
  
  cout << "\n Cadastro(s) feitos com sucesso!";

  
  arquivo2S << "\n" << "NOME ----------- TELEFÔNE" << endl;
  for (int i = 0; i < dat; i++)
  { 
  arquivo2S << endl << nome[i] << " ------------- " << telefone[i];
  }
  arquivo2S.close();


  ifstream arquivo2E;

  arquivo2E.open("Lista Telefônica.xls");
  if (!arquivo2E.is_open())
  { 
    cout << "\n Não foi possível abrir o arquivo!";
    cout << "\n O mesmo pode ter sido apagado!";
  }
 
  cout << endl;
  return 0;
}