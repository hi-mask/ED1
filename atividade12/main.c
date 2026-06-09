#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamenteEncadeada.h"

int main(void){
    
    TLLDE lista;
    inicializarLLDE(&lista);

    inserirNoInicioDaLLDE(&lista, 40);
    inserirNoInicioDaLLDE(&lista, 30);
    inserirNoInicioDaLLDE(&lista, 50);
    mostrarLista(&lista, 1);
    mostrarLista(&lista, 0);
    printf("\n%d\n", acessarInicioDaLLDE(&lista));
    RetirarNoInicioDaLLDE(&lista);
    printf("\n%d\n", acessarInicioDaLLDE(&lista));
    RetirarNoInicioDaLLDE(&lista);
    printf("\n%d\n", acessarInicioDaLLDE(&lista));
    RetirarNoInicioDaLLDE(&lista);
    RetirarNoInicioDaLLDE(&lista);
    printf("\n%d\n", acessarInicioDaLLDE(&lista));
    inserirNoInicioDaLLDE(&lista, 10);
    inserirNoInicioDaLLDE(&lista, 20);
    inserirNoInicioDaLLDE(&lista, 30);
    mostrarLista(&lista, 1);
    mostrarLista(&lista, 0);
    RetirarNoInicioDaLLDE(&lista);
    RetirarNoInicioDaLLDE(&lista);
    RetirarNoInicioDaLLDE(&lista);

}