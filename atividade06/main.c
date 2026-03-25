#include <stdio.h>
#include "listaArray.h"
#include <stdlib.h>
int main(void){


    TLista lista;
    int verificador = 0;
    printf("\n*******************************\n");
    mostrarDadosLista(&lista);
    inicializarLista(&lista, 5);
    printf("\n*******************************\n");
    /*printf("\n\tLista Vazia = %d\n", listaEstaVazia(&lista));
    printf("\n*******************************\n");
    printf("\n\tLista Cheia = %d\n", listaEstaCheia(&lista));
    printf("\n*******************************\n");
    */

    do{
        int opcao = 0, elemento = 0;
        printf("\n\t\tMENU\n");
        printf("\n\tInicio\n");
        printf("1. Inserir no inicio\n2. Acessar no inicio\n3. Retirar no inicio\n");
        printf("\n\tFim\n");
        printf("4. Inserir no fim\n5. Acessar no fim\n6. Retirar no fim\n");
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
            if(listaEstaVazia(&lista)){
                printf("Lista Vazia!\n");
                break;
            }    
            printf("Elemento no inicio:\n");
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
            if(listaEstaVazia(&lista)){
                printf("Lista Vazia!\n");
                break;
            }   
            printf("Elemento no fim:\n");
            printf("%d\n", acessarFimLista(&lista));
            break;

            case 6:
            retirarFimlista(&lista);
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