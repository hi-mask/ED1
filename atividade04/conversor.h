#ifndef CONVERSOR_H
#define CONVERSOR_H

#include "pilha.h"

/* Funções necessárias */

/*======================================================
    Função que realiza o processo de conversão para base N e guarda em uma pilha
    Parâmetros:
    1 - dividendo: variavel que guarda o numero decimal a ser convertido
    2 - n: variavel que guarda a base desejada para a conversão
    3 - pilha: ponteiro que aponta para a struct do tipo TPilha 
======================================================*/
void converterBaseDesejada(int dividendo, int n, TPilha * const pilha);

/*======================================================
    Função que exibe a conversão por meio de desempilhamentos consecutivos
    Parâmetros:
    1 - pilha: ponteiro que aponta para a struct do tipo TPilha 
======================================================*/
void exibirNumerosConvertidos(TPilha * const pilha);

#endif