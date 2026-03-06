#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/*======================================================
    Função que cria a pilha e inicializa o vetor pilha.
    Parâmetros:
    1 - tamanho: Varíavel que passa o tamanho da pilha
    2 - pilha: ponteiro que aponta para a struct do tipo TPilha 
======================================================*/
void criarPilha(int tamanho, TPilha *const pilha){
    // o topo foi inicializado em -1, para indicar que ainda não há elementos
    pilha->topo = -1;
    // O campo tamanho da struct é inicializado
    pilha->tamanho = tamanho;
    // alocação dinâmica do array do tipo int com tamanho recebido
    pilha->array = malloc(tamanho * sizeof(int));

}

/*======================================================
    Função que verifica se a pilha está cheia
    Parâmetros:
    1 - pilha: ponteiro que aponta para a struct do tipo TPilha 
    Retornos: - 1: a pilha está cheia - 0: a pilha não está cheia
======================================================*/
int verificarPilhaCheia(TPilha const * const pilha){
    if(pilha->topo == pilha->tamanho - 1) return 1;
    return 0;
}

/*======================================================
    Função que verifica se a pilha está vazia
    Parâmetros:
    1 - pilha: ponteiro que aponta para a struct do tipo TPilha 
    Retornos: - 1: a pilha está vazia - 0: a pilha não está vazia
======================================================*/
int verificarPilhaVazia(TPilha const * const pilha){
    if(pilha->topo == -1) return 1;
    return 0;
}
/*======================================================
    Função que limpa o vetor da pilha e redefine topo e tamanho
    Parâmetros:
    1 - pilha: ponteiro que aponta para a struct do tipo TPilha 
======================================================*/
void liberarPilha(TPilha * const pilha){
    free(pilha->array);
    pilha->tamanho = 0;
    pilha->topo = -1;
    pilha->array = NULL;
}
/*======================================================
    Função que acessa o topo da pilha
    Parâmetros:
    1 - pilha: ponteiro que aponta para a struct do tipo TPilha 
======================================================*/
int acessarPilha(TPilha const * const pilha){
    if(verificarPilhaVazia(pilha)) return -1;

    return pilha->array[pilha->topo];
}

/*======================================================
    Função que insere um elemento no topo da pilha
    Parâmetros:
    1 - elemento: numero inteiro a ser inserido no topo da pilha
    2 - pilha: ponteiro que aponta para a struct do tipo TPilha 
======================================================*/
void empilhar(int elemento, TPilha * const pilha){
    if(verificarPilhaCheia(pilha)) return;

    pilha->topo++; // aumentei o tamanho em +1
    pilha->array[pilha->topo] = elemento; // elemento inserido no novo espaço

}

/*======================================================
    Função que remove o ultimo elemento inserido na pilha
    Parâmetros:
    1 - pilha: ponteiro que aponta para a struct do tipo TPilha 
======================================================*/
void desempilhar(TPilha * const pilha){
    if(verificarPilhaVazia(pilha)) return;

    pilha->topo--;
}

/*======================================================
    Função que exibe os dados da pilha
    Parâmetros:
    1 - pilha: ponteiro que aponta para a struct do tipo TPilha 
======================================================*/
void exibirPilha(TPilha const * const pilha){
  printf("\tDADOS DA PILHA\t\n");
  printf("Tamanho: %d\n", pilha->tamanho);
  printf("Topo: %d\n", pilha->topo);
  printf("Array da pilha: %p\n", pilha->array);
  printf("Pilha: {");
  if(verificarPilhaVazia(pilha)) printf(" }\n");
  else{
    int *pA = pilha->array;
    for( int i = 0; i <= pilha->topo; i++ ){
      printf(" %d", *pA);
      pA++;
    }
    printf(" }\n");
  }
}