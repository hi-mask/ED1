#include <stdio.h>
#include "pilha.h"

int main(void){

    TPilha pilha;
    int opcao = 0, tam = 0;
    printf("Tamanho:\n");
    scanf("%d", &tam);
    getchar();
    criarPilha(&pilha, tam);
    do{
        int opcao = 0;
        printf("============== MENU ==============\n");
        printf("1. Empilhar\n2. Acessar Pilha\n3. Desempilhar\n");
        printf("4. Exibir Pilha\n5. Sair\n");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){

            case 1:
            int elemento = 0;
            printf("Elemento a ser inserido na pilha:\n");
            scanf("%d", &elemento);
            empilhar(&pilha, elemento);
            break;

            case 2:
            printf("Elemento no topo: %d\n", acessarPilha(&pilha));
            break;

            case 3:
            desempilhar(&pilha);
            break;

            case 4:
            exibirDadosPilha(&pilha);
            break;

            case 5:
            printf("Saindo...\n");
            liberarPilha(&pilha);
            return 0;

            default:
            printf("Opcao Invalida!\n");
        }
}while(1);

    liberarPilha(&pilha);
}