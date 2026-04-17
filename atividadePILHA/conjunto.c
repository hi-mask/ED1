#include <stdio.h>
#include "conjunto.h"
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
    if(conjA->array == NULL){
        printf("Problema ao alocar memoria!\n");
        exit(1);
    }

    srand(time(NULL));
    int *aux = conjA->array;
    int *fim = conjA->array + conjA->capacidade;

    while(aux < fim){
        *aux = rand() % 51; // de 0 a 50
        aux++;
    }
}

void exibirConjunto(SET const * const conjA){
    printf("{ ");
    int i = 0;
    for(i = 0; i < conjA->capacidade; i++){
        if(i == conjA->capacidade - 1){
            printf("%d ", conjA->array[i]); //para tirar a vírgula na ultima impressao
            break;
        }

        printf("%d, ", conjA->array[i]); //imprime normalmente

    }
    printf("}\n");
}