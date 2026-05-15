
#ifndef FILADINAMICA_H
#define FILADINAMICA_H
#include "aluno.h"

typedef struct TNo{
    TAluno aluno;
    struct TNo *proximo;
}TNo;


typedef struct{
    int tamanho;
    TNo *inicio;
    TNo *fim;
}TFila;

/*=========================================================
    Função para inicializar a fila
    Parametros:
        1 - fila - ponteiro para a struct da fila
  =========================================================*/
void inicializarFila(TFila * const fila);

/*=========================================================
    Função para verificar se a fila está vazia
    Parametros:
        1 - fila - ponteiro para a struct da fila
    Retorno:
        != 0   - fila está vazia
        0      - fila não está vazia
  =========================================================*/
int filaestaVazia(TFila const * const fila);

/*=========================================================
    Função para inserir um aluno no final da fila
    Parametros:
        1 - fila  - ponteiro para a struct da fila
        2 - aluno - ponteiro para o aluno a ser inserido
  =========================================================*/
void enfileirar(TFila * const fila, TAluno const * const aluno);

/*=========================================================
    Função para remover o primeiro elemento da fila
    Parametros:
        1 - fila - ponteiro para a struct da fila
  =========================================================*/
void desenfileirar(TFila * const fila);


/*=========================================================
    Função para acessar o primeiro elemento da fila
    Parametros:
        1 - fila - ponteiro para a struct da fila
  =========================================================*/
void acessarInicio(TFila const * const fila);

/*=========================================================
    Função para mostrar todos os elementos da fila
    Parametros:
        1 - fila - ponteiro para a struct da fila
  =========================================================*/
void mostrarFila(TFila const * const fila);

/*=========================================================
    Função para liberar toda memória utilizada pela fila
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void liberarFila(TFila * const fila);

#endif