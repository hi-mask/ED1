#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaDinamica.h"
#include "tratamentoArquivos.h"
#include "aluno.h"

int main(void){

    TFila fila;
    inicializarFila(&fila);
    TAluno aluno;

    FILE *arquivo = NULL;
    char *nomeArquivo = "alunosGeral.txt";
    char string[250];
    int linha = 0;

    do{
        int opcao = 0;
        printf("\n=========== FILA DE ALUNOS ===========\n");
        printf("1. Criar arquivo e cadastrar aluno\n");
        printf("2. Adicionar aluno no final do arquivo\n");
        printf("3. Mostrar fila\n");
        printf("4. Mostrar primeiro da fila\n");
        printf("5. Remover aluno da fila\n");
        printf("6. Limpar fila\n");
        printf("7. Sair\n");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
           case 1:

            arquivo = fopen(nomeArquivo, "w");
            if(verificarAberturaArquivo(arquivo))return 1;

            printf("Digite matricula e nome:\n");
            printf("Exemplo: 2025.1.0028.0380-8;MARCOS PAULO DA SILVA OLIVEIRA\n\n");

            fgets(string, 250, stdin);
            string[strcspn(string, "\n")] = '\0';
            fprintf(arquivo, "%s\n", string);
            fclose(arquivo);
            printf("Aluno cadastrado!\n");
            carregarArquivoNaFila(&fila, nomeArquivo);
            break;
            
            case 2:
            arquivo = fopen(nomeArquivo, "a");
            if(verificarAberturaArquivo(arquivo)) return 1;

            printf("Digite matricula e nome:\n");
            printf("Exemplo: 2025.1.0028.0380-8;MARCOS PAULO DA SILVA OLIVEIRA\n\n");

            fgets(string, 250, stdin);
            string[strcspn(string, "\n")] = '\0';
            fprintf(arquivo, "%s\n", string);
            fclose(arquivo);

            printf("Aluno cadastrado!\n");
            carregarArquivoNaFila(&fila, nomeArquivo);
            break;

            case 3:
            mostrarFila(&fila);
            break;

            case 4:
            acessarInicio(&fila);
            break;
            
            case 5:
            desenfileirar(&fila);
            break;

            case 6:
            liberarFila(&fila);
            inicializarFila(&fila);
            printf("Fila limpa!\n");
            break;

            case 7:
            printf("Saindo...\n");
            liberarFila(&fila);
            return 0;

            default:
            printf("\nResposta invalida!\n\n");
        }

    }while(1);

    liberarFila(&fila);
}