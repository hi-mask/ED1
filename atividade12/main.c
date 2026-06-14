#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamenteEncadeada.h"

int main(void){
    
    TLLDE lista;
    inicializarLLDE(&lista);

    // 1 é do inicio p fim, 0 é do fim p inicio
    inserirNoInicioDaLLDE(&lista, 40);
    inserirNoFimDaLLDE(&lista, 50);
    inserirNoInicioDaLLDE(&lista, 30);
    inserirNoFimDaLLDE(&lista, 60);
    mostrarLista(&lista, 0);
    mostrarLista(&lista, 1);
    printf("\n%d\n", acessarInicioDaLLDE(&lista));
    printf("\n%d\n", acessarFimDaLLDE(&lista));
    RetirarNoInicioDaLLDE(&lista);
    RetirarNoFimDaLLDE(&lista);
    mostrarLista(&lista, 0);
    mostrarLista(&lista, 1);
    RetirarNoInicioDaLLDE(&lista);
    RetirarNoFimDaLLDE(&lista);
    mostrarLista(&lista, 0);
    mostrarLista(&lista, 1);
    inserirNoInicioDaLLDE(&lista, 98);
    inserirNoFimDaLLDE(&lista, 99);
    mostrarLista(&lista, 0);
    mostrarLista(&lista, 1);
}