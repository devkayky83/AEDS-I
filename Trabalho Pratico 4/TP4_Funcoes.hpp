#include "TP4-ES.cpp"

using namespace std;

void menu();
void viagensLinha(tipoLista *linha, int *id); // Criar as linhas
void encontreLinha(tipoLista *linhas); // Verifica se uma linha existe, pela cidade/codigo
void criarLinha(tipoLista *linhas, int *id); // Responsavel por adicionar uma nova linha
void criarParada(tipoLista *linhas); // Responsavel por adicionar uma parada em uma linha existente
void mudarParada(tipoLista *linhas); // Responsavel por fazer uma edicao de paradas em cada linha
void excluirParada(tipoLista *linhas); // Responsavel por excluir alguma parada que existe em uma linha
void excluirLinha(tipoLista *linhas); // Responsavel por excluir alguma linha que exista
void alteracaoCompleta(tipoLista *linhas, int *id); // Responsavel por incluir todas as funcoes listadas acima, e tambem fazer a logica do programa