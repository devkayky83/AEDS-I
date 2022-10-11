#ifndef PILHA-TP2_H
#define PILHA-TP2_H

#define MAXTAM 10
#define MAX_ENTREGA 7
#define PRODUTOSMAX 8

typedef struct Pedido{
    int codigo;
    int produtos[MAXTAM];
    int tamanho;
    double valor_total_pedido;
    double distancia;
};

typedef struct PilhaEntrega{
     int tamanho;
    Pedido itens[MAX_ENTREGA];
};

#endif