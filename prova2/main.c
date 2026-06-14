#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamenteEncadeada.h"

int main(void){
    
    TLLDE lista;
    inicializarLLDE(&lista);
    FILE *arquivo = NULL;
    char *nomeArquivo = "dados.txt";
    char string[250];
    int linha = 0;
    carregarArquivoNaLista(&lista, nomeArquivo);
    
    do{
        int opcao = -1;
        int posicao = -1;
        int elemento = -1;
        printf("================== MENU ==================\n");
        printf("1. Inserir no inicio\n");
        printf("2. Acessar na inicio\n");
        printf("3. Retirar na inicio\n");
        printf("1. Inserir no fim\n");
        printf("2. Acessar na fim\n");
        printf("3. Retirar na fim\n");
        printf("7. Inserir na Posicao\n");
        printf("8. Acessar na Posicao\n");
        printf("9. Retirar na Posicao\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

    switch(opcao){
            case 1:
            printf("Elemento:\n");
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
            printf("Elemento:\n");
            scanf("%d", &elemento);
            getchar();
            break;

            case 5:

            break;

            case 6:
            
            break;

            case 7:
            printf("Posicao:\n");
            scanf("%d", &posicao);
            printf("Elemento:\n");
            scanf("%d", &elemento);
            inserirPosicao(&lista, posicao, elemento);
            break;

            case 8:
            printf("Posicao:\n");
            scanf("%d", &posicao);
            printf("\n%d\n", acessarPosicao(&lista, posicao));
            break;

            case 9:
            printf("Posicao:\n");
            scanf("%d", &posicao);
            retirarPosicao(&lista, posicao);
            break;

            case 0:
            printf("\nSaindo...\n");
            return 0;

            default:
            printf("Opcao invalida!\n");

    }while(1);
}

//tenho que inserir ordenadamente
// ordenar por partes, exemplo, exibe 30 dados e pergunta se quer prosseguir

/*1 etapa
mostrar a lista carregada
fazer operacoes (inserindo alunos no inicio, fim, pos)*/