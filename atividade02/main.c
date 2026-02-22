#include <stdio.h>
#include "funcoes.h"
#include <stdlib.h>
int main(){

    SET conjunto;
    int tamanho = lerTamanho();

    conjunto.capacidade = tamanho;
    
    criarConjunto(&conjunto);
    exibirConjunto(&conjunto);

    free(conjunto.array);

    return 0;
}