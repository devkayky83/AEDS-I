#include <iostream>
#include "Trabalho1.hpp"

using namespace std;


void Lista_Menu(){
       
    cout << " ----------------------------------------\n";
    cout << "          Funcionários e Projetos        \n";
    cout << " ----------------------------------------\n";
    cout << " 1. Inserir novo funcionario\n";
    cout << " 2. Inserir novos projetos\n";
    cout << " 3. Excluir projeto\n";
    cout << " 4. Excluir funcionário\n";
    cout << " 5. Exclusão de funcionario sem projeto\n";
    cout << " 6. Consultar funcionário\n";
    cout << " 7. Imprimir contra-cheque\n";
    cout << " 0. Sair\n\n";
}

void CriarListaFuncionario(ListaFuncionario *lista)
{
    lista->primeiro = new Armazenamento;
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
}

void InsereListaFuncionario(ListaFuncionario *lista, Funcionario func)
{
    lista->ultimo->prox = new Armazenamento;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->itens = func;
    lista->ultimo->prox = NULL; 
    lista->cont++;
}

void ImprimeFuncionario(ListaFuncionario *lista)
{
    TChave c;
    Apontador alvo1;
    
    int atual;

    system("cls");

    cout << "\n Digite o ID do funcionário: ";
    cin >> c;

    atual = BuscarListaFuncionario(c, *lista, &alvo1);

    if (atual == 1)
    {
        system("cls");
        cout << "\n Total de funcionários cadastrados: " << lista->cont;
        cout << "\n ------------------------------------" << endl;
        cout << "\n Nome: " << alvo1->prox->itens.nome;
        cout << "\n ID: " << alvo1->prox->itens.id;
        cout << "\n Dependentes: " << alvo1->prox->itens.dependentes;
        cout << "\n Estado: " << alvo1->prox->itens.endereco.estado;
        cout << "\n Cidade: " << alvo1->prox->itens.endereco.cidade;
        cout << "\n Bairro: " << alvo1->prox->itens.endereco.bairro;
        cout << "\n Rua: " << alvo1->prox->itens.endereco.rua;
        cout << "\n Número da casa: " << alvo1->prox->itens.endereco.numero;

        cout << "\n -------------------------" << endl;
        cout << "\n INFORMAÇÕES DE PROJETOS NESTE FUNCIONÁRIO: " << endl;
        cout << "\n -------------------------------------------" << endl;

        ImprimeProjeto(alvo1->prox->itens.projetos);

        system("pause");
        system("cls");
        cout << endl;
    }else
    {
        cout << "\n O sequinte ID não está registrado na lista!" << endl;
        system("pause");
    }
}

int VerificaListaFuncionarioVazia(ListaFuncionario *lista)
{
    return (lista->primeiro == lista->ultimo);
}

void CriarListaProjeto(ListaProjetos *pro)
{
    pro->primeiro = MAXTAM_C;
    pro->ultimo = pro->primeiro;
}

void InsereListaProjeto(Projeto proj1, ListaProjetos *pro)
{
    if(pro->ultimo == MAXTAM)
    {
        cout << "\n Não é possivel adicionar mais projetos! O limite foi atingido!" << endl;
    }else
    {
        pro->itens[pro->ultimo] = proj1;
        pro->ultimo++;
    }
}

void ImprimeProjeto(ListaProjetos pro)
{
    for (int i = 0; i < pro.ultimo; i++)
    {
        cout << "\n Código do projeto: " << pro.itens[i].codigo;
        cout << "\n Nome do projeto: " << pro.itens[i].nome;
        cout << "\n Total de horas trabalhadas: " << pro.itens[i].horas << endl;
        cout << endl;
    }
}

int VerificaListaProjetoVazia(ListaProjetos *pro)
{
   return (pro->primeiro == pro->ultimo);
}

int BuscarListaFuncionario(TChave c, ListaFuncionario lista, Apontador *alvo1)
{
    Apontador alvo2 = lista.primeiro;

    int a = 0;

    while((!a) && (alvo2->prox != NULL))
    {
        if (alvo2->prox->itens.id == c)
        {
            a = 1;
        }else
        {
            alvo2 = alvo2->prox;
        }
        }
        *alvo1 = alvo2;
        return a;
}

int BuscarListaProjeto(ListaProjetos pro, int c, int *alvo1)
{
    int primeiro = pro.primeiro;
    int a = 0;

    while ((!a) && (primeiro < pro.ultimo))
    {
        if (pro.itens[primeiro].codigo == c)
        {
            a = 1;
        }else
        {
            primeiro++;
        }
        *alvo1 = primeiro;
        return (a);
    }
}

void CadastrarProjetos(ListaFuncionario *lista)
{
    Projeto proj1;
    Apontador alvo1;
    TChave c;

    int aux2, aux3;

    system("cls");

    cout << "\n Digite o ID do funcionário no qual deseja adicionar um projeto: ";
    cin >> c;

    aux2 = BuscarListaFuncionario(c, *lista, &alvo1);

    if(aux2 == 1)
    {
        system("cls");
        cout << "\n Digite um código para o projeto: ";
        cin >> proj1.codigo;
    }

    if (BuscarListaProjeto(alvo1->prox->itens.projetos, proj1.codigo, &aux3))
    {
        cout << "\n O sequinte código já existe!";
        system("pause");
        system("cls");
    }else
    {
        cout << "\n Digite o nome do projeto: ";
        cin.ignore();
        cin.getline(proj1.nome, 30);

        cout << "\n Digite a quantidade de horas trabalhadas neste projeto: ";
        cin >> proj1.horas;

        InsereListaProjeto(proj1, &(alvo1->prox->itens.projetos));

         cout << "\n Projeto registrado com sucesso!" << endl;
         system("pause");
         system("cls");
    }

}

