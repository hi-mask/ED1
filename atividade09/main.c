#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

int main(void){

    TFila fila;
    inicializarFila(&fila);
    do{
        int opcao = 0, elemento = 0, posicao = 0;
        printf("\n=============== MENU ===============\n");
        printf("1. Enfileirar\n2. Acessar no inicio\n3. Desenfileirar\n");
        printf("4. Mostrar lista\n5. Sair\n");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 1:
            printf("Elemento a ser inserido no inicio:\n");
            scanf("%d", &elemento);
            getchar();
            enfileirar(&fila, elemento);
            break;
            
            case 2:
            printf("%d\n", acessarInicio(&fila));
            break;

            case 3:
            desenfileirar(&fila);
            break;

            case 4:
            mostrarFila(&fila);
            break;
            
            case 5:
            printf("Saindo...\n");
            liberarFila(&fila);
            return 0;

            default:
            printf("\nResposta invalida!\n\n");
        }

    }while(1);

    liberarFila(&fila);
}