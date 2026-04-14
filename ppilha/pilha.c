#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void criarPilha(TPilha * const pilha, int capacidade){
    pilha->array = malloc(sizeof(int) * capacidade);

    if(pilha->array == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    printf("Pilha inicializada!\n");
    pilha->capacidade = capacidade;
    pilha->topo = -1;}

void liberarPilha(TPilha * const pilha){
    printf("Pilha liberada!\n");
    free(pilha->array);
    pilha->capacidade = 0;
    pilha->topo = -1;
    pilha->array = NULL;
}

void exibirDadosPilha(TPilha const * const pilha){
    printf("\n\tDados da pilha:\n");
    printf("Capacidade da pilha: %d\n", pilha->capacidade);
    printf("Topo da pilha: %d\n", pilha->topo);
    printf("Array da pilha:\n");
    printf("Pilha = { ");
    if(pilhaVazia(pilha)){
        printf("}\n");
        return;
    }
    int *p = pilha->array;
    int *fim = pilha->array + pilha->topo;
    while(p <= fim){
        if(p == fim){
            printf("%d ", *p);
        }
        else{
            printf("%d, ", *p);
        }
        p++;
        }
    printf("}\n");
}

int pilhaVazia(TPilha const * const pilha){
    if(pilha->topo ==-1){
        return 1;
    }
    return 0;
}

int pilhaCheia(TPilha const * const pilha){
    if(pilha->topo >= pilha->capacidade-1){
        return 1;
    }
    return 0;
}

int acessarPilha(TPilha const * const pilha){
    if(pilhaEstaVazia(pilha)){
        printf("Pilha vazia!\n");
        return -1;
    }
    int *p = pilha->array + pilha->topo - 1;
    return *p;
}

void empilhar(TPilha * const pilha, int elemento){
    if(pilhaCheia(pilha)){
        printf("Pilha cheia!\n");
        return;
    }
    pilha->topo++;
    int *p = pilha->array + pilha->topo;
    *p = elemento;
}

void desempilhar(TPilha * const pilha){
    if(pilhaVazia(pilha)){
        printf("Pilha vazia!\n");
        return;
    }

    pilha->topo--;
}
