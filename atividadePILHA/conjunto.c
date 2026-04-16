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
    srand(time(NULL));
    int *aux = conjA;
    int *fim = conjA + conjA->capacidade;

    while(aux < fim){
        *aux = rand() % 51; // de 0 a 50
        aux++;
    }
}