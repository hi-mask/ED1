#include <stdio.h>
#include <stdlib.h>
#include "listaDinamica.h"

/*=========================================================
    Função para inicializar um nó da lista
    Parametros:
        1 - no - ponteiro para o nó a ser inicializado
        2 - dado - valor que será armazenado no nó
  =========================================================*/
void inicializarNo(TNo * const no, int dado){
    no->dado = dado;
    no->proximo = NULL;
}

/*=========================================================
    Função para inicializar a lista simplesmente encadeada
    Parametros:
        1 - lista - ponteiro para a struct da lista
  =========================================================*/
void inicializarLista(TLLSE * const lista){
    lista->tamanho = 0;
    lista->inicio = NULL;
    lista->fim = NULL;
}

/*=========================================================
    Função para verificar se a lista está vazia
    Parametros:
        1 - lista - ponteiro para a struct da lista
    Retorno:
        != 0   - lista está vazia
        0      - lista não está vazia
  =========================================================*/
int llseEstaVazia(TLLSE const * const lista){
    return(lista->tamanho == 0);
}

/*=========================================================
    Função para inserir um elemento no início da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - elemento - valor a ser inserido
  =========================================================*/
void inserirNoInicioDaLLSE(TLLSE * const lista, int elemento){
    TNo * pAux = malloc(sizeof(TNo));
    verificarMalloc(pAux);

    inicializarNo(pAux, elemento);

    if(llseEstaVazia(lista)){
        lista->inicio = pAux;
        lista->fim = pAux;
        lista->tamanho++;
        return;
    }

    // lista->inicio aponta para o nó criado anteriormente
    pAux->proximo = lista->inicio;
    lista->inicio = pAux;
    lista->tamanho++;
}

/*=========================================================
    Função para acessar o primeiro elemento da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
    Retorno:
        valor armazenado no início da lista
  =========================================================*/
int acessarInicioDaLLSE(TLLSE const * const lista){
    if(llseEstaVazia(lista)){
        printf("A lista esta vazia!\n");
        return -1;
    }
    return lista->inicio->dado;
}

/*=========================================================
    Função para remover o primeiro nó da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
  =========================================================*/
void RetirarNoInicioDaLLSE(TLLSE * const lista){
    if(llseEstaVazia(lista)){
        printf("\nLista esta vazia!\n");
        return;
    }

    TNo * pAux = malloc(sizeof(TNo));
    verificarMalloc(pAux);

    pAux = lista->inicio;
    lista->inicio = pAux->proximo;
    free(pAux);
    lista->tamanho--;

    if(llseEstaVazia(lista)){
        printf("Lista ficou vazia!\n");
        lista->fim = NULL;
        return;
    }

    printf("\nO elemento do inicio da lista saiu!\n");

}

/*=========================================================
    Função para inserir um elemento no fim da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - elemento - valor a ser inserido
  =========================================================*/
void inserirNoFimDaLLSE(TLLSE * const lista, int elemento){
    TNo * pAux = malloc(sizeof(TNo));
    verificarMalloc(pAux);
    
    inicializarNo(pAux, elemento);

    if(llseEstaVazia(lista)){
        lista->inicio = pAux;
        lista->fim = pAux;
        lista->tamanho++;
        return;
    }
    
    lista->fim->proximo = pAux;
    lista->fim = pAux;
    lista->tamanho++;

}

/*=========================================================
    Função para acessar o último elemento da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
    Retorno:
        valor armazenado no início da lista
  =========================================================*/
int acessarFimDaLLSE(TLLSE const * const lista){
    if(llseEstaVazia(lista)){
        printf("A lista esta vazia!\n");
        return -1;
    }
    
    return lista->fim->dado;
}

/*=========================================================
    Função para remover o último nó da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
  =========================================================*/
