#ifndef ORDENACAO_H
#define ORDENACAO_H

#include "pilha.h"

/*=========================================================
    Função para ordenar um vetor utilizando pilhas dinâmicas
    Parametros: 
        1 - vetor    - ponteiro para o vetor de inteiros
        2 - tamanho  - quantidade de elementos no vetor
        3 - pilha    - ponteiro para a pilha principal
        4 - pilhaAux - ponteiro para a pilha auxiliar
  =========================================================*/
void ordenarConjunto(int *vetor, int tamanho, TPilha * const pilha, TPilha * const pilhaAux); 
#endif