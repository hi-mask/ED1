#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamenteEncadeada.h"

int main(void){
    
    TLLDE lista;
    inicializarLLDE(&lista);
    
    do{
        int opcao = -1;
        int posicao = -1;
        int elemento = -1;
        int direcao = -1;
        printf("\n================== MENU ==================\n");
        printf("1. Inserir no inicio\n");
        printf("2. Acessar no inicio\n");
        printf("3. Retirar no inicio\n");
        printf("4. Inserir no fim\n");
        printf("5. Acessar no fim\n");
        printf("6. Retirar no fim\n");
        printf("7. Inserir na Posicao\n");
        printf("8. Acessar na Posicao\n");
        printf("9. Retirar na Posicao\n");
        printf("10. Mostrar Lista\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1:
            printf("\nElemento:\n");
            scanf("%d", &elemento);
            getchar();
            inserirNoInicioDaLLDE(&lista, elemento);
            break;

            case 2:
            printf("\n%d\n", acessarInicioDaLLDE(&lista));
            break;

            case 3:
            RetirarNoInicioDaLLDE(&lista);
            break;
                
            case 4:
            printf("\nElemento:\n");
            scanf("%d", &elemento);
            getchar();
            inserirNoInicioDaLLDE(&lista, elemento);
            break;

            case 5:
            printf("\n%d\n", acessarFimDaLLDE(&lista));
            break;

            case 6:
            RetirarNoFimDaLLDE(&lista);
            break;

            case 7:
            printf("\nPosicao:\n");
            scanf("%d", &posicao);
            printf("\nElemento:\n");
            scanf("%d", &elemento);
            inserirPosicao(&lista, posicao, elemento);
            break;

            case 8:
            printf("\nPosicao:\n");
            scanf("%d", &posicao);
            printf("\n%d\n", acessarPosicao(&lista, posicao));
            break;

            case 9:
            printf("\nPosicao:\n");
            scanf("%d", &posicao);
            retirarPosicao(&lista, posicao);
            break;

            case 10:
            direcao = -1;
            printf("\nDirecao desejada\n1. Inicio->Fim\n0. Fim->Inicio\n");
            printf("Opcao: ");
            scanf("%d", &direcao);
            getchar();
            if(direcao){
                mostrarLista(&lista, 1);
            }
            else{
                mostrarLista(&lista, 0);
            }
            break;

            case 0:
            printf("\nSaindo...\n");
            return 0;

            default:
            printf("\nOpcao invalida!\n");

        }
    }while(1);
}