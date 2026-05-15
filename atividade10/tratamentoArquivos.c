#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaDinamica.h"
#include "tratamentoArquivos.h"
#include "aluno.h"

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
    Função para carregar os dados do arquivo na fila
    Parametros:
        1 - fila         - ponteiro para a struct da fila
        2 - nomeArquivo  - nome do arquivo a ser lido
  =========================================================*/
void carregarArquivoNaFila(TFila * const fila, char nomeArquivo[]){
    FILE *arquivo;
    TAluno aluno;
    char string[250];
    char *campo = NULL;

    liberarFila(fila);
    inicializarFila(fila);

    arquivo = fopen(nomeArquivo, "r");

    if(verificarAberturaArquivo(arquivo)) return;

    while(fgets(string, 250, arquivo) != NULL){
        string[strcspn(string, "\n")] = '\0';
        campo = strtok(string, ";");
        strcpy(aluno.numMatricula, campo);
        campo = strtok(NULL, ";");
        strcpy(aluno.nome, campo);
        enfileirar(fila, &aluno);
    }
    fclose(arquivo);
}
