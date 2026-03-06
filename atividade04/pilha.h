#ifndef PILHA_H
#define PILHA_H

typedef struct {
    int topo;
    int tamanho;
    int *array;
}TPilha;


/* Funções necessárias */

/*======================================================
    Função que cria a pilha e inicializa o vetor pilha.
    Parâmetros:
    1 - tamanho: Varíavel que passa o tamanho da pilha
    2 - pilha: ponteiro que aponta para a struct do tipo TPilha 
======================================================*/
void criarPilha(int tamanho, TPilha *const pilha);

/*======================================================
    Função que verifica se a pilha está cheia
    Parâmetros:
    1 - pilha: ponteiro que aponta para a struct do tipo TPilha 
    Retornos: - 1: a pilha está cheia - 0: a pilha não está cheia
======================================================*/
int verificarPilhaCheia(TPilha const * const pilha);

/*======================================================
    Função que verifica se a pilha está vazia
    Parâmetros:
    1 - pilha: ponteiro que aponta para a struct do tipo TPilha 
    Retornos: - 1: a pilha está vazia - 0: a pilha não está vazia
======================================================*/
int verificarPilhaVazia(TPilha const * const pilha);

/*======================================================
    Função que limpa o vetor da pilha e redefine topo e tamanho
    Parâmetros:
    1 - pilha: ponteiro que aponta para a struct do tipo TPilha 
======================================================*/
void liberarPilha(TPilha * const pilha);

/*======================================================
    Função que acessa o topo da pilha
    Parâmetros:
    1 - pilha: ponteiro que aponta para a struct do tipo TPilha 
======================================================*/
int acessarPilha(TPilha const * const pilha);

/*======================================================
    Função que insere um elemento no topo da pilha
    Parâmetros:
    1 - elemento: numero inteiro a ser inserido no topo da pilha
    2 - pilha: ponteiro que aponta para a struct do tipo TPilha 
======================================================*/
void empilhar(int elemento, TPilha * const pilha);

/*======================================================
    Função que remove o ultimo elemento inserido na pilha
    Parâmetros:
    1 - pilha: ponteiro que aponta para a struct do tipo TPilha 
======================================================*/
void desempilhar(TPilha * const pilha);

/*======================================================
    Função que exibe os dados da pilha
    Parâmetros:
    1 - pilha: ponteiro que aponta para a struct do tipo TPilha 
======================================================*/
void exibirPilha(TPilha const * const pilha);

#endif

