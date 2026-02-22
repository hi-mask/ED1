#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int receberTamanho(){
    int tam = 0;
    scanf("%d", &tam);
    return tam;
}

void criarVet(int *vet, int tam){
    srand(time(NULL));
    
    for(int i = 0; i < tam; i++){
        vet[i] = rand() % 1001;
    }
}
    