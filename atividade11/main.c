#include <stdio.h>
#include <stdlib.h>
#include "listaDinamica.h"

int main(void){

    TLLSE lista;
    inicializarLista(&lista);

    do{
        int opcao = -1;
        int posicao = -1;
        int elemento = -1;
        printf("================== MENU ==================\n");
        printf("1. Inserir na Posicao\n");
        printf("2. Acessar na Posicao\n");
        printf("3. Retirar na Posicao\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
            printf("Posicao:\n");
            scanf("%d", &posicao);
            printf("Elemento:\n");
            scanf("%d", &elemento);
            inserirPosicao(&lista, posicao, elemento);
            mostrarLista(&lista);
            break;

            case 2:
            printf("Posicao:\n");
            scanf("%d", &posicao);
            printf("\n%d\n", acessarPosicao(&lista, posicao));
            mostrarLista(&lista);
            break;

            case 3:
            printf("Posicao:\n");
            scanf("%d", &posicao);
            retirarPosicao(&lista, posicao);
            mostrarLista(&lista);
            break;

            case 0:
            printf("\nSaindo...\n");
            return 0;

            default:
            printf("Opcao invalida!\n");
        }
    }while(1);
  
}