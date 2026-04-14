#ifndef PILHA_H
#define PILHA_H

typedef struct {
    int *array;
    int topo;
    int capacidade;

}TPilha;

void criarPilha(TPilha * const pilha, int capacidade);

void liberarPilha(TPilha * const pilha);

void exibirDadosPilha(TPilha const * const pilha);

int pilhaVazia(TPilha const * const pilha);

int pilhaCheia(TPilha const * const pilha);

int acessarPilha(TPilha const * const pilha);

void empilhar(TPilha * const pilha, int elemento);

void desempilhar(TPilha * const pilha);


#endif


