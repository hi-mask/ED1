#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"
#include "tratamento.h"

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
void enfileirar(TFila * const fila, TAluno const * const aluno){
    TNo *aux = malloc(sizeof(TNo));
    if(aux == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    aux->aluno = *aluno;
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
void acessarInicio(TFila const * const fila){
    if(filaestaVazia(fila)){
        printf("Fila esta vazia!\n");
        return;
    }

    printf("\nPrimeiro aluno:\n");
    printf("Matricula: %s\n",
    fila->inicio->aluno.numMatricula);
    printf("Nome: %s\n",
    fila->inicio->aluno.nome);
                
}

/*=========================================================
    Função para remover um elemento da fila
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void desenfileirar(TFila * const fila){
     if(filaestaVazia(fila)){
        printf("Fila esta vazia!\n");
        return;
    }
    TNo *aux = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    free(aux);
    fila->tamanho--;
    if(fila->inicio == NULL){
        fila->fim = NULL;
    }
    printf("O elemento do inicio da fila saiu!\n");
}

/*=========================================================
    Função para mostrar os elementos da fila
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void mostrarFila(TFila const * const fila){
    printf("Fila = [ ");
    if(filaestaVazia(fila)){
        printf(" ]\n");
        return;
    }
    TNo *aux = fila->inicio;
    while(aux != NULL){
        if(aux->proximo == NULL){
            printf("%d ", aux->dado);
        }
        else{
            printf("%d, ", aux->dado);
        }
        aux = aux->proximo;
    }
    printf("]\n");
}

/*=========================================================
    Função para liberar toda memória utilizada pela fila
    Parametros: 
        1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void liberarFila(TFila * const fila){
    TNo *aux;
    while(fila->inicio != NULL){
        aux = fila->inicio;
        fila->inicio = fila->inicio->proximo;
        free(aux);
    }
    fila->fim = NULL;
    fila->tamanho = 0;
}