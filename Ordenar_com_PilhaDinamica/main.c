#include <stdio.h>
#include "pilha.h"
#include <stdlib.h>
#include "conjunto.h"
#include "ordenacao.h"

int main(void){
    
    TPilha pilha, pilhaAux;
    SET conjunto;
    int tamanho = lerTamanho();
    conjunto.capacidade = tamanho;
    
    criarConjunto(&conjunto);

    inicializarPilha(&pilha);
    inicializarPilha(&pilhaAux);

    printf("Conjunto Original:\n");
    exibirConjunto(&conjunto);

    ordenarConjunto(conjunto.array, tamanho, &pilha, &pilhaAux);
    printf("Conjunto Ordenado:\n");
    exibirConjunto(&conjunto);


    
}