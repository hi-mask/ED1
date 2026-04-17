#include <stdio.h>
#include "conjunto.h"
#include <stdlib.h>
#include <time.h>

/*=========================================================
    Função para ler o tamanho do conjunto
    Retorno:
        valor inteiro correspondente ao tamanho informado
  =========================================================*/
int lerTamanho(){
    int tam = 0;
    printf("Tamanho: ");
    scanf("%d", &tam);

    return tam;
}

/*=========================================================
    Função para criar um conjunto com valores aleatórios
    Parametros:
        1 - conjA - ponteiro para a struct do conjunto
  =========================================================*/
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

/*=========================================================
    Função para exibir os elementos do conjunto
    Parametros:
        1 - conjA - ponteiro para a struct do conjunto
  =========================================================*/
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