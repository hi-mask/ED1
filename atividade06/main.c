#include <stdio.h>
#include "listaArray.h"
#include <stdlib.h>
int main(void){


    TLista lista;
    printf("\n*******************************\n");
    mostrarDadosLista(&lista);
    inicializarLista(&lista, 5);
    printf("\n\tLista inicializada!\n");
    mostrarDadosLista(&lista);
    printf("\n*******************************\n");

    do{
        int opcao = 0, elemento = 0, posicao = 0;
        printf("\n\t\tMENU\n");
        printf("\n\tInicio\n");
        printf("1. Inserir no inicio\n2. Acessar no inicio\n3. Retirar no inicio\n");
        printf("\n\tFim\n");
        printf("4. Inserir no fim\n5. Acessar no fim\n6. Retirar no fim\n");
        printf("\n\tPosicao Especifica\n");
        printf("7. Inserir na posicao\n8. Acessar na posicao\n9. Retirar na posicao\n");
        printf("\n\tGeral\n");
        printf("10. Mostrar Lista\n11. Sair\n");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 1:
            if(listaEstaCheia(&lista)){
                printf("Lista Cheia!\n");
                break;
            }
            printf("Elemento a ser inserido no inicio:\n");
            scanf("%d", &elemento);
            getchar();
            inserirInicioLista(&lista, elemento);
            break;
            
            case 2:
            printf("%d\n", acessarInicioLista(&lista));
            break;

            case 3:
            retirarIniciolista(&lista);
            break;

            case 4:
            if(listaEstaCheia(&lista)){
                printf("Lista Cheia!\n");
                break;
            }
            printf("Elemento a ser inserido no fim:\n");
            scanf("%d", &elemento);
            getchar();
            inserirFimLista(&lista, elemento);
            break;
            
            case 5:
            printf("%d\n", acessarFimLista(&lista));
            break;

            case 6:
            retirarFimlista(&lista);
            break;

            case 7:
            printf("Posicao desejada:\n");
            scanf("%d", &posicao);
            getchar();
            printf("Elemento a ser inserido na posicao %d:\n", posicao);
            scanf("%d", &elemento);
            getchar();
            inserirPosicaoLista(&lista, posicao, elemento);
            break;

            case 8:
            printf("Posicao desejada:\n");
            scanf("%d", &posicao);
            getchar();
            printf("%d\n", acessarPosicaoLista(&lista, posicao));
            break;

            case 9:
            printf("Posicao desejada:\n");
            scanf("%d", &posicao);
            getchar();
            retirarPosicaoLista(&lista, posicao);
            break;
            case 10:
            mostrarLista(&lista);
            break;

            case 11:
            printf("Saindo...\n");
            liberarLista(&lista);
            return 0;

            default:
            printf("\nResposta invalida!\n\n");
        }

    }while(1);


    liberarLista(&lista);


}