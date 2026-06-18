#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamenteEncadeada.h"
#include "tratamentoArquivos.h"
#include "aluno.h"
#include <string.h>
#include "ordenacao.h"

/*=========================================================
    Função para exibir o menu de ordenação da lista
    Parametros:
        1 - lista - ponteiro para a lista de alunos
        2 - nomeArquivo - nome do arquivo utilizado para
            salvar as alterações realizadas
  =========================================================*/
void exibirMenuOrdenacao(TLLDE * const lista, char nomeArquivo[]){
    do{
        int opcao = -1;

        printf("\n================== MENU DE ORDENACAO ==================\n");
        printf("1. Ordenar pela Matricula\n");
        printf("2. Ordenar pelo Nome\n");
        printf("3. Ordenar pelo Curso e Nome\n");
        printf("4. Ordenar pela Enfase e Nome\n");
        printf("5. Mostrar lista\n\n");
        printf("6. Voltar ao menu principal\n");
        printf("0. Encerrar o Programa\n\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1:
            ordenarPorMatricula(lista);
            salvarListaNoArquivo(lista, nomeArquivo);
            if(desejaExibirALista()){
                escolherDirecaoExibicao(lista);
            }
            break;

            case 2:
            ordenarPorNome(lista);
            salvarListaNoArquivo(lista, nomeArquivo); 
            if(desejaExibirALista()){
                escolherDirecaoExibicao(lista);
            }
            break;

            case 3:
            ordenarPorCursoNome(lista);
            salvarListaNoArquivo(lista, nomeArquivo);
            if(desejaExibirALista()){
                escolherDirecaoExibicao(lista);
            }
            break;

            case 4:
            ordenarPorEnfaseNome(lista);
            salvarListaNoArquivo(lista, nomeArquivo);
            if(desejaExibirALista()){
                escolherDirecaoExibicao(lista);
            }
            break;

            case 5:
            escolherDirecaoExibicao(lista);
            break;

            case 6:
            printf("Voltando..\n");
            return;

            case 0:
            salvarListaNoArquivo(lista, nomeArquivo); 
            liberarLista(lista);
            printf("\nEncerrando...\n");
            exit(0);


            default:
            printf("\nOpcao invalida!\n");

        }
    }while(1);
}

/*=========================================================
    Função para trocar os ponteiros para os alunos
    armazenados em dois nós da lista
    Parametros:
        1 - no1 - ponteiro para o primeiro nó
        2 - no2 - ponteiro para o segundo nó
  =========================================================*/
void trocarAlunos(TNo *no1, TNo *no2){
    TAluno *aux = no1->atual;
    no1->atual = no2->atual;
    no2->atual = aux;
}

/*=========================================================
    Função para ordenar a lista pelo número de matrícula
    dos estudantes
    Parametros:
        1 - lista - ponteiro para a lista a ser ordenada
  =========================================================*/
void ordenarPorMatricula(TLLDE * const lista){
    TNo *no1, *no2;

    for(no1 = lista->inicio; no1 != NULL; no1 = no1->proximo){
        for(no2 = no1->proximo; no2 != NULL; no2 = no2->proximo){
            if(strcmp(no1->atual->numMatricula,
                      no2->atual->numMatricula) > 0){
                trocarAlunos(no1, no2);
            }
        }
    }
    printf("\nA lista foi ordenada pelo numero de matricula!\n\n");
}

/*=========================================================
    Função para ordenar a lista pelo nome dos estudantes
    em ordem alfabética
    Parametros:
        1 - lista - ponteiro para a lista a ser ordenada
    Retorno:
        Nenhum
  =========================================================*/
void ordenarPorNome(TLLDE * const lista){
    TNo *no1, *no2;

    for(no1 = lista->inicio; no1 != NULL; no1 = no1->proximo){
        for(no2 = no1->proximo; no2 != NULL; no2 = no2->proximo){
            if(strcmp(no1->atual->nome, no2->atual->nome) > 0){
                trocarAlunos(no1, no2);
            }
        }
    }
        printf("\nA lista foi ordenada pelo nome dos(as) estudantes!\n\n");

}

/*=========================================================
    Função para ordenar a lista pelo curso e, em caso de
    empate, pelo nome dos estudantes
    Parametros:
        1 - lista - ponteiro para a lista a ser ordenada
  =========================================================*/
void ordenarPorCursoNome(TLLDE * const lista){
    TNo *no1, *no2;
    int cmpCurso = 0;

    for(no1 = lista->inicio; no1 != NULL; no1 = no1->proximo){
        for(no2 = no1->proximo; no2 != NULL; no2 = no2->proximo){

            cmpCurso = strcmp(no1->atual->curso, no2->atual->curso);

            if(cmpCurso > 0 || (cmpCurso == 0 &&
            strcmp(no1->atual->nome, no2->atual->nome) > 0)){
                trocarAlunos(no1, no2);
            }
        }
    }
        printf("\nA lista foi ordenada pelo curso e nome dos(as) estudantes!\n\n");
}

/*=========================================================
    Função para ordenar a lista pela ênfase e, em caso de
    empate, pelo nome dos estudantes
    Parametros:
        1 - lista - ponteiro para a lista a ser ordenada
    Retorno:
        Nenhum
  =========================================================*/
void ordenarPorEnfaseNome(TLLDE * const lista){
    TNo *no1, *no2;
    int cmpEnfase = 0;
    
    for(no1 = lista->inicio; no1 != NULL; no1 = no1->proximo){
        for(no2 = no1->proximo; no2 != NULL; no2 = no2->proximo){

            cmpEnfase = strcmp(no1->atual->enfase, no2->atual->enfase);

            if(cmpEnfase > 0 || (cmpEnfase == 0 &&
               strcmp(no1->atual->nome, no2->atual->nome) > 0)){
                trocarAlunos(no1, no2);
            }
        }
    }
         printf("\nA lista foi ordenada pela enfase e nome dos(as) estudantes!\n\n");
}

