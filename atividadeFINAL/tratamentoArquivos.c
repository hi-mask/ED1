#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaDuplamenteEncadeada.h"
#include "tratamentoArquivos.h"
#include "aluno.h"
#define TAM_STRING 250
/*=========================================================
    Função para verificar se o arquivo foi aberto corretamente
    Parametros:
        1 - arquivo - ponteiro para o arquivo
    Retorno:
        1   - erro ao abrir o arquivo
        != 0      - arquivo aberto com sucesso
  =========================================================*/
int verificarAberturaArquivo(FILE *arquivo){
    if(arquivo == NULL){
        printf("Problema ao abrir o arquivo!\n");
        return 1;
    }
    return 0;
}

/*=========================================================
    Função para carregar os dados do arquivo na lista
    Parametros:
        1 - lista         - ponteiro para a struct da lista
        2 - nomeArquivo  - nome do arquivo a ser lido
  =========================================================*/
void carregarArquivoNaLista(TLLDE * const lista, char nomeArquivo[]){
    FILE *arquivo = fopen(nomeArquivo, "r");
    if(verificarAberturaArquivo(arquivo)) return;

    char string[TAM_STRING];
    char *campo = NULL;

    while(fgets(string, sizeof(string), arquivo) != NULL){
        string[strcspn(string, "\n")] = '\0';
        
        TAluno *novoAluno = malloc(sizeof(TAluno));
        if(novoAluno == NULL) exit(1);

        campo = strtok(string, ";");
        if(!campo) { free(novoAluno); continue; }
        strcpy(novoAluno->numMatricula, campo);
        
        campo = strtok(NULL, ";");
        strcpy(novoAluno->nome, campo);
        
        campo = strtok(NULL, ";");
        strcpy(novoAluno->turno, campo);
        
        campo = strtok(NULL, ";");
        strcpy(novoAluno->periodo, campo);
        
        campo = strtok(NULL, ";");
        strcpy(novoAluno->enfase, campo);
        
        campo = strtok(NULL, ";");
        strcpy(novoAluno->curso, campo);
        inserirNoFimDaLLDE(lista, novoAluno);
    }
    fclose(arquivo);
}

/*=========================================================
    Função para salvar todos os alunos da lista em um arquivo
    Parametros:
        1 - lista - ponteiro para a lista a ser salva
        2 - nomeArquivo - nome do arquivo de destino
  =========================================================*/
void salvarListaNoArquivo(TLLDE const * const lista, char nomeArquivo[]){
    FILE *arquivo = fopen(nomeArquivo, "w");
    if(verificarAberturaArquivo(arquivo)) return;

    TNo *pAux = lista->inicio;

    while(pAux != NULL){
        fprintf(arquivo, "%s;%s;%s;%s;%s;%s\n", 
                pAux->atual->numMatricula,
                pAux->atual->nome,
                pAux->atual->turno,
                pAux->atual->periodo,
                pAux->atual->enfase,
                pAux->atual->curso);
        
        pAux = pAux->proximo;
    }
    
    fclose(arquivo);
}