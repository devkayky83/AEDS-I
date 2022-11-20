#include <iostream>
#include <windows.h>
#include "Super TP3.cpp"
#include <time.h>
#include <ctime>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
  int opcao, decisao;

  
  EstruturaFila Medicos;
  EstruturaFila Pacientes;
  EstruturaFila Medicos_D;
  EstruturaFila Atendidos;
  Medico ItemM;
  Paciente itemP;

  IniciarFila(&Medicos);
  IniciarFila(&Pacientes);
  IniciarFila(&Medicos_D);
  IniciarFila(&Atendidos);


  do
  {
    system("cls");
    Menu();
    cout << "\n Digite oque deseja acessar: ";
    cin >> opcao;

    switch(opcao)
    {

      case 1:

        if (VerificaTamanho(&Medicos) == 5)
        {
            cout << "\n A fila de médicos chegou ao seu limite (Total de médicos cadastrados: 5)" << endl;
            system("pause");
            break;
        }

        system("cls");

        cout << "\n -------------------------";
        cout << "\n    CADASTRO DE MÉDICOS";
        cout << "\n -------------------------" << endl;
  
        cout << "\n Digite o nome: ";
        cin.ignore();
        cin.getline(ItemM.nomeM, 50);
  
        cout << "\n Digite a especialização: ";
        cin.getline(ItemM.especializacao, 50);
  
        cout << "\n Digite o CRM: ";
        cin >> ItemM.CRM;

        AdicionaMedicos(&Medicos, ItemM);

        cout << "\n Médico cadastrado com sucesso!";
        cout << "\n ------------------------------" << endl;

        cout << "\n Mais algum médico será cadastrado? (1) para sim, (0) para não: ";
        cin >> decisao;

        while(decisao != 0)
        {
          if (VerificaTamanho(&Medicos) == 5)
          {
            cout << "\n A fila de médicos chegou ao seu limite (Total de médicos cadastrados: 5)" << endl;
            system("pause");
            break;
          }

          system("cls");

          cout << "\n -------------------------";
          cout << "\n    CADASTRO DE MÉDICOS";
          cout << "\n -------------------------" << endl;
  
          cout << "\n Digite o nome: ";
          cin.ignore();
          cin.getline(ItemM.nomeM, 50);
  
          cout << "\n Digite a especialização: ";
          cin.getline(ItemM.especializacao, 50);
  
          cout << "\n Digite o CRM: ";
          cin >> ItemM.CRM;
  
          AdicionaMedicos(&Medicos, ItemM);
  
          cout << "\n Médico cadastrado com sucesso!";
          cout << "\n ------------------------------" << endl;

          cout << "\n Mais algum médico será cadastrado? (1) para sim, (0) para não: ";
          cin >> decisao;
        }

        if (decisao == 0)
        {
          break;
        }
      break;


      case 2:

        char recebe;
        system("cls");

        recebe = retorno_triagem();
        Prioridade(&itemP, recebe);
        AdicionaPrioridade(&Pacientes, itemP);
        cout << "\n Paciente Cadastrado com sucesso!" << endl;
        system("pause");
        break;

      case 3:
        system("cls");

        cout << "\n -------------------------";
        cout << "\n   REGISTRO HOSPITALAR ";
        cout << "\n -------------------------";

        cout << "\n Total de médicos cadastrados: " << VerificaTamanho(&Medicos);
        cout << "\n Total de médicos disponíveis: " << VerificaTamanho(&Medicos_D);
        cout << "\n Total de pacientes cadastrados: " << VerificaTamanho(&Pacientes);
        cout << "\n Total de pacientes atendidos: " << VerificaTamanho(&Atendidos) << endl;

        ImprimeMedicos(&Medicos);

        cout << "\n  PACIENTES CADASTRADOS ";
        cout << "\n ------------------------";
        ImprimePacientes(&Pacientes);

        cout << "\n  PACIENTES ATENDIDOS ";
        cout << "\n -----------------------";
        ImprimePacientes(&Atendidos);
      break;

      case 4:
        ImprimeAtendimento(Pacientes, Atendidos, Medicos, Medicos_D);
      break;
    }


  }while(opcao != 0); 





 
 
  cout << endl;
  return 0;
}