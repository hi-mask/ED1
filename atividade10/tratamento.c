#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaDinamica.h"
#include "tratamento.h"
int verificarAberturaArquivo(FILE *arquivo){
    if(arquivo == NULL){
        printf("Problema ao abrir o arquivo!\n");
        return 1;
    }
    return 0;
}

void carregarArquivoNaFila(TFila * const fila, char nomeArquivo[]){

    FILE *arquivo;
    TAluno aluno;
    char string[250];
    char *campo = NULL;

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
