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
    int i = 0;
    for(i = 0; i < conjA->capacidade; i++){
        conjA->array[i] = rand() % 1001;
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

int lerElemento(){
    int elemento = 0;
    printf("\nElemento: ");
    scanf("%d", &elemento);

    return elemento;
}

int realizarBusca(SET const * const conjA, int elemento){
    int resposta = -1; /*será alterado para i apenas
     se o loop encontrar o elemento na posicao i*/
    int i = 0;
    for(i = 0; i < conjA->capacidade; i++){
        if(conjA->array[i] == elemento){
            resposta = i; // achou o elemento na posicao i
        }
    }

    return resposta;
}


void ordenarConjunto(SET const * const conjA){
    //selection sort
    int pos = 0;
    for(pos = 0; pos < conjA->capacidade - 1; pos++){
        int min = pos; // min é a pos 0
    int i = 0;
        for(i = pos + 1; i < conjA->capacidade; i++){
            if(conjA->array[i] < conjA->array[min]){
                min = i;
            } // 5 3 2 4 1
            //   0 1 2 3 4 
        }
        
    int temp = conjA->array[pos];
    conjA->array[pos] = conjA->array[min];
    conjA->array[min] = temp;

    }

}

void copiarConjunto(SET * const conjCopia, SET const * const conjOriginal){

    conjCopia->capacidade = conjOriginal->capacidade; // capacidade igual
    conjCopia->array = malloc(conjCopia->capacidade * sizeof(int));
    int i = 0;
    for(i = 0; i < conjCopia->capacidade; i++){
        conjCopia->array[i] = conjOriginal->array[i];
    }

}

int realizarBuscaBinaria(SET const * const conj, int elemento){
    int menor = 0;
    int maior = conj->capacidade - 1;
    while(menor <= maior){
        int meio = (maior + menor)/2;
        if(conj->array[meio] == elemento){
            return meio; // ta retornando a posicao achada
        }
        if(conj->array[meio] < elemento){
            menor = meio + 1;
        }
        else{
            maior = meio - 1;
        }
    }
    return -1;
}