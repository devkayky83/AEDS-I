#ifndef T1_H
#define T1_H

#define MAXTAM 5
#define MAXTAM_C 0


typedef int TChave;

typedef struct TCelula_str *Apontador;

typedef struct Projeto
{
    TChave codigo;
    char nome[30];
    int horas;
};

typedef struct ListaProjetos
{
    Projeto itens[MAXTAM];
    int primeiro;
    int ultimo;
};

typedef struct FuncionarioEndereco
{
    char estado[30];
    char cidade[30];
    char bairro[30];
    char rua[30];
    int numero;
};

typedef struct Funcionario
{
    TChave id;
    char nome[40];
    FuncionarioEndereco endereco;
    int dependentes;
    ListaProjetos projetos;
};

typedef struct TCelula_str
{
    Funcionario itens;
    Apontador prox;
} Armazenamento;

typedef struct ListaFuncionario
{
    Apontador primeiro;
    Apontador ultimo;
};

void Lista_Menu();

void CriarListaFuncionario(ListaFuncionario *lista);

void InsereListaFuncionario(ListaFuncionario *lista, Funcionario func);

void ImprimeFuncionario(ListaFuncionario *lista);

int VerificaListaFuncionarioVazia(ListaFuncionario *lista);

void CriarListaProjeto(ListaProjetos *pro);

void InsereListaProjeto(Projeto proj1, ListaProjetos *pro);

void ImprimeProjeto(ListaProjetos pro);

int VerificaListaProjetoVazia(ListaProjetos *pro);

int BuscarListaFuncionario(TChave c, ListaFuncionario lista, Apontador *alvo1);

int BuscarListaProjeto(ListaProjetos pro, int c, int *alvo1);

void CadastrarProjetos(ListaFuncionario *lista);

void ExcluirProjeto(ListaFuncionario *lista);

void ExcluiFuncionario(int alvo1, ListaProjetos *pro, Projeto *proj1);

void FuncionarioExclusaoOficial(ListaFuncionario *lista);

void Deletar(Apontador aux, ListaFuncionario *lista, Funcionario *func);

void DeletarFuncionarioSemProjeto(ListaFuncionario *lista);

void ImprimeCC(ListaFuncionario *Lista);




#endif