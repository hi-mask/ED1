
#ifndef FILADINAMICA_H
#define FILADINAMICA_H

typedef struct TNo{
    int dado;
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
        1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void inicializarFila(TFila * const fila);

/*=========================================================
    Função para verificar se a fila está vazia
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
    Retorno:
        != 0   - fila está vazia
        0      - fila não está vazia
  =========================================================*/
int filaestaVazia(TFila const * const fila);

/*=========================================================
    Função para inserir um elemento na fila
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
        2 - elemento - valor a ser inserido na fila
  =========================================================*/
void enfileirar(TFila * const fila, int elemento);

/*=========================================================
    Função para remover um elemento da fila
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void desenfileirar(TFila * const fila);

/*=========================================================
    Função para acessar o primeiro elemento da fila
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
    Retorno:
        elemento do início da fila
  =========================================================*/
int acessarInicio(TFila const * const fila);

/*=========================================================
    Função para mostrar os elementos da fila
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void mostrarFila(TFila const * const fila);

/*=========================================================
    Função para liberar toda memória utilizada pela fila
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void liberarFila(TFila * const fila);
#endif