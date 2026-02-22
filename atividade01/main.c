#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){
    int tamanho = 0;
    
    tamanho = receberTamanho();
    
    int * const vet = malloc(tamanho * sizeof(int));
    
    criarVet(vet, tamanho);
    
    printf("[ ");
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vet[i]);
    }
    printf("]");
    
    free(vet);
    
}