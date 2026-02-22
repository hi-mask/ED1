#include <stdio.h>
#include "funcoes.h"
#include <stdlib.h>
int main(){

    SET conjunto;
    int tamanho = lerTamanho();

    conjunto.capacidade = tamanho;

    criarConjunto(&conjunto);
    exibirConjunto(&conjunto);

    do{
        int opcao = 0;
        printf("\nDeseja realizar uma busca?\n1. Sim\n2. Nao\n");
        scanf("%d", &opcao);

        int elemento = 0;

        switch(opcao){
            case 1:
            int elemento = lerElemento();
            int resposta = realizarBusca(&conjunto, elemento);

            if(resposta == -1){
                printf("\nO elemento %d nao pertence ao conjunto.\n", elemento);
            }
            else{
                printf("\nO elemento %d esta na posicao %d do conjunto.\n", elemento, resposta);
            }

            break;
            
            case 2:
            printf("\nEncerrando o programa...\n");
            return 0;
            
            default:
            printf("\nResposta invalida!\n\n");
        }

    }while(1);

    free(conjunto.array);

    return 0;
}