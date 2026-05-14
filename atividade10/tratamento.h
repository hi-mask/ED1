#ifndef TRATAMENTO_H
#define TRATAMENTO_H
#include "filaDinamica.h"
#include <stdio.h>

typedef struct{
    char numMatricula[15];
    char nome[60];
}TAluno;

int verificarAberturaArquivo(FILE *arq);

void carregarArquivoNaFila(TFila * const fila, char nomeArquivo[]);

#endif