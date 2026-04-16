#include <stdio.h>
#include "pilha.h"
#include <stdlib.h>

int main(void){
    TPilha pilha;

    inicializarPilha(&pilha);
    mostrarPilha(&pilha);
    empilhar(&pilha, 4);
    empilhar(&pilha, 5);
    printf("ELemento no topo: %d\n",acessarPilha(&pilha));
    mostrarPilha(&pilha);
    desempilhar(&pilha);
    printf("ELemento no topo: %d\n",acessarPilha(&pilha));

    liberarPilha(&pilha);
    mostrarPilha(&pilha);
    
}