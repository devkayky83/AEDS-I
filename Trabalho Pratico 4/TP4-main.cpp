// Senha de acesso: MenosQueTotalNaoEValido
// Desenvolvido por: Calebe Ribeiro e Kayky Júnio

#include <iostream>
#include "TP4_Funcoes.cpp"
#include <windows.h>
 
using namespace std;
 
int main() 
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int idLinhas = 1;
    string senha;
    string senhaCorreta = "MenosQueTotalNaoEValido";

    tipoLista linhas;
    criarListaVazia(&linhas);
    viagensLinha(&linhas, &idLinhas);

    imprimeListaDupla(&linhas.ultimo->item.paradas);
    int escolha;

    while (escolha != 0)
    {
        menu();
        cout << "\n Digite oque deseja acessar: ";
        cin >> escolha;

        if (escolha == 1)
        {
            system("cls");
            encontreLinha(&linhas);
        }
        else if (escolha == 2)
        {
            system("cls");
            cout << "\n Informe a senha: ";
            cin >> senha;

            if (senha == senhaCorreta)
            {
                system("cls");
                alteracaoCompleta(&linhas, &idLinhas);
            }
            else
            {
              cout << endl;
              cout << "\n Senha incorreta!" << endl;
            }
        }
    }
    return 0;
}


void menu(){
  cout << "\n -------------------------------------" << endl;
  cout << "         SISTEMA DE VIAGENS      ";
  cout << "\n -------------------------------------";
  cout << "\n         1. Procura Linha";
  cout << "\n         2. Edita Linhas";
  cout << "\n         0. Sair";
  cout << "\n -------------------------------------" << endl; 
}