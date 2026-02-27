#include <stdio.h>
#include "funcoes.h"
#include <stdlib.h>
int main(){

    SET conjunto;
    SET conjuntoCopia;
    int tamanho = lerTamanho();
    int verificador = 0;
    conjunto.capacidade = tamanho;

    criarConjunto(&conjunto);
    
    do{
        int opcao = 0;
        printf("\n\t\tMENU\n");
        printf("\n1. Exibir Conjunto original\n2. Realizar busca sequencial\n");
        printf("3. Exibir conjunto original e ordenado\n4. Realizar busca binaria\n5. Sair\n");

        scanf("%d", &opcao);
        int elemento = 0;
        int resposta = 0;
        
        switch(opcao){
            case 1:
            printf("\nConjunto Original\n\n");
            exibirConjunto(&conjunto);
            break;
            
            case 2:
            elemento = lerElemento();
            resposta = realizarBusca(&conjunto, elemento);

            if(resposta == -1){
                printf("\nO elemento %d nao pertence ao conjunto.\n", elemento);
            }
            else{
                printf("\nO elemento %d esta na posicao %d do conjunto.\n", elemento, resposta);
            }

            break;

            case 3:
            verificador = 1; // isso daqui é para garantir q o conjunto ordenado surgiu

            copiarConjunto(&conjuntoCopia, &conjunto);
            ordenarConjunto(&conjuntoCopia);

            printf("\nConjunto Original\n\n");
            exibirConjunto(&conjunto);

            printf("\nConjunto Ordenado\n\n");
            exibirConjunto(&conjuntoCopia);

            break;

            case 4:
            if(!verificador){
                printf("\nO conjunto ordenado nao existe\n");
                break;
            }
            elemento = lerElemento();
            resposta = realizarBuscaBinaria(&conjuntoCopia, elemento);

            if(resposta == -1){
                printf("\nO elemento %d nao pertence ao conjunto.\n", elemento);
            }
            else{
                printf("\nO elemento %d esta na posicao %d do conjunto ordenado.\n",
                     elemento, resposta);
            }
            break;

            case 5:
            printf("\nEncerrando o programa...\n");
            return 0;
            
            default:
            printf("\nResposta invalida!\n\n");
        }

    }while(1);

    free(conjunto.array);
    free(conjuntoCopia.array);
    return 0;
}