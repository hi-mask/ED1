#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamenteEncadeada.h"

/*=========================================================
    Função para inicializar um nó da lista
    Parametros:
        1 - no - ponteiro para o nó a ser inicializado
        2 - dado - valor que será armazenado no nó
  =========================================================*/
void inicializarNo(TNo * const no, int dado){
    no->dado = dado;
    no->proximo = NULL;
    no->anterior = NULL;
}

/*=========================================================
    Função para inicializar a lista simplesmente encadeada
    Parametros:
        1 - lista - ponteiro para a struct da lista
  =========================================================*/
void inicializarLLDE(TLLDE * const lista){
    lista->tamanho =  0;
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
int LLDEEstaVazia(TLLDE const * const lista){
    return(lista->tamanho == 0);
}

/*=========================================================
    Função para mostrar lista completa
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - direcao - direcao na qual a lista sera mostrada
        do inicio p fim ou do fim p inicio
  =========================================================*/
void mostrarLista(TLLDE const * const lista, int direcao){
    if(LLDEEstaVazia(lista)){
        printf("\nA lista esta vazia\nLista = [ ]\n");
        return;
    }

    TNo * pAux = malloc(sizeof(TNo));
    verificarMalloc(pAux);

    printf("\nLista = [ ");
    if(direcao){
    pAux = lista->inicio;
        while(pAux != NULL){
            printf("%d", pAux->dado);
            if(pAux->proximo != NULL){
                printf(" | ");
            }

        pAux = pAux->proximo;
        }
    }
    else{
        pAux = lista->fim;
        while(pAux != NULL){
            printf("%d", pAux->dado);
            if(pAux->anterior != NULL){
                printf(" | ");
            }

        pAux = pAux->anterior;
        }
    }
    printf(" ]\n");

    printf("Total de elementos na lista: %d\n", lista->tamanho);
}

/*=========================================================
    Função para inserir um elemento no início da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - elemento - valor a ser inserido
  =========================================================*/
void inserirNoInicioDaLLDE(TLLDE * const lista, int elemento){
    TNo * pAux = malloc(sizeof(TNo));
    verificarMalloc(pAux);

    inicializarNo(pAux, elemento);

    if(LLDEEstaVazia(lista)){
        lista->inicio = pAux;
        lista->fim = pAux;
        lista->tamanho++;
        return;
    }

    pAux->proximo = lista->inicio;
    lista->inicio->anterior = pAux;
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
int acessarInicioDaLLDE(TLLDE const * const lista){
    if(LLDEEstaVazia(lista)){
        printf("\nA lista esta vazia!\n");
        return -1;
    }
    return lista->inicio->dado;
}

/*=========================================================
    Função para remover o primeiro nó da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
  =========================================================*/
void RetirarNoInicioDaLLDE(TLLDE * const lista){
    if(LLDEEstaVazia(lista)){
        printf("\nLista esta vazia!\n");
        return;
    }

    TNo * pAux = malloc(sizeof(TNo));
    verificarMalloc(pAux);

    if(lista->tamanho == 1){
        lista->tamanho = 0;
        free(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;
        printf("\nO elemento do inicio da lista saiu!\n");
        return;
    }

    pAux = lista->inicio;
    lista->inicio = pAux->proximo;
    lista->inicio->anterior = NULL;
    free(pAux);
    lista->tamanho--;

    printf("\nO elemento do inicio da lista saiu!\n");

}

/*=========================================================
    Função para inserir um elemento no fim da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - elemento - valor a ser inserido
  =========================================================*/
void inserirNoFimDaLLDE(TLLDE * const lista, int elemento){
    TNo * pAux = malloc(sizeof(TNo));
    verificarMalloc(pAux);
    
    inicializarNo(pAux, elemento);

    if(LLDEEstaVazia(lista)){
        lista->inicio = pAux;
        lista->fim = pAux;
        lista->tamanho++;
        return;
    }
    
    lista->fim->proximo = pAux;
    pAux->anterior = lista->fim;
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
int acessarFimDaLLDE(TLLDE const * const lista){
    if(LLDEEstaVazia(lista)){
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
void RetirarNoFimDaLLDE(TLLDE * const lista){
    if(LLDEEstaVazia(lista)){
        printf("A lista esta vazia!\n");
        return;
    }

    if(lista->tamanho == 1){
        free(lista->fim);
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho--;
        printf("\nO elemento do fim da lista saiu!\n");
        return;
    }

    TNo * pAux = malloc(sizeof(TNo));
    verificarMalloc(pAux);

    pAux = lista->fim;
    lista->fim = pAux->anterior;

    free(pAux);
    lista->fim->proximo = NULL;
    lista->tamanho--;
    printf("\nO elemento do fim da lista saiu!\n");
}

/*=========================================================
    Função para inserir um elemento em uma posição da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - pos - posição onde o elemento será inserido
        3 - elemento - valor a ser inserido
  =========================================================*/
void inserirPosicao(TLLDE * const lista, int pos, int elemento){
    if(pos < 0 || pos > lista->tamanho){
        printf("\nPosicao invalida!\n");
        return;
    }

    if(pos == 0){
        inserirNoInicioDaLLDE(lista, elemento);
        return;
    }

    if(pos == lista->tamanho){
        inserirNoFimDaLLDE(lista, elemento);
        return;
    }

    TNo * pAuxElemento = malloc(sizeof(TNo));
    verificarMalloc(pAuxElemento);

    inicializarNo(pAuxElemento, elemento);

    TNo * pAuxAndarilho = lista->inicio;

    int i = 0;
    while(i < pos - 1){
        pAuxAndarilho = pAuxAndarilho->proximo;
        i++;
    }

    pAuxElemento->proximo = pAuxAndarilho->proximo;
    pAuxElemento->anterior = pAuxAndarilho;

    pAuxAndarilho->proximo->anterior = pAuxElemento;
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
int acessarPosicao(TLLDE const * const lista, int pos){
    if(LLDEEstaVazia(lista)){
            printf("\nA lista esta vazia!\n");
            return -1;
        }

        if(pos < 0 || pos >= lista->tamanho){
            printf("\nPosicao invalida!\n");
            return -1;
        }

        TNo * pAux = lista->inicio;

        int i = 0;
        while(i < pos){
            pAux = pAux->proximo;
            i++;
        }

        return pAux->dado;
}

/*=========================================================
    Função para remover o nó na posicao solicitada da lista
    Parametros:
        1 - lista - ponteiro para a struct da lista
        2 - pos - posição desejada
  =========================================================*/
void retirarPosicao(TLLDE * const lista, int pos){
    if(LLDEEstaVazia(lista)){
        printf("\nA lista esta vazia!\n");
        return;
    }

    if(pos < 0 || pos >= lista->tamanho){
        printf("\nPosicao invalida!\n");
        return;
    }

    if(pos == 0){
        RetirarNoInicioDaLLDE(lista);
        return;
    }

    if(pos == lista->tamanho - 1){
        RetirarNoFimDaLLDE(lista);
        return;
    }

    TNo * pAux = lista->inicio;

    int i = 0;
    while(i < pos){
        pAux = pAux->proximo;
        i++;
    }

    pAux->anterior->proximo = pAux->proximo;
    pAux->proximo->anterior = pAux->anterior;

    free(pAux);
    lista->tamanho--;

    printf("\nElemento da posicao %d removido!\n", pos);
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