#ifndef LISTARRAY_H
#define LISTARRAY_H


typedef struct {
    int tamanho;
    int ocupacao;
    int *array;
}TLista;

/*=========================================================
    Função que mostra os dados da struct de uma lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void mostrarDadosLista(TLista const * const lista);

/*=========================================================
    Função que cria e inicializa uma lista
    Parametros: 
		1 - lista - define a quantidade de elementos que a lista contem
    	2 - tamanho - ponteiro para a struct com os dados da lista
  =========================================================*/
void inicializarLista(TLista * const lista, int tamanho);

/*=========================================================
    Função para mostrar a lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
	Retorno:
		ponteiro para a string com os dados da lista
  =========================================================*/
void mostrarLista(TLista const * const lista);

/*=========================================================
    Função que libera o espaco de memória usado pela lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void liberarLista(TLista *  const lista);

/*=========================================================
    Função que verifica se a lista esta vazia
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
	Retorno:
		!= 0 	- lista esta cheia
		0 		-  lista não esta cheia
  =========================================================*/
int listaEstaVazia(TLista const * const lista);

/*=========================================================
    Função que verifica se a lista esta cheia
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
	Retorno:
		!= 0 	- lista esta cheia
		0 		-  lista não esta cheia
  =========================================================*/
int listaEstaCheia(TLista const * const lista);

void inserirFimLista(TLista * const lista, int elemento);

int acessarFimLista(TLista const * const lista);

void retirarFimlista(TLista * const lista);

#endif