void RetirarNoFimDaLLSE(TLLSE * const lista){
    if(llseEstaVazia(lista)){
        printf("A lista esta vazia!\n");
        return;
    }

    if(lista->inicio->proximo == NULL){
        free(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho--;
        return;
    }

    TNo * pAux = malloc(sizeof(TNo));
    verificarMalloc(pAux);

    pAux = lista->inicio;
    while(pAux->proximo != lista->fim){
        pAux = pAux->proximo;
    }

    free(lista->fim);
    pAux->proximo = NULL;
    lista->fim = pAux;
    lista->tamanho--;
    printf("\nO elemento do fim da lista saiu!\n");
    
}

/*=========================================================
    Função para mostrar lista completa
    Parametros:
        1 - lista - ponteiro para a struct da lista
  =========================================================*/
void mostrarLista(TLLSE const * const lista){
    if(llseEstaVazia(lista)){
        printf("\nLista = [ ]\n");
        return;
    }

    TNo * pAux = malloc(sizeof(TNo));
    verificarMalloc(pAux);

    pAux = lista->inicio;
    printf("\nLista = [ ");
    while(pAux != NULL){
        printf("%d", pAux->dado);
        if(pAux->proximo != NULL){
            printf(" | ");
        }

    pAux = pAux->proximo;
    }
    printf(" ]\n");

    printf("Total de elementos na lista: %d\n", lista->tamanho);
}

/*=========================================================
    Função para inserir um elemento em uma posição da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - pos - posição onde o elemento será inserido
        3 - elemento - valor a ser inserido
  =========================================================*/
void inserirPosicao(TLLSE * const lista, int pos, int elemento){
    if(pos < 0 || pos > lista->tamanho){
        printf("\nPosicao Invalida!\n");
        return;
    }

    if(pos == 0){
        inserirNoInicioDaLLSE(lista, elemento);
        return;
    }
    if(pos == lista->tamanho){
        inserirNoFimDaLLSE(lista, elemento);
        return;
    }

    TNo * pAuxElemento = malloc(sizeof(TNo));
    verificarMalloc(pAuxElemento);

    inicializarNo(pAuxElemento, elemento);

    TNo * pAuxAndarilho = malloc(sizeof(TNo));
    verificarMalloc(pAuxAndarilho);

    pAuxAndarilho = lista->inicio;

    int i = 0;
    while(i < pos - 1){
        pAuxAndarilho = pAuxAndarilho->proximo;
        i++;
    }

    pAuxElemento->proximo = pAuxAndarilho->proximo;
    pAuxAndarilho->proximo = pAuxElemento;

    lista->tamanho++;
    
}

/*=========================================================
    Função para acessar o elemento em uma posição da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - pos - posição desejada
    Retorno:
        valor armazenado na posição informada
        -1 se for inválido
  =========================================================*/
int acessarPosicao(TLLSE const * const lista, int pos){
    if(llseEstaVazia(lista)){
        printf("\nLista vazia!\n");
        return -1;
    }
    if(pos < 0 || pos >= lista->tamanho){
        printf("\nPosicao Invalida!\n");
        return -1;
    }
    if(pos == 0){
        return acessarInicioDaLLSE(lista);
    }
    if(pos == lista->tamanho-1){
        return acessarFimDaLLSE(lista);
    }

    TNo * pAuxAndarilho = malloc(sizeof(TNo));
    verificarMalloc(pAuxAndarilho);

    pAuxAndarilho = lista->inicio;

    int i = 0;
    while(i < pos){
        pAuxAndarilho = pAuxAndarilho->proximo;
        i++;
    }

    return pAuxAndarilho->dado;
}

/*=========================================================
    Função para remover o nó na posicao solicitada da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - pos - posição desejada
  =========================================================*/
void retirarPosicao(TLLSE * const lista, int pos){
    if(llseEstaVazia(lista)){
        printf("\nLista vazia!\n");
        return;
    }
    if(pos < 0 || pos >= lista->tamanho){
        printf("\nPosicao Invalida!\n");
        return;
    }
    if(pos == 0){
        RetirarNoInicioDaLLSE(lista);
        return;
    }
    if(pos == lista->tamanho-1){
        RetirarNoFimDaLLSE(lista);
        return;
    }

    TNo * pAuxAndarilho = malloc(sizeof(TNo));
    verificarMalloc(pAuxAndarilho);

    pAuxAndarilho = lista->inicio;

    int i = 0;
    while(i < pos - 1){
        pAuxAndarilho = pAuxAndarilho->proximo;
        i++;
    }

    TNo * pAuxTemp = malloc(sizeof(TNo));
    verificarMalloc(pAuxTemp);

    pAuxTemp = pAuxAndarilho->proximo;
    pAuxAndarilho->proximo = pAuxTemp->proximo;
    free(pAuxTemp);
    lista->tamanho--;
}

/*=========================================================
    Função para verificar se a alocação dinâmica ocorreu
    corretamente
    Parametros:
        1 - no - ponteiro retornado pela alocação dinâmica
  =========================================================*/
void verificarMalloc(TNo const * const no){
    if(no == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
}