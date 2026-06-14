#ifndef LISTADUPLAMENTEENCADEADA_H
#define LISTADUPLAMENTEENCADEADA_H

typedef struct TNo{
    int dado;
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
void inicializarNo(TNo * const no, int dado);

/*=========================================================
    Função para inicializar a lista simplesmente encadeada
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
        do inicio p fim ou do fim p inicio
  =========================================================*/
void mostrarLista(TLLDE const * const lista, int direcao);

/*=========================================================
    Função para inserir um elemento no início da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - elemento - valor a ser inserido
  =========================================================*/
void inserirNoInicioDaLLDE(TLLDE * const lista, int elemento);

/*=========================================================
    Função para acessar o primeiro elemento da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
    Retorno:
        valor armazenado no início da lista
  =========================================================*/
int acessarInicioDaLLDE(TLLDE const * const lista);

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
        2 - elemento - valor a ser inserido
  =========================================================*/
void inserirNoFimDaLLDE(TLLDE * const lista, int elemento);

/*=========================================================
    Função para acessar o último elemento da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
    Retorno:
        valor armazenado no início da lista
  =========================================================*/
int acessarFimDaLLDE(TLLDE const * const lista);

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
        3 - elemento - valor a ser inserido
  =========================================================*/
void inserirPosicao(TLLDE * const lista, int pos, int elemento);

/*=========================================================
    Função para acessar o elemento em uma posição da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - pos - posição desejada
    Retorno:
        valor armazenado na posição informada
        -1 se for inválido
  =========================================================*/
int acessarPosicao(TLLDE const * const lista, int pos);

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
#endif