#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "ordenacao.h"

void ordenarConjunto(int *vetor, int tamanho, TPilha * const pilha, TPilha * const pilhaAux){

    for(int i = 0; i < tamanho; i++){
        int valorAtual = vetor[i];

        // tira os maiores da pilha A
        while(!pilhaEstaVazia(pilha) && acessarPilha(pilha) > valorAtual){
            int topo = acessarPilha(pilha);
            desempilhar(pilha);
            empilhar(pilhaAux, topo);
        }

        // coloca o valor na posição certa
        empilhar(pilha, valorAtual);

        // devolve tudo da pilha B
        while(!pilhaEstaVazia(pilhaAux)){
            int topo = acessarPilha(pilhaAux);
            desempilhar(pilhaAux);
            empilhar(pilha, topo);
        }
    }

    // joga de volta pro vetor (ordenado)
    int i = tamanho - 1;
    while(!pilhaEstaVazia(pilha)){
        vetor[i--] = acessarPilha(pilha);
        desempilhar(pilha);
    }
}