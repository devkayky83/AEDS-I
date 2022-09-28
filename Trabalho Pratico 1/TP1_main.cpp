#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Trabalho1.hpp"
#include "TP1.cpp"

using namespace std;
 
int main() {
  
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int opcao;
 
  ListaFuncionario lista;
  Apontador alvo;
  Funcionario funcionario;

  CriarListaFuncionario(&lista);

  FILE *arquivo;
  arquivo = fopen("Funcionarios e Projetos.bin", "a+b");
  alvo = lista.primeiro;

  if (arquivo != NULL)
  {
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo))
    {
        InsereListaFuncionario(&lista, funcionario);
    }
    fclose(arquivo);
  }
  else
  {
    cout << "\n O seguinte arquivo não existe!";
    getch();
    system("cls");
  }

  do
  {
    system("cls");
    Lista_Menu();
    cout << " Escolha a opção que deseja acessar: ";
    cin >> opcao;
    system("cls");

    switch (opcao)
    {

      case 1:
      system("cls");
      Funcionario funcionario;

      cout << "\n Digite o nome: ";
      cin.ignore();
      cin.getline(funcionario.nome, 40);

      cout << "\n Digite o ID do funcionário: ";
      cin >> funcionario.id;
      cin.ignore();

      cout << "\n Digite com quantas pessoas voçê trabalha: ";
      cin >> funcionario.dependentes;
      cin.ignore();

      cout << "\n Digite o estado: ";
      cin.getline(funcionario.endereco.estado, 30);

      cout << "\n Digite a cidade: ";
      cin.getline(funcionario.endereco.cidade, 30);

      cout << "\n Digite o bairro: ";
      cin.getline(funcionario.endereco.bairro, 30);

      cout << "\n Digite a rua: ";
      cin.getline(funcionario.endereco.rua, 30);

      cout << "\n Digite o número da casa: ";
      cin >> funcionario.endereco.numero;

      CriarListaProjeto(&funcionario.projetos);
      InsereListaFuncionario(&lista, funcionario);

      cout << "\n Registro de funcionário feito com sucesso!" << endl;
      cout << " --------------------------------------------------\n";

      cout << "\n Deseja adicionar um projeto ao funcionário? (1) para sim, (2) para não: ";
      cin >> opcao;

      if(opcao == 1)
      {
        CadastrarProjetos(&lista);  
      }
      system("cls");
      break;

      case 2:
      system("cls");
      CadastrarProjetos(&lista);
      break;;

      case 3:
      ExcluirProjeto(&lista);
      break;

      case 4:
      FuncionarioExclusaoOficial(&lista);
      break;

      case 5:
      DeletarFuncionarioSemProjeto(&lista);
      break;

      case 6:
      ImprimeFuncionario(&lista);
      break;

      case 7:
      ImprimeCC(&lista);
      break;
    }
  }while (opcao != 0);
 
  arquivo = fopen("Funcionarios e Projetos.bin", "wb");

  while(alvo->prox != NULL)
  {
    funcionario = alvo->prox->itens;
    fwrite(&funcionario, sizeof(Funcionario), 1, arquivo);
    alvo = alvo->prox;
  }
    fclose(arquivo);

  cout << endl;
  return 0;
}
