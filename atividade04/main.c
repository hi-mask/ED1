#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "conversor.h"
int main(void){

    TPilha pilhaConversoes;

    int decimal = 0;
    printf("Numero decimal:\n");
    scanf("%d", &decimal);

do{
        int opcao = 0;
        printf("\n\t\tMENU\n");
        printf("\nConverter decimal para:\n1. Binario\n2. Octal\n3. Hexadecimal\n4. Sair\n");

        scanf("%d", &opcao);
        switch(opcao){
            case 1:
            criarPilha(15, &pilhaConversoes);
            converterBaseDesejada(decimal, 2, &pilhaConversoes);
            printf("\nNumero convertido para binario:\n");
            exibirNumerosConvertidos(&pilhaConversoes);
            liberarPilha(&pilhaConversoes);
            break;
            
            case 2:
            criarPilha(15, &pilhaConversoes);
            converterBaseDesejada(decimal, 8, &pilhaConversoes);
            printf("\nNumero convertido para octal:\n");
            exibirNumerosConvertidos(&pilhaConversoes);
            liberarPilha(&pilhaConversoes);
            break;

            case 3:
            criarPilha(15, &pilhaConversoes);
            converterBaseDesejada(decimal, 16, &pilhaConversoes);
            printf("\nNumero convertido para hexadecimal:\n");
            exibirNumerosConvertidos(&pilhaConversoes);
            liberarPilha(&pilhaConversoes);
            break;

            case 4:
            printf("\nEncerrando o programa...\n");
            liberarPilha(&pilhaConversoes);
            return 0;
            
            default:
            printf("\nResposta invalida!\n\n");
        }

    }while(1);
}