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
        1 - lista         - ponteiro para a struct da lista
        2 - nomeArquivo  - nome do arquivo a ser lido
  =========================================================*/
void carregarArquivoNaLista(TLLDE * const lista, char nomeArquivo[]);

/*=========================================================
    Função para salvar todos os alunos da lista em um arquivo
    Parametros:
        1 - lista - ponteiro para a lista a ser salva
        2 - nomeArquivo - nome do arquivo de destino
  =========================================================*/
void salvarListaNoArquivo(TLLDE const * const lista, char nomeArquivo[]);
#endif