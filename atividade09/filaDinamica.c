#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

typedef struct TNo{
    int dado;
    struct TNo *proximo;
}TNo;

/*=========================================================
    Função para inicializar a fila
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void inicializarFila(TFila * const fila){
    fila->tamanho = 0;
    fila->inicio = NULL;
    fila->fim = NULL;
}

/*=========================================================
    Função para verificar se a fila está vazia
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
    Retorno:
        != 0   - fila está vazia
        0      - fila não está vazia
  =========================================================*/
int filaestaVazia(TFila const * const fila){
    if(fila->tamanho == 0){
        return 1;
    }
    return 0;
}

/*=========================================================
    Função para inserir um elemento na fila
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
        2 - elemento - valor a ser inserido na fila
  =========================================================*/
void enfileirar(TFila * const fila, int elemento){
    TNo *aux = malloc(sizeof(TNo));
    if(aux == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    aux->dado = elemento;
    aux->proximo = NULL;

    if(filaestaVazia(fila)){
    fila->tamanho++;
    fila->inicio = aux;
    fila->fim = aux;
    return;
    }

    fila->fim->proximo = aux;
    fila->fim = aux;
    fila->tamanho++;
}

/*=========================================================
    Função para acessar o primeiro elemento da fila
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
    Retorno:
        elemento do início da fila
  =========================================================*/
int acessarInicio(TFila const * const fila){
    if(filaestaVazia(fila)){
        printf("Fila esta vazia!\n");
        return -1;
    }
    return fila->inicio->dado;
}

/*=========================================================
    Função para remover um elemento da fila
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void desenfileirar(TFila * const fila){}

/*=========================================================
    Função para acessar o primeiro elemento da fila
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
    Retorno:
        elemento do início da fila
  =========================================================*/
int acessarInicio(TFila const * const fila){}

/*=========================================================
    Função para mostrar os elementos da fila
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void mostrarFila(TFila const * const fila){}

/*=========================================================
    Função para liberar toda memória utilizada pela fila
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void liberarFila(TFila * const fila){}