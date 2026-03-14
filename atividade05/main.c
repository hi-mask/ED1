#include "FilaEstatica.h"
int main(void)
{
    TFila filaTeste;

    printf("\nFila Declarada\n");
    criarFila(4, &filaTeste);
    printf("\nFila Criada e Inicializada\n");
    dadosDaFila(&filaTeste);
    char *str = mostrarFila(&filaTeste);
    printf("\n%s\n", str);
    free(str);
    
    enfileirar(105, &filaTeste);
    enfileirar(205, &filaTeste);
    enfileirar(305, &filaTeste);
    enfileirar(405, &filaTeste);
    printf("\nFila esta cheia?\n");
        if(filaEstaCheia(&filaTeste)){
            printf("Nao esta cheia.\n");
        }
     enfileirar(505, &filaTeste);
     printf("\nFila com dados incluidos\n");
     dadosDaFila(&filaTeste);
     str = mostrarFila(&filaTeste);
     printf("\n%s\n", str);
     free(str);    
     dadosDaFila(&filaTeste);
     desenfileirar(&filaTeste);
     desenfileirar(&filaTeste);
     desenfileirar(&filaTeste);
     enfileirar(550,&filaTeste);
     enfileirar(660,&filaTeste);
     str = mostrarFila(&filaTeste);
     printf("\n%s\n", str);
     free(str);  

    printf("\nFila com dados incluidos/excluidos\n");
    dadosDaFila(&filaTeste);



    liberarFila(&filaTeste);
}