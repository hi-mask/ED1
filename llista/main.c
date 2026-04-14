#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void){

    TLista lista;
    int tam = 0;
    printf("Tamanho da lista:\n");
    scanf("%d", &tam);
    getchar();
    inicializarLista(&lista, tam);
    exibirDadosLista(&lista);

    do{
        int opcao = 0, elemento = 0, pos = 0;
        printf("\n====================== MENU ======================\n");
        printf("1. Inserir no fim\n2. Acessar no fim\n3. Retirar no fim\n\n");
        printf("4. Inserir no inicio\n5. Acessar no inicio\n6. Retirar no inicio\n\n");
        printf("7. Inserir na posicao\n8. Acessar na posicao\n9. Retirar na posicao\n\n");
        printf("10. Exibir Lista\n11. Sair\n\n");
        scanf("%d", &opcao);
        getchar();
        printf("\n");

        switch(opcao){
            case 1:
            printf("Elemento a ser inserido no fim:\n");
            scanf("%d", &elemento);
            getchar();
            inserirFimLista(&lista, elemento);
            break;

            case 2:
            printf("%d\n", acessarFimLista(&lista));          
            break;

            case 3:
            retirarFimLista(&lista);
            break;
            
            case 4:
            printf("Elemento a ser inserido no inicio:\n");
            scanf("%d", &elemento);
            getchar();
            inserirInicioLista(&lista, elemento);
            break;

            case 5:
            printf("%d\n", acessarInicioLista(&lista));
            break;

            case 6:
            retirarInicioLista(&lista);
            break;

            case 7:
            printf("Posicao a inserir o elemento:\n");
            scanf("%d", &pos);
            getchar();
            printf("Elemento a ser inserido na posicao %d:\n", pos);
            scanf("%d", &elemento);
            getchar();
            inserirPosicaoLista(&lista, elemento, pos);
            break;

            case 8:
            printf("Posicao a ser acessada\n");
            scanf("%d", &pos);
            getchar();
            printf("%d\n", acessarPosicaoLista(&lista, pos));
            break;

            case 9:
            printf("Posicao a remover o elemento:\n");
            scanf("%d", &pos);
            getchar();
            retirarPosicaoLista(&lista, pos);
            break;

            case 10:
            mostrarLista(&lista);
            break;

            case 11:
            liberarLista(&lista);
            printf("Saindo....\n");
            exit(0);

            default:
            printf("Opcao invalida!\n");

        }
    }while(1);
}