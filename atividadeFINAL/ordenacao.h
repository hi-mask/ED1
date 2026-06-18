#ifndef ORDENACAO_H
#define ORDENACAO_H

#include "listaDuplamenteEncadeada.h"

/*=========================================================
    Função para exibir o menu de ordenação da lista
    Parametros:
        1 - lista - ponteiro para a lista de alunos
        2 - nomeArquivo - nome do arquivo utilizado para
            salvar as alterações realizadas
  =========================================================*/
void exibirMenuOrdenacao(TLLDE * const lista, char nomeArquivo[]);

/*=========================================================
    Função para trocar os ponteiros para os alunos
    armazenados em dois nós da lista
    Parametros:
        1 - no1 - ponteiro para o primeiro nó
        2 - no2 - ponteiro para o segundo nó
  =========================================================*/
void trocarAlunos(TNo *no1, TNo *no2);

/*=========================================================
    Função para ordenar a lista pelo número de matrícula
    dos estudantes
    Parametros:
        1 - lista - ponteiro para a lista a ser ordenada
  =========================================================*/
void ordenarPorMatricula(TLLDE * const lista);

/*=========================================================
    Função para ordenar a lista pelo nome dos estudantes
    em ordem alfabética
    Parametros:
        1 - lista - ponteiro para a lista a ser ordenada
    Retorno:
        Nenhum
  =========================================================*/
void ordenarPorNome(TLLDE * const lista);

/*=========================================================
    Função para ordenar a lista pelo curso e, em caso de
    empate, pelo nome dos estudantes
    Parametros:
        1 - lista - ponteiro para a lista a ser ordenada
  =========================================================*/
void ordenarPorCursoNome(TLLDE * const lista);

/*=========================================================
    Função para ordenar a lista pela ênfase e, em caso de
    empate, pelo nome dos estudantes
    Parametros:
        1 - lista - ponteiro para a lista a ser ordenada
    Retorno:
        Nenhum
  =========================================================*/
void ordenarPorEnfaseNome(TLLDE * const lista);

int desejaExibirALista();

#endif