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
    while(*p != lista->ocupacao){
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

/*=========================================================
    Função que insere um elemento no fim da lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
        2 - elemento - elemento a ser inserido no fim da lista
  =========================================================*/
void inserirFimLista(TLista * const lista, int elemento){
    if(listaEstaCheia(lista)) printf("Lista cheia!\n");
    /*Guardo elementos no array na posicao de ocupação*/
    lista->array[lista->ocupacao] = elemento;
    //Como eu guardei um elemento, preciso incrementar
    lista->ocupacao++;
}

/*=========================================================
    Função que acessa e retorna o elemento no fim da lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
    Retorno:
		elemento que está na posição ocupação - 1
  =========================================================*/
int acessarFimLista(TLista const * const lista){
    if(listaEstaVazia(lista)) printf("Lista vazia!\n");
    
    /*a ocupação sempre está na frente, por isso tenho que
    fazer lista->ocupacao-1 */
    return lista->array[lista->ocupacao - 1];
}

/*=========================================================
    Função que retira um elemento no fim da lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
        2 - elemento - elemento a ser inserido no fim da lista
  =========================================================*/
void retirarFimlista(TLista * const lista){
    if(listaEstaVazia(lista)) printf("Lista Vazia!\n");

    lista->ocupacao--;
}

/*=========================================================
    Função que insere um elemento no inicio da lista
    Parametros: 
        1 - lista - ponteiro para a struct com os dados da lista
        2 - elemento - elemento a ser inserido no inicio da lista
  =========================================================*/
void inserirInicioLista(TLista * const lista, int elemento){
    if(listaEstaCheia(lista)) printf("Lista Cheia!\n");

    //mover elementos uma casa pro lado
    int aux = lista->ocupacao;
    while(aux != 0){
        lista->array[aux] = lista->array[aux - 1]; // recebe elemento da pos anterior
        aux--; // ando uma posição pra tras
    }

    /* rascunho 
    int *p = (lista->array + lista->ocupacao);
    */


    lista->ocupacao++; // recebe um valor acima do inicial
    lista->array[0] = elemento; // posicao inicial recebe o elemento
}

/*=========================================================
    Função que acessa e retorna o elemento no inicio da lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
    Retorno:
		elemento que está na posição 0
  =========================================================*/
int acessarInicioLista(TLista const * const lista){
    if(listaEstaVazia(lista)) printf("Lista Vazia!\n");

    return lista->array[0]; // retornando elemento da pos 0
}

/*=========================================================
    Função que retira um elemento no inicio da lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
      2 - elemento - elemento a ser inserido no inicio da lista
  =========================================================*/
void retirarIniciolista(TLista * const lista){
    if(listaEstaVazia(lista)) printf("Lista Vazia!\n");

    int aux = 0;

    while(aux != (lista->ocupacao - 1)){ // vai rodar até bater no antigo ultimo elemento
        lista->array[aux] = lista->array[aux + 1]; // recebe elemento da pos seguinte
        aux++; // anda uma posicao  pra frente
    }
    lista->ocupacao--; // recebe um valor abaixo do inicial
}
