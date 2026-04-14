#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int *array;
    int ocupacao;
    int capacidade;
}TLista;

void inicializarLista(TLista * const lista, int tamanho);

void liberarLista(TLista * const lista);

void exibirDadosLista(TLista const * const lista);

int listaEstaVazia(TLista const * const lista);

int listaEstaCheia(TLista const * const lista);

void mostrarLista(TLista const * const lista);

void inserirFimLista(TLista * const lista, int elemento);

int acessarFimLista(TLista const * const lista);

void retirarFimLista(TLista * const lista);

void inserirInicioLista(TLista * const lista, int elemento);

int acessarInicioLista(TLista const * const lista);

void retirarInicioLista(TLista * const lista);

void inserirPosicaoLista(TLista * const lista, int elemento, int posicao);

int acessarPosicaoLista(TLista const * const lista, int posicao);

void retirarPosicaoLista(TLista * const lista, int posicao);

#endif