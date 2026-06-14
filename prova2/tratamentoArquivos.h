#ifndef TRATAMENTO_H
#define TRATAMENTO_H
#include "listaDuplamenteEncadeada.h"
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
    Função para carregar os dados do arquivo na lista
    Parametros:
        1 - fila         - ponteiro para a struct da lista
        2 - nomeArquivo  - nome do arquivo a ser lido
  =========================================================*/
void carregarArquivoNaLista(TLLDE * const lista, char nomeArquivo[]);

#endif