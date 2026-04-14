#include <stdio.h>
#include <stdlib.h>
#include "lista.h"



void inicializarLista(TLista * const lista, int tamanho){
    lista->array = malloc(sizeof(int) * tamanho);
    if(lista->array == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    lista->capacidade = tamanho;
    lista->ocupacao = 0;
}

void liberarLista(TLista * const lista){

    free(lista->array);
    lista->array = NULL;
    lista->ocupacao = 0;
    lista->capacidade = 0;
}

int listaEstaVazia(TLista const * const lista){
    if(lista->ocupacao == 0){
        return 1;
    }

    return 0;
}

int listaEstaCheia(TLista const * const lista){
    if(lista->ocupacao == lista->capacidade){
        return 1;
    }

    return 0;

}

void exibirDadosLista(TLista const * const lista){
    printf("====================== DADOS DA LISTA ======================\n");
    printf("Capacidade da Lista: %d\n", lista->capacidade);
    printf("Ocupacao da lista: %d\n", lista->ocupacao);
    printf("Endereco do array da lista: %p\n", lista);
}

void mostrarLista(TLista const * const lista){
   printf("Lista = { ");
    if(listaEstaVazia(lista)){
        printf("}\n");
        return;
    }
    int *p = lista->array;
    int *fim = lista->array + lista->ocupacao - 1;
    while(p <= fim){
        if(p == fim){
            printf("%d }\n", *p); 
            return;
        }
        
        printf("%d, ", *p);
        p++;
    }
    printf("}\n");
}

void inserirFimLista(TLista * const lista, int elemento){
    if(listaEstaCheia(lista)){
        printf("Lista Cheia!\n");
        return;
    }

    int *p = lista->array + lista->ocupacao;
    *p = elemento;
    lista->ocupacao++;
    printf("O elemento %d foi inserido no fim da lista!\n", elemento);
}

int acessarFimLista(TLista const * const lista){
    if(listaEstaVazia(lista)){
        printf("Lista Vazia!\n");
        return -1;
    }
    int *p = lista->array + lista->ocupacao - 1;
    printf("Elemento no fim da lista: ");
    return *p;
}

void retirarFimLista(TLista * const lista){
    if(listaEstaVazia(lista)){
        printf("Lista vazia!\n");
        return;
    }
    printf("O elemento no final da lista foi removido!\n");
    lista->ocupacao--;
}

void inserirInicioLista(TLista * const lista, int elemento){
    if(listaEstaCheia(lista)){
        printf("Lista Cheia!\n");
        return;
    }

    int *aux = lista->array + lista->ocupacao;
    int *inicio = lista->array;
    while(aux > inicio){
        *aux = *(aux - 1);
        aux--;
    }
    lista->ocupacao++;
    *inicio = elemento;
    printf("O elemento %d foi inserido no inicio da lista!\n", elemento);
}

int acessarInicioLista(TLista const * const lista){
    if(listaEstaVazia(lista)){
        printf("Lista vazia!\n");
        return -1;
    }

    int *p = lista->array;
    printf("Elemento no inicio da lista: ");
    return *p;

}

void retirarInicioLista(TLista * const lista){
    if(listaEstaVazia(lista)){
        printf("Lista vazia!\n");
        return;
    }

    int *aux = lista->array;
    int *fim = lista->array + lista->ocupacao - 1;
    while(aux < fim){
        *aux = *(aux + 1);
        aux++;
    }
    printf("O elemento no inicio da lista foi removido!\n");
    lista->ocupacao--;
}

void inserirPosicaoLista(TLista * const lista, int elemento, int posicao){
    if(listaEstaCheia(lista)){
        printf("Lista cheia!\n");
        return;
    }
    if(posicao < 0 || posicao > lista->ocupacao){
        printf("Posicao invalida!\n");
        return;
    }

    int *aux = lista->array + lista->ocupacao;
    int *fim = lista->array + posicao;
    while(aux > fim){
        *aux = *(aux - 1);
        aux--;
    }
    lista->ocupacao++;
    *aux = elemento;
    printf("O elemento %d foi inserido na posicao %d", *aux, posicao);
}

int acessarPosicaoLista(TLista const * const lista, int posicao){
    if(listaEstaVazia(lista)){
        printf("Lista vazia!\n");
        return -1;
    }

    if(posicao < 0 || posicao >= lista->ocupacao){
        printf("Posicao invalida!\n");
        return -1;
    }

    int *p = lista->array + posicao;
    printf("Elemento na posicao %d: ", posicao);
    return *p;
}

void retirarPosicaoLista(TLista * const lista, int posicao){
    if(listaEstaVazia(lista)){
        printf("Lista vazia!\n");
        return;
    }

    if(posicao < 0 || posicao >= lista->ocupacao){
        printf("Posicao invalida!\n");
        return;
    }

    int *aux = lista->array + posicao;
    int *fim = lista->array + lista->ocupacao - 1;
    while(aux < fim){
        *aux = *(aux + 1);
        aux++;
    }
    lista->ocupacao--;
    printf("Elemento removido na posicao %d!\n", posicao);
}
