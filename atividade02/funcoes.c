#include <stdio.h>
#include "funcoes.h"
#include <stdlib.h>
#include <time.h>

int lerTamanho(){
    int tam = 0;
    printf("Tamanho: ");
    scanf("%d", &tam);

    return tam;
}


void criarConjunto(SET * const conjA){
    conjA->array = malloc(conjA->capacidade * sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < conjA->capacidade; i++){
        conjA->array[i] = rand() % 1001;
    }
    
}

void exibirConjunto(SET const * const conjA){
    printf("{ ");
    for(int i = 0; i < conjA->capacidade; i++){
        if(i == conjA->capacidade - 1){
            printf("%d ", conjA->array[i]); //para tirar a vírgula na ultima impressao
            break;
        }

        printf("%d, ", conjA->array[i]); //imprime normalmente

    }
    printf("}\n");
}

int lerElemento(){
    int elemento = 0;
    printf("\nElemento: ");
    scanf("%d", &elemento);

    return elemento;
}

int realizarBusca(SET const * const conjA, int elemento){
    int resposta = -1; /*será alterado para i apenas
     se o loop encontrar o elemento na posicao i*/

    for(int i = 0; i < conjA->capacidade; i++){
        if(conjA->array[i] == elemento){
            resposta = i; // achou o elemento na posicao i
        }
    }

    return resposta;
}