void ExcluirProjeto(ListaFuncionario *lista)
{
    Projeto pro;
    TChave c;
    Apontador alvo1;

    int aux2, alvo, parametro;

    system("cls");

    cout << "\n Digite o código do funcionário: ";
    cin >> c;

    aux2 = BuscarListaFuncionario(c, *lista, &alvo1);

    if (aux2 == 1)
    {
        alvo1 = alvo1->prox;

        cout << "\n Digite o código do projeto que deseja excluir: ";
        cin >> alvo;

        if (BuscarListaProjeto(alvo1->itens.projetos, alvo, &parametro))
        {
            ExcluiFuncionario(parametro, &(alvo1->itens.projetos), &pro);

            cout << "\n O projeto foi excluido com sucesso!" << endl;
            system("pause");
            system("cls");
        }else
        {
            cout << "\n O sequinte código não existe!";
            system("pause");
            system("cls");
        }
    }else
    {
        cout << "\n O código do projeto não pode ser encontrado ou não existe!";
        system("pause");
        system("cls");
    }
}

void ExcluiFuncionario(int alvo1, ListaProjetos *pro, Projeto *proj1)
{
    if (VerificaListaProjetoVazia(pro))
    {
        cout << "\n A lista de projetos está vazia!";
    }
    *proj1 = pro->itens[alvo1];
    pro->ultimo--;

    for (int i = alvo1; i < pro->ultimo; i++)
    {
        pro->itens[i] = pro->itens[i + 1];
    }
}

void FuncionarioExclusaoOficial(ListaFuncionario *lista)
{
    Funcionario func;
    Apontador aux = lista->primeiro;

    int contador = 0;



    while (aux->prox != NULL)
    {
        Deletar(aux, lista, &func);
        contador++;
    }

    cout << "\n Funcionário excluido com sucesso!" << endl;
    system("pause");
    system("cls");
}

void Deletar(Apontador aux, ListaFuncionario *lista, Funcionario *func)
{
    Apontador aux2;

    if ((VerificaListaFuncionarioVazia(lista)) || (aux == NULL) || aux->prox == NULL)
    {
        cout << "\n A lista está vazia!";
    }else
    {
        aux2 = aux->prox;
        *func = aux2->itens;
        aux->prox = aux2->prox;

        if (aux->prox == NULL)
        {
            lista->ultimo = aux;
        }
        delete aux2;
    }
}

void DeletarFuncionarioSemProjeto(ListaFuncionario *lista)
{
    Apontador alvo1, alvo4;
    TChave c;

    int atual;

    system("cls");
    cout << "\n Digite o ID do funcionário: " << endl;
    cin >> c;

    atual = BuscarListaFuncionario(c, *lista, &alvo1);
    if (atual == 1)
    {
        if (alvo1->prox->itens.projetos.primeiro == alvo1->prox->itens.projetos.ultimo)
        {
            alvo4 = alvo1;
            alvo1 = alvo1->prox;
            alvo4->prox = alvo1->prox;
            delete alvo1;

            cout << "\n Funcionário excluido com sucesso!" << endl;
            system("pause");
            system("cls");
        }else
        {
            cout << '\n Este Funcionário possui projetos!';
            system("pause");
            system("cls");
        }
    }else
    {
        cout << "\n O sequinte código não existe!" << endl;
        system("pause");
        system("cls");
    }

}

void ImprimeCC(ListaFuncionario *lista)
{
    Apontador pont = lista->primeiro->prox;

    int T_horas = 0;
    double Salario_B;
    double Salario_L;
    double INSS;
    double IRPF;

    system("cls");

    while(pont)
    {
        cout << "\n Nome: " << pont->itens.nome << endl;
        cout << "\n ID: " << pont->itens.id << endl;
        cout << "\n --------------------------------" << endl;

        for (int i = 0; i < pont->itens.projetos.ultimo; i++)
        {
            T_horas = T_horas + pont->itens.projetos.itens[i].horas;
        }

        Salario_B = (T_horas * 45) + (35 * pont->itens.dependentes);
        INSS = Salario_B * 0.085;
        IRPF = Salario_B * 0.15;
        Salario_L = Salario_B - (INSS + IRPF);

        cout << "\n Total de horas trabalhadas: " << T_horas << endl;
        cout << "\n Salario Bruto: " << Salario_B << endl;
        cout << "\n Desconto do INSS: " << INSS << endl;
        cout << "\n Desconto do IRPF: " << IRPF << endl;
        cout << "\n Salario Liquido: " << Salario_L << endl;
    
        T_horas = 0;
        Salario_B = 0;
        INSS = 0;
        IRPF = 0;
        Salario_L = 0;
    
        pont = pont->prox;
    }
    system("pause");
    system("cls");
}

