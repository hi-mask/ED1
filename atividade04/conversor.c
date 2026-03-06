#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "conversor.h"

/*str é o vetor que será acessado para imprimir as conversoes*/
char str[] = "0123456789ABCDEF"; 

/*======================================================
    Função que realiza o processo de conversão para base N e guarda em uma pilha
    Parâmetros:
    1 - dividendo: variavel que guarda o numero decimal a ser convertido
    2 - n: variavel que guarda a base desejada para a conversão
    3 - pilha: ponteiro que aponta para a struct do tipo TPilha 
======================================================*/
void converterBaseDesejada(int dividendo, int n, TPilha * const pilha){
    while(dividendo > 0){
        empilhar(dividendo % n, pilha);
        dividendo /= n;
    }
}

/*======================================================
    Função que exibe a conversão por meio de desempilhamentos consecutivos
    Parâmetros:
    1 - pilha: ponteiro que aponta para a struct do tipo TPilha 
======================================================*/
void exibirNumerosConvertidos(TPilha * const pilha){
    char *p = str;
    while(!verificarPilhaVazia(pilha)){
        int valor = acessarPilha(pilha);
        printf("%c", *(p + valor));
        desempilhar(pilha);
    }
    printf("\n");
}

