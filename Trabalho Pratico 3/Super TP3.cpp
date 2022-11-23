#include <iostream>
#include "Super TP3.hpp"
#include <time.h>

using namespace std;


void Menu()
{
    cout << "\n ------------------------------------------";
    cout << "\n         HOSPITAL - 'CHEGOU, MORREU'";
    cout << "\n ------------------------------------------" << endl;
    cout << "\n 1. Cadastrar Médicos";
    cout << "\n 2. Atender Paciente";
    cout << "\n 3. Imprimir REGISTRO DO HOSPITAL (UPA)";
    cout << "\n 4. Imprimir Dados Finais";
    cout << "\n 0. Sair";
    cout << "\n ------------------------------------------" << endl;
}

void Menu_Triagem()
{
    system("cls");
    
    cout << "\n   -----------------------------";
    cout << "\n      TRIAGEM - QUESTIONÁRIO";
    cout << "\n   -----------------------------" << endl;

    cout << "\n 1. Comprometimento da via aérea? ";
    cout << "\n 2. Respiração ineficas? ";
    cout << "\n 3. Choque? ";
    cout << "\n 4. Não responde a estímulos? ";
    cout << "\n 5. Em convulsão? ";
    cout << "\n -----------------------------------";
    cout << "\n 6. Dor severa? ";
    cout << "\n 7. Grande hemorragia incontrolável? ";
    cout << "\n 8. Alteração do estado de consciência? ";
    cout << "\n 9. Temperatura maior ou igual a 39ºC? ";
    cout << "\n 10. Trauma craniano? ";
    cout << "\n ------------------------------------";
    cout << "\n 11. Dor moderada? ";
    cout << "\n 12. Pequena hemorragia incontrolável? ";
    cout << "\n 13. Vômito persistente? ";
    cout << "\n 14. Temperatura entre 38ºC e 39ºC? ";
    cout << "\n 15. Idoso ou grávida? ";
    cout << "\n ------------------------------------";
    cout << "\n 16. Dor leve?";
    cout << "\n 17. Náuseas? ";
    cout << "\n 18. Temperatura entre 37ºC e 39ºC? ";
    cout << "\n ------------------------------------";
    cout << "\n - Responda (S) para sim, (N) para não";
    cout << "\n ---------------------------------------" << endl;
}

void IniciarFila(EstruturaFila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

bool VerificaFilaVazia(EstruturaFila *fila)
{
    return (fila->tamanho == NULL);
}

int VerificaTamanho(EstruturaFila *fila)
{
    return fila->tamanho;
}

void AdicionaMedicos(EstruturaFila *fila, Medico item)
{
    Apontador alvo;

    alvo = new Celula;
    alvo->itemM = item;
    alvo->prox = NULL;

    if (VerificaFilaVazia(fila))
    {
        fila->inicio = alvo;
    }
    else
    {
        fila->fim->prox = alvo;
    }

    fila->fim = alvo;
    fila->tamanho++;
}

void AdicionaPaciente(EstruturaFila *fila, Paciente itemP)
{
    Apontador alvo;

    alvo = new Celula;
    alvo->itemP = itemP;
    alvo->prox = NULL;

    if (VerificaFilaVazia(fila))
    {
        fila->inicio = alvo;
    }else
    {
        fila->fim->prox = alvo;
    }
    fila->fim = alvo;
    fila->tamanho++;
}

void Prioridade(Paciente *itemP, int recebe)
{
    int prioridade;
    double Tempo_A;

    if (recebe >= 1 && recebe <= 5)
    {
        prioridade = 0;
        Tempo_A = 5;
    }
    else if (recebe > 5 && recebe <= 10)
    {
        prioridade = 1;
        Tempo_A = 4;
    }
    else if (recebe > 10 && recebe <= 15)
    {
        prioridade = 2;
        Tempo_A = 3;
    }
    else if (recebe > 15 && recebe <= 18)
    {
        prioridade = 3;
        Tempo_A = 2;
    }
    else if (recebe == 0)
    {
        prioridade = 4;
        Tempo_A = 1;
    }

    system("cls");
    cout << "\n ----------------------------";
    cout << "\n     REGISTRO DE PACIENTE";
    cout << "\n ----------------------------" << endl;

    cout << "\n - Responda o questionario com as informações pedintes: " << endl;

    cout << "\n 1. Nome: ";
    cin.ignore();
    cin.getline(itemP->nomeP, 50);
    
    cout << "\n 2. Idade: ";
    cin >> itemP->idade;
  
    cout << "\n 3. Bairro: ";
    cin.ignore();
    cin.getline(itemP->endP.bairro, 30);

    cout << "\n 4. Rua: ";
    cin.getline(itemP->endP.rua, 50);

    cout << "\n 5. Número da casa: ";
    cin >> itemP->endP.numero;

    cout << "\n 6. Sexo: ";
    cin.ignore();
    cin.getline(itemP->sexo, 15);
    cout << "\n ------------------------------" << endl;

    itemP->prioridade = prioridade;
    itemP->HC = time(NULL);
    itemP->tempo = Tempo_A;
}

void AdicionaPrimeiro(EstruturaFila *fila, Paciente item)
{
    Apontador aux;

    aux = new Celula;
    aux->itemP = item;
    aux->prox = NULL;

    if (VerificaFilaVazia(fila))
    {
        fila->inicio = aux;
        fila->fim = fila->inicio;
    }
    else
    {
        aux->prox = fila->inicio;
        fila->inicio = aux;
    }
    fila->tamanho++;
}

void AdicionaApos(Apontador anterior, Apontador alvo, EstruturaFila *fila)
{
    alvo->prox = anterior->prox;
    anterior->prox = alvo;
    fila->tamanho++;
}

void AdicionaPrioridade(EstruturaFila *fila, Paciente item)
{   
    Apontador anterior, atual, alvo;

    if (VerificaFilaVazia(fila))
    {
        AdicionaPrimeiro(fila, item);
        return;
    }

    if (item.prioridade < fila->inicio->itemP.prioridade)
    {
        AdicionaPrimeiro(fila, item);
        return;
    }

    anterior = fila->inicio;
    atual = anterior->prox;
    alvo = new Celula;
    alvo->itemP = item;
    alvo->prox = NULL;

    while (atual != NULL)
    {
        if (alvo->itemP.prioridade < atual->itemP.prioridade)
        {
            AdicionaApos(anterior, alvo, fila);
            return;
        }
            anterior = atual;
            atual = atual->prox;
    }
    AdicionaApos(anterior, alvo, fila);
    fila->fim = alvo;
}

void RetiraPaciente(EstruturaFila *fila, Paciente *item)
{
    Apontador aux;

    if (VerificaFilaVazia(fila))
    {
        cout << "\n A fila de pacientes está vazia!";
        return;
    }

    aux = fila->inicio;

    *item = aux->itemP;
    fila->inicio = aux->prox;
    delete aux;
    // fila->tamanho--;
}

void ImprimeMedicos(EstruturaFila *fila)
{
    Apontador aux;

    aux = fila->inicio;

    cout << "\n ------------------------";
    cout << "\n   MÉDICOS CADASTRADOS";
    cout << "\n ------------------------" << endl;

    while (aux != NULL)
    {
        cout << "\n Nome: " << aux->itemM.nomeM;
        cout << "\n Especialização: " << aux->itemM.especializacao;
        cout << "\n CRA: " << aux->itemM.CRM << endl;
        aux = aux->prox;
    }
    system("pause");
}

void ImprimePacientes(EstruturaFila *fila)
{
  
    Apontador aux;

    if (VerificaFilaVazia(fila))
    {
        cout << "\n Nenhum paciente cadastrado!" << endl;
        system("cls");
        return;
    }

    aux = fila->inicio;

    while (aux != NULL)
    {
        cout << "\n Nome: " << aux->itemP.nomeP;
        cout << "\n Idade: " << aux->itemP.idade;
        cout << "\n Bairro: " << aux->itemP.endP.bairro;
        cout << "\n Rua: " << aux->itemP.endP.rua;
        cout << "\n Número da casa: " << aux->itemP.endP.numero;
        cout << "\n Sexo: " << aux->itemP.sexo;
        cout << "\n Prioridade: " << aux->itemP.prioridade;
        cout << "\n Atendido? (1) Sim, (0) Não: " << aux->itemP.atendido; 

            if (aux->itemP.atendido == 1)
            {
                cout << "\n Tempo total de atendimento: " << aux->itemP.tempo;
            } 

            cout << "\n Horario de chegada: " << ctime(&aux->itemP.HC);

        aux = aux->prox;
    }
    cout << endl;
    system("pause");
}

void Atualiza(EstruturaFila *Pacientes, EstruturaFila *Atendidos, Paciente *itemP, EstruturaFila *Medicos, Medico *ItemM, EstruturaFila *Medicos_D)
{  
    Apontador aux;
    Apontador aux2;

    aux = Pacientes->inicio;
    aux2 = Medicos->inicio;

    aux2->itemM.disponivel = true;

    for (int i = 0; i < Medicos->tamanho; i++)
    {
        aux->itemP.HS = time(NULL);
        aux->itemP.tempo =  aux->itemP.HS - aux->itemP.HC;

        cout << "\n Paciente " << aux->itemP.nomeP << " foi atendido em: " << aux->itemP.tempo << " minutos"
             << " pelo médico: " << aux2->itemM.nomeM;

        cout << "\n Paciente atendido com sucesso!\n";

        aux->itemP.atendido = true;
        aux2->itemM.disponivel = false;

        if (aux->itemP.atendido == true)
        {
            AdicionaPrioridade(Atendidos, aux->itemP);
            RetiraPaciente(Pacientes, &aux->itemP);
        }
        if (Pacientes->tamanho == Atendidos->tamanho)
        {
            if (aux2->itemM.disponivel == true)
            {
                AdicionaMedicos(Medicos_D, aux2->itemM);
            }
            break; // Se todos os pacientes forem atendidos e sobrar algum medico, volta para o menu.
        }
        aux2 = aux2->prox;
        aux = aux->prox;
        Sleep(1000);
    }
}

int retorno_triagem()
{
    Paciente itemP;
    char recebe[18];

    for (int i = 0; i <= 5; i++)
    {
        Menu_Triagem();
        cout << "\n Pergunta " << i + 1 << ": ";
        cin >> recebe[i];

            if (recebe[i] == 'S' || recebe[i] == 's')
            {
                cout << "\n - Sua prioridade é de nivel vermelho! - nivel (0)";
                cout << "\n ---------------------------------------------------" << endl;
                system("pause");
                return i;
            }
    }
    for (int i = 6; i < 18; i++)
    {
        Menu_Triagem();
        cout << "\n Pergunta " << i + 1 << ": ";
        cin >> recebe[i];
    }
    
    cout << "\n - Ordem das respostas: ";
    for (int i = 0; i < 18; i++)
    {
        cout << recebe[i] << " ";
    }
    for (int i = 6; i < 18; i++)
    {
        if (recebe[i] == 'S')
        {
            if (i > 5 && i <= 10)
            {
                cout << endl;
                cout << "\n - Sua prioridade é de nivel laranja! - nivel (1)";
                cout << "\n ---------------------------------------------------" << endl;
                system("pause");
            }
            else if (i > 10 && i < 15)
            {
                cout << endl;
                cout << "\n - Sua prioridade é de nivel amarelo! - nivel (2)";
                cout << "\n ---------------------------------------------------" << endl;
                system("pause");
            }
            else if (i >= 15 && i <= 18)
            {
                cout << endl;
                cout << "\n - Sua prioridade é de nivel verde! - nivel (3)";
                cout << "\n ---------------------------------------------------" << endl;
                system("pause");
            }
            return i;
        }
    }
    for (int i = 0; i < 18; i++)
    {
        if (recebe[i] != 'S')
        {
            cout << endl;
            cout << "\n - Sua prioridade é de nivel azul! - nivel (4)";
            cout << "\n ---------------------------------------------------" << endl;
            system("pause");
            i = 0;
            return i;
        }
    }
}

