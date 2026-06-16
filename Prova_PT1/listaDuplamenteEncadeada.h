#ifndef LISTADUPLAMENTEENCADEADA_H
#define LISTADUPLAMENTEENCADEADA_H
#include "aluno.h"

typedef struct TNo{
    TAluno *atual;
    struct TNo *proximo;
    struct TNo *anterior;
}TNo;

typedef struct{
    int tamanho;
    TNo *inicio;
    TNo *fim;
}TLLDE;

/*=========================================================
    Função para inicializar um nó da lista
    Parametros:
        1 - no - ponteiro para o nó a ser inicializado
        2 - dado - valor que será armazenado no nó
  =========================================================*/
void inicializarNo(TNo * const no, TAluno * const aluno);

/*=========================================================
    Função para inicializar a lista duplamente encadeada
    Parametros:
        1 - lista - ponteiro para a struct da lista
  =========================================================*/
void inicializarLLDE(TLLDE * const lista);

/*=========================================================
    Função para verificar se a lista está vazia
    Parametros:
        1 - lista - ponteiro para a struct da lista
    Retorno:
        != 0   - lista está vazia
        0      - lista não está vazia
  =========================================================*/
int LLDEEstaVazia(TLLDE const * const lista);

/*=========================================================
    Função para mostrar lista completa
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - direcao - direcao na qual a lista sera mostrada
        direção == 1: inicio->fim | direção == 0: fim->inicio)
  =========================================================*/
void mostrarLista(TLLDE const * const lista, int direcao);

/*=========================================================
    Função para inserir um elemento no início da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - aluno - ponteiro para o aluno a ser inserido
  =========================================================*/
void inserirNoInicioDaLLDE(TLLDE * const lista, TAluno * const aluno);

/*=========================================================
    Função para acessar o primeiro elemento da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
    Retorno:
        Ponteiro para o aluno armazenado no início da lista
  =========================================================*/
TAluno * acessarInicioDaLLDE(TLLDE const * const lista);

/*=========================================================
    Função para remover o primeiro nó da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
  =========================================================*/
void RetirarNoInicioDaLLDE(TLLDE * const lista);

/*=========================================================
    Função para inserir um elemento no fim da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - aluno - ponteiro para o aluno a ser inserido
  =========================================================*/
void inserirNoFimDaLLDE(TLLDE * const lista, TAluno * const aluno);

/*=========================================================
    Função para acessar o último elemento da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
    Retorno:
        Ponteiro para o aluno armazenado no fim da lista
  =========================================================*/
TAluno * acessarFimDaLLDE(TLLDE const * const lista);

/*=========================================================
    Função para remover o último nó da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
  =========================================================*/
void RetirarNoFimDaLLDE(TLLDE * const lista);

/*=========================================================
    Função para inserir um elemento em uma posição da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - pos - posição onde o elemento será inserido
        3 - aluno - ponteiro para o aluno a ser inserido
  =========================================================*/
void inserirPosicao(TLLDE * const lista, int pos, TAluno * const aluno);

/*=========================================================
    Função para acessar o elemento em uma posição da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - pos - posição desejada
    Retorno:
        - Ponteiro para o aluno armazenado na posição informada
        - NULL caso a posição seja inválida
  =========================================================*/
TAluno * acessarPosicao(TLLDE const * const lista, int pos);

/*=========================================================
    Função para remover o nó na posicao solicitada da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - pos - posição desejada
  =========================================================*/
void retirarPosicao(TLLDE * const lista, int pos);

/*=========================================================
    Função para verificar se a alocação dinâmica ocorreu
    corretamente
    Parametros:
        1 - no - ponteiro retornado pela alocação dinâmica
  =========================================================*/
void verificarMalloc(TNo const * const no);

/*=========================================================
    Função para percorrer a lista a partir do início até
    a posição desejada
    Parametros:
        1 - no - ponteiro para o nó inicial da busca
        2 - pos - posição desejada
    Retorno:
        Ponteiro para o nó imediatamente anterior à posição
        desejada
  =========================================================*/
TNo * andarDoInicioAtePosicao(TNo *no, int pos);

/*=========================================================
    Função para percorrer a lista a partir do fim até
    a posição desejada
    Parametros:
        1 - no - ponteiro para o último nó da lista
        2 - pos - posição desejada
        3 - tamanho - quantidade de elementos da lista
    Retorno:
        Ponteiro para o nó imediatamente anterior à posição
        desejada
  =========================================================*/
TNo * andarDoFimAtePosicao(TNo *no, int pos, int tamanho);

/*=========================================================
    Função para liberar toda memória utilizada pela lista
    Parametros: 
        1 - lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void liberarLista(TLLDE * const lista);

/*=========================================================
    Função para exibir os dados do aluno armazenado em um nó
    Parâmetros:
        1 - no - ponteiro para o nó que contém o aluno
  =========================================================*/
void exibirAluno(TNo const * const no);

/*=========================================================
    Função para verificar se o usuário deseja continuar
    exibindo os elementos da lista
    Retorno:
        != 0 - continua a exibir
        0 - interrompe a exibição
  =========================================================*/
int continuarExibindo();

/*=========================================================
    Função para receber os dados de um aluno pelo teclado
    Parametros:
        Nenhum
    Retorno:
        Ponteiro para a struct TAluno preenchida com os
        dados informados pelo usuário
  =========================================================*/
TAluno * receberDadosDoTeclado();

#endif