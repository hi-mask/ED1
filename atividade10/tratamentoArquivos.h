#ifndef TRATAMENTO_H
#define TRATAMENTO_H
#include "filaDinamica.h"
#include <stdio.h>

/*=========================================================
    Função para verificar se o arquivo foi aberto corretamente
    Parametros:
        1 - arquivo - ponteiro para o arquivo
    Retorno:
        1   - erro ao abrir o arquivo
        != 0      - arquivo aberto com sucesso
  =========================================================*/
int verificarAberturaArquivo(FILE *arq);

/*=========================================================
    Função para carregar os dados do arquivo na fila
    Parametros:
        1 - fila         - ponteiro para a struct da fila
        2 - nomeArquivo  - nome do arquivo a ser lido
  =========================================================*/
void carregarArquivoNaFila(TFila * const fila, char nomeArquivo[]);

#endif