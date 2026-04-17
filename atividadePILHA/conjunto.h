#ifndef CONJUNTO_H
#define CONJUNTO_H

typedef struct{
    int capacidade;
    int *array;
}SET;

/*=========================================================
    Função para ler o tamanho do conjunto
    Retorno:
        valor inteiro correspondente ao tamanho informado
  =========================================================*/
int lerTamanho();

/*=========================================================
    Função para criar um conjunto com valores aleatórios
    Parametros:
        1 - conjA - ponteiro para a struct do conjunto
  =========================================================*/
void criarConjunto(SET * const conjA);

/*=========================================================
    Função para exibir os elementos do conjunto
    Parametros:
        1 - conjA - ponteiro para a struct do conjunto
  =========================================================*/
void exibirConjunto(SET const * const conjA);

#endif