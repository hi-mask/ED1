#include <stdio.h>
#include "listaArray.h"
#include <stdlib.h>
int main(void){


    TLista lista;
    printf("\n*******************************\n");
    mostrarDadosLista(&lista);
    inicializarLista(&lista, 7);
    printf("\n*******************************\n");
    printf("\n\tLista Vazia = %d\n", listaEstaVazia(&lista));
    printf("\n*******************************\n");
    printf("\n\tLista Cheia = %d\n", listaEstaCheia(&lista));
    printf("\n*******************************\n");
    
    /*mostrarDadosLista(&lista);

    mostrarLista(&lista);*/

    liberarLista(&lista);


}