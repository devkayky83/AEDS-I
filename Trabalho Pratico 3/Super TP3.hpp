#ifndef STP3_H
#define STP3_H


typedef struct Medico
{
    char nomeM[50];
    char especializacao[50];
    char CRM[15];
    bool disponivel = true;
};

typedef struct EnderecoPaciente
{
    char bairro[30];
    char rua[50];
    int numero;
};

typedef struct Paciente
{
    char nomeP[50];
    int idade;
    char sexo[15];
    char triagem[18];
    int prioridade;
    double tempo;
    bool atendido = false;
    EnderecoPaciente endP;
    time_t HC;
    time_t HS;
};

typedef struct Celula *Apontador;

typedef struct Celula
{
    Medico itemM;
    Paciente itemP;
    Apontador prox;
};

typedef struct EstruturaFila
{
    Apontador inicio, fim;
    int tamanho;
};


#endif