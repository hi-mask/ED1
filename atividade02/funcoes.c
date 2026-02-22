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

void realizarBusca(SET const * const conjA);