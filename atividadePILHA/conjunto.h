#ifndef CONJUNTO_H
#define CONJUNTO_H

typedef struct{
    int capacidade;
    int *array;
}SET;

int lerTamanho();

void criarConjunto(SET * const conjA);

void exibirConjunto(SET const * const conjA);

#endif