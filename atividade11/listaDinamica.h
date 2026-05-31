#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H

typedef struct TNo{
    int dado;
    struct TNo *proximo;
}TNo;

typedef struct{
    int tamanho;
    TNo *inicio;
    TNo *fim;
}TLLSE;

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
void inicializarLista(TLLSE * const lista);

/*=========================================================
    Função para verificar se a lista está vazia
    Parametros:
        1 - lista - ponteiro para a struct da lista
    Retorno:
        != 0   - lista está vazia
        0      - lista não está vazia
  =========================================================*/
int llseEstaVazia(TLLSE const * const lista);

/*=========================================================
    Função para inserir um elemento no início da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - elemento - valor a ser inserido
  =========================================================*/
void inserirNoInicioDaLLSE(TLLSE * const lista, int elemento);

/*=========================================================
    Função para acessar o primeiro elemento da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
    Retorno:
        valor armazenado no início da lista
  =========================================================*/
int acessarInicioDaLLSE(TLLSE const * const lista);

/*=========================================================
    Função para remover o primeiro nó da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
  =========================================================*/
void RetirarNoInicioDaLLSE(TLLSE * const lista);

/*=========================================================
    Função para inserir um elemento no fim da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - elemento - valor a ser inserido
  =========================================================*/
void inserirNoFimDaLLSE(TLLSE * const lista, int elemento);

/*=========================================================
    Função para acessar o último elemento da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
    Retorno:
        valor armazenado no início da lista
  =========================================================*/
int acessarFimDaLLSE(TLLSE const * const lista);

/*=========================================================
    Função para remover o último nó da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
  =========================================================*/
void RetirarNoFimDaLLSE(TLLSE * const lista);

/*=========================================================
    Função para mostrar lista completa
    Parametros:
        1 - lista - ponteiro para a struct da lista
  =========================================================*/
void mostrarLista(TLLSE const * const lista);

/*=========================================================
    Função para inserir um elemento em uma posição da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - pos - posição onde o elemento será inserido
        3 - elemento - valor a ser inserido
  =========================================================*/
void inserirPosicao(TLLSE * const lista, int pos, int elemento);

/*=========================================================
    Função para acessar o elemento em uma posição da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - pos - posição desejada
    Retorno:
        valor armazenado na posição informada
        -1 se for inválido
  =========================================================*/
int acessarPosicao(TLLSE const * const lista, int pos);

/*=========================================================
    Função para remover o nó na posicao solicitada da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - pos - posição desejada
  =========================================================*/
void retirarPosicao(TLLSE * const lista, int pos);

/*=========================================================
    Função para verificar se a alocação dinâmica ocorreu
    corretamente
    Parametros:
        1 - no - ponteiro retornado pela alocação dinâmica
  =========================================================*/
void verificarMalloc(TNo const * const no);

#endif