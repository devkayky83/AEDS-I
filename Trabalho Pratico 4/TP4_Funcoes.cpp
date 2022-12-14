#include <iostream>
#include <windows.h>
#include "TP4_Funcoes.hpp"

using namespace std;

void viagensLinha(tipoLista *linha, int *id)
{
    // Linha Principal
    tipoItem item;
    item.id = *id;
    *id += 1;
    item.nome = "BH-SJE";
    item.companhia = "Onibus_1";

    criarListaVaziaDupla(&item.paradas);

    tipoItemDupla parada;

    // Saida da linha - BH
    parada.id = item.id;
    item.id++;
    parada.horarioChegada = "01:00";
    parada.horarioSaida = "01:15";
    parada.cidade = "BH";
    parada.passagem = 0;

    insereListaUltimoDupla(&item.paradas, parada);

    // Linha Itabira
    parada.id = item.id;
    item.id++;
    parada.horarioChegada = "01:50";
    parada.horarioSaida = "02:00";
    parada.cidade = "ITA";
    parada.passagem = 13.00;

    insereListaUltimoDupla(&item.paradas, parada);

    // Linha Santa Maria de Itabira
    parada.id = item.id;
    item.id++;
    parada.horarioChegada = "05:15";
    parada.horarioSaida = "05:25";
    parada.cidade = "STM";
    parada.passagem = 31.00;

    insereListaUltimoDupla(&item.paradas, parada);

    // Linha Guanhaes
    parada.id = item.id;
    item.id++;
    parada.horarioChegada = "06:15";
    parada.horarioSaida = "06:35";
    parada.cidade = "GHS";
    parada.passagem = 71.00;

    insereListaUltimoDupla(&item.paradas, parada);

    // Linha SJE
    parada.id = item.id;
    item.id++;
    parada.horarioChegada = "09:25";
    parada.horarioSaida = "09:45";
    parada.cidade = "SJE";
    parada.passagem = 54.18;

    insereListaUltimoDupla(&item.paradas, parada);
    insereListaUltimo(linha, &item);
}

void encontreLinha(tipoLista *linhas)
{
    int op;
    ApontadorDupla umaOrigem;
    ApontadorDupla umDestino;

    do{
        cout << "\n 1 - Encontre pela sua cidade: " << endl;
        cout << " 2 - Encontrar por codigo: " << endl;
        cout << " 0 - Voltar" << endl << endl;
        cout << "\n Digite oque deseja fazer: ";
        cin >> op;
        system("cls");
    } while (op != 0 && op != 1 && op != 2);
    

    if(op == 1)
    {
        float valor = 0;
        int rotas = 0;

        string cidadeOrigem;
        string cidadeDestino;

        bool Origem = false;
        bool Destino = false;

        Apontador linha;
        linha = linhas->primeiro->prox;

        cout << "\n Informe a sua cidade de origem: ";
        cin >> cidadeOrigem;
        cout << "\n Informe a cidade de destino: ";
        cin >> cidadeDestino;

        while(linha != NULL)
        {
            umDestino = linha->item.paradas.primeiro->prox;

            while (umDestino != linha->item.paradas.primeiro)
            {
                if (umDestino->item.cidade == cidadeDestino)
                {
                    Destino = true;
                    umaOrigem = umDestino;
                    valor = 0;

                    while (umaOrigem != linha->item.paradas.primeiro)
                    {
                        if (umaOrigem->item.cidade == cidadeOrigem)
                        {
                            Origem = true;
                            system("cls");
                            imprimeItemRecebido(linha->item);
                            cout << endl;
                            cout << "\n Preço da passagem: " << valor << endl;
                            cout << " Horário de saída: " << umaOrigem->item.horarioSaida << endl;
                            cout << " Horário de chegada: " << umDestino->item.horarioChegada << endl << endl;
                            rotas++;
                        }
                        valor += umaOrigem->item.passagem;
                        umaOrigem = umaOrigem->ant;
                    }
                }
                umDestino = umDestino->prox;
            }
            linha = linha->prox;
        }
        if(!Origem)
        {
            cout << "\n Origem inexistente.\n\n";
        }
        if(!Destino)
        {
            cout << "\n Destino inexistente.\n\n";
        } 
        if(rotas == 0 && !Origem && !Destino)
        {
            cout << "\n Linha inexistente.\n\n";
        }
        system("pause");
        system("cls");
        return;
    }

    if(op == 2)
    {
        int id;
        cout << "\n Informe o codigo da linha: ";
        cin >> id;

        Apontador aux = pesquisaItem(linhas, id);

        if(aux == NULL)
        {
            cout << "\n Não possui essa linha!";
            cout << endl;
            return;
        }

        imprimeItemRecebido(aux->item);
        cout << endl;

        cout << "\n Cidades: " << endl;
        imprimeListaDupla(&aux->item.paradas);
        system("pause");
        system("cls");
    }

    if(op == 3)
    {
        return;
    }
}

void criarLinha(tipoLista *linhas, int *id)
{
    tipoItem item;
    item.id = *id;

    cout << "\n Informe o nome da companhia que deseja adicionar: ";
    cin >> item.companhia;

    cout << "\n Insira o nome (código) da linha: ";
    cin >> item.linha;

    cout << "\n\n Linha criada!\n\n";

    criarListaVaziaDupla(&item.paradas);
    insereListaUltimo(linhas, &item);

    *id = *id + 1;
}

void criarParada(tipoLista *linhas)
{
    int id;

    cout << "\n Informe o ID que sera adicionado na parada: ";
    cin >> id;

    Apontador aux = pesquisaItem(linhas, id);

    while(aux == NULL)
    {
        cout << "\n Nenhuma linha encontrada!" << endl << endl;
    }

    tipoItemDupla parada;

    parada.id = aux->item.idStop;
    aux->item.idStop++;

    cout << "\n Informe o codigo da cidade: ";
    cin >> parada.cidade;
    cout << "\n Informe o horario de chegada: ";
    cin >> parada.horarioChegada;
    cout << "\n Informe o horário saida: ";
    cin >> parada.horarioSaida;
    cout << "\n Informe o valor da passagem: ";
    cin >> parada.passagem;

    if(verificaListaVaziaDupla(&aux->item.paradas))
    {
        cout << "\n -----------------------------";
        cout << "\n  A linha não contem paradas!" << endl;
        cout << "\n  A parada foi inserida!" << endl;

        insereListaUltimoDupla(&aux->item.paradas, parada);

        return;
    }
    imprimeListaDupla(&aux->item.paradas);

    cout << "\n Onde deseja incluir a parada? (Digite 0 para inserí-la no início).\n";
    cout << "\n ID: ";
    cin >> id;

    if(id == 0)
    {
        insereListaPrimeiroDupla(&aux->item.paradas, parada);
        cout << "\n Parada inserida.\n\n";
        return;
    }
    insereAposElementoDupla(&aux->item.paradas, parada, id);
}

void mudarParada(tipoLista *linhas)
{
    int id;

    cout << "\n Insira o ID da linha à qual deseja alterar uma parada: ";
    cin >> id;

    Apontador aux;
    aux = pesquisaItem(linhas, id);

    if(aux == NULL)
    {
        cout << "\n Não existe essa linha no nosso registro!" << endl;
        return;
    }

    if(verificaListaVaziaDupla(&aux->item.paradas))
    {
        cout << "\n Não contem parada nessa linha!" << endl;
        return;
    }

    imprimeListaDupla(&aux->item.paradas);

    cout << "\n Codigo da parada que deseja alterar: ";
    cin >> id;

    ApontadorDupla aux1;
    aux1 = localizaIDDupla(&aux->item.paradas, id);

    if(aux1 == NULL)
    {
        cout << "\n Não contem parada nessa linha!" << endl;
        return;
    }

    cout << "\n Dados alterados!" << endl;

    imprimeItemDupla(aux1->item);

    cout << "\n Informe o codigo da cidade: ";
    cin >> aux1->item.cidade;
    cout << "\n Informe o horario em que o onibus chegara na cidade: ";
    cin >> aux1->item.horarioChegada;
    cout << "\n Informe o horário em que o ônibus saira da cidade: ";
    cin >> aux1->item.horarioSaida;
    cout << "\n Informe o valor da passagem: ";
    cin >> aux1->item.passagem;
}

void excluirParada(tipoLista *linhas)
{
    int id;

    cout << "\n Informe o codigo da linha que deseja remover uma parada: ";
    cin >> id;

    Apontador aux;
    aux = pesquisaItem(linhas, id);

    if (aux == NULL)
    {
        cout << "\n Não existe essa linha no nosso registro!" << endl;
        return;
    }

    if (verificaListaVaziaDupla(&aux->item.paradas))
    {
        cout << "Não contem parada nessa linha!" << endl;
        return;
    }

    imprimeListaDupla(&aux->item.paradas);

    cout << "\n Codigo da parada que deseja remover: ";
    cin >> id;

    ApontadorDupla aux1 = localizaIDDupla(&aux->item.paradas, id);

    if (aux1 == NULL)
    {
        cout << "\n Não contem parada nessa linha!" << endl;
        return;
    }

    retiraIDDupla(&aux->item.paradas, id);
    cout << "\n Parada removida da linha!" << endl << endl;
}

void excluirLinha(tipoLista *linhas)
{
    int id;

    cout << "\n Informe o codigo da linha: ";
    cin >> id;

    Apontador aux;
    aux = pesquisaItem(linhas, id);

    if (aux == NULL)
    {
        cout << "\n Essa linha não existe no nosso registro!" << endl;
        return;
    }

    removeItemPorId(linhas, id);
    cout << "\n Linha removida com sucesso!" << endl;
}

void alteracaoCompleta(tipoLista *linhas, int *id)
{
    int op;

    while(op != 6){
        cout << "\n 1 - Inserir uma nova linha" << endl;
        cout << " 2 - Inserir uma nova parada na linha" << endl;
        cout << " 3 - Altere uma parada" << endl;
        cout << " 4 - Elimine uma parada" << endl;
        cout << " 5 - Elimine uma linha" << endl;
        cout << " 6 - Voltar" << endl;
        cout << "\n Digite oque deseja fazer: ";
        cin >> op;

        cout << endl << endl;

        switch (op)
        {
            case 1:
                system("cls");
                criarLinha(linhas, id);
                break;

            case 2:
                system("cls");
                criarParada(linhas);
                break;

            case 3:
                system("cls");
                mudarParada(linhas);
                break;

            case 4:
                system("cls");
                excluirParada(linhas);
                break;

            case 5:
                system("cls");
                excluirLinha(linhas);
                break;

            default:
                break;
        }
        system("cls");
    }
}