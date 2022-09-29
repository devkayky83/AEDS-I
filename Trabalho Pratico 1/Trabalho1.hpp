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

void CriarListaFuncionario(ListaFuncionario *lista); // Cria a lista de funcionarios para o cadastramento e armazenamento dos mesmos

void InsereListaFuncionario(ListaFuncionario *lista, Funcionario func); // Insere o funcionario cadastrado na lista.

void ImprimeFuncionario(ListaFuncionario *lista); // Mostra na tela os dados referente ao funcionario procurado

int VerificaListaFuncionarioVazia(ListaFuncionario *lista); // Verifica se a lista de funcionarios está vazia

void CriarListaProjeto(ListaProjetos *pro); // Cria a lista de projetos para o cadastramento e armazenamento dos mesmos

void InsereListaProjeto(Projeto proj1, ListaProjetos *pro); // Função auxiliar da função CadastrarProjetos

void ImprimeProjeto(ListaProjetos pro); // Mostra na tela os dados referente ao projeto junto ao funcionario procurado

int VerificaListaProjetoVazia(ListaProjetos *pro); // Verifica se a lista de projetos está vazia.

int BuscarListaFuncionario(TChave c, ListaFuncionario lista, Apontador *alvo1); // Procura o funcionario requesitado na lista de funcionarios

int BuscarListaProjeto(ListaProjetos pro, int c, int *alvo1); // Procura o projeto requesitado na lista de projetos

void CadastrarProjetos(ListaFuncionario *lista); // Insere o projeto cadastrado na lista.

void ExcluirProjeto(ListaFuncionario *lista); // Exclui o projeto requesitado

void ExcluiFuncionario(int alvo1, ListaProjetos *pro, Projeto *proj1); // Função auxiliar da função ExcluirProjetos 

void FuncionarioExclusaoOficial(ListaFuncionario *lista); // Exclui o funcionário requesitado

void Deletar(Apontador aux, ListaFuncionario *lista, Funcionario *func); // Função auxiliar da função ExcluirProjetos 

void DeletarFuncionarioSemProjeto(ListaFuncionario *lista); // Exclui funcionario com nenhum projeto cadastrado

void ImprimeCC(ListaFuncionario *Lista); // Imprime o contra cheque com base nos dados do funcionário cadastrado




#endif