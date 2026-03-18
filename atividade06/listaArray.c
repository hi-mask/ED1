#include <stdio.h>
#include "listaArray.h"
#include <stdlib.h>

/*=========================================================
    Função que mostra os dados da struct de uma lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void mostrarDadosLista(TLista const * const lista){
    printf("\nTamanho da lista: %d\n", lista->tamanho);
    printf("Ocupacao: %d\n", lista->ocupacao);
    printf("Endereco do array: %p\n", lista);

}

/*=========================================================
    Função que cria e inicializa uma lista
    Parametros: 
		1 - lista - define a quantidade de elementos que a lista contem
    	2 - tamanho - ponteiro para a struct com os dados da lista
  =========================================================*/
void inicializarLista(TLista * const lista, int tamanho){
  lista->tamanho = tamanho;
  lista->ocupacao = 0;
  lista->array = malloc(lista->tamanho * sizeof(int));
}

/*=========================================================
    Função que libera o espaco de memória usado pela lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void liberarLista(TLista *  const lista){
    free(lista->array);
    lista->tamanho = 0;
    lista->ocupacao = 0;
    lista->array = NULL;
}

/*=========================================================
    Função para mostrar a lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
	Retorno:
		ponteiro para a string com os dados da lista
  =========================================================*/
void mostrarLista(TLista const * const lista){
    if(listaEstaVazia(lista)){
        printf("Lista = { }\n");
        return;
    }

    printf("Lista = { ");

    int *p = lista->array;
    while(*p != '\0'){
        printf(" %d ", *p);

        p++;
    }
    printf("}\n");

}

/*=========================================================
    Função que verifica se a lista esta vazia
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
	Retorno:
		!= 0 	- lista esta cheia
		0 		-  lista não esta cheia
  =========================================================*/
int listaEstaVazia(TLista const * const lista){
    if(lista->ocupacao == 0) return 1;
    
    return 0;
}

/*=========================================================
    Função que verifica se a lista esta cheia
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
	Retorno:
		!= 0 	- lista esta cheia
		0 		-  lista não esta cheia
  =========================================================*/
int listaEstaCheia(TLista const * const lista){
    if(lista->ocupacao == lista->tamanho) return 1;

    return 0;
}

void inserirFimLista(TLista * const lista, int elemento){
    if(listaEstaCheia(lista)) printf("Lista cheia!\n");
    /*Guardo elementos no array na posicao de ocupação*/
    lista->array[lista->ocupacao] = elemento;
    //Como eu guardei um elemento, preciso incrementar
    lista->ocupacao++;
}

int acessarFimLista(TLista const * const lista){
    if(listaEstaVazia(lista)) printf("Lista vazia!\n");
    
    /*a ocupação sempre está na frente, por isso tenho que
    fazer lista->ocupacao-1 */
    return lista->array[lista->ocupacao - 1];
}

void retirarFimlista(TLista * const lista){
    if(listaEstaVazia(lista)) printf("Lista Vazia!\n");

    lista->ocupacao--;
}


