#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamenteEncadeada.h"
#include "tratamentoArquivos.h"
#include "aluno.h"
#define TAM_STRING 250
int main(void){
    
    TLLDE lista;
    inicializarLLDE(&lista);
    FILE *arquivo = NULL;
    char *nomeArquivo = "DadosDosAlunos.csv";
    TAluno *pAux = NULL;
    carregarArquivoNaLista(&lista, nomeArquivo);
    
    do{
        int opcao = -1;
        int posicao = -1;

        printf("================== MENU ==================\n");
        printf("1. Inserir no inicio\n");
        printf("2. Acessar na inicio\n");
        printf("3. Retirar na inicio\n\n");
        printf("4. Inserir no fim\n");
        printf("5. Acessar na fim\n");
        printf("6. Retirar na fim\n\n");
        printf("7. Inserir na Posicao\n");
        printf("8. Acessar na Posicao\n");
        printf("9. Retirar na Posicao\n");
        printf("10. Mostrar Lista\n\n");
        printf("0. Sair\n\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1:
            pAux = receberDadosDoTeclado();
            inserirNoInicioDaLLDE(&lista, pAux);
            salvarListaNoArquivo(&lista, nomeArquivo);
            printf("\nAluno cadastrado com sucesso!\n");
            break;

            case 2:
            printf("\n");
            pAux = acessarInicioDaLLDE(&lista);
                if(pAux != NULL){
                    TNo auxNo; 
                    auxNo.atual = pAux; 
                    exibirAluno(&auxNo);
                }
            printf("\n");
            break;

            case 3:
            RetirarNoInicioDaLLDE(&lista);
            salvarListaNoArquivo(&lista, nomeArquivo);
            break;
                
            case 4:
            pAux = receberDadosDoTeclado();
            inserirNoFimDaLLDE(&lista, pAux);
            salvarListaNoArquivo(&lista, nomeArquivo);
            printf("\nAluno cadastrado com sucesso!\n");
            break;

            case 5:
            pAux = acessarFimDaLLDE(&lista);
            printf("\n");
                if(pAux != NULL){
                    TNo auxNo; 
                    auxNo.atual = pAux; 
                    exibirAluno(&auxNo);
                }
            printf("\n");
            break;

            case 6:
            RetirarNoFimDaLLDE(&lista);
            salvarListaNoArquivo(&lista, nomeArquivo);
            break;

            case 7:
            printf("\nPosicao:\n");
            scanf("%d", &posicao);
            getchar();

            pAux = receberDadosDoTeclado();
            inserirPosicao(&lista, posicao, pAux);
            salvarListaNoArquivo(&lista, nomeArquivo);
            printf("\nAluno inserido na posicao %d!\n", posicao);
            break;

            case 8:
            printf("\nPosicao:\n");
            scanf("%d", &posicao);
            getchar();

            pAux = acessarPosicao(&lista, posicao);
            printf("\n");
            if(pAux != NULL){
                TNo auxNo; 
                auxNo.atual = pAux; 
                exibirAluno(&auxNo);
            }
            printf("\n");
            break;

            case 9:
            printf("\nPosicao:\n");
            scanf("%d", &posicao);
            getchar();

            retirarPosicao(&lista, posicao);
            salvarListaNoArquivo(&lista, nomeArquivo);
            break;

            case 10:
            int direcao = -1;
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
            salvarListaNoArquivo(&lista, nomeArquivo); 
            liberarLista(&lista);
            printf("\nSaindo...\n");
            return 0;

            default:
            printf("\nOpcao invalida!\n");

        }
    }while(1);
}
