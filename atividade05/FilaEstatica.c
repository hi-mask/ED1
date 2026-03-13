#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaEstatica.h"

/*=========================================================
    Função que mostra os dados da struct de uma fila
    Parametros: 
    	1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void dadosDaFila(TFila const * const fila){
  
}

/*=========================================================
    Função que cria e inicializaa uma fila
    Parametros: 
		1 - tamanho - define a quantidade de elementos que a fila contem
    	2 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void criarFila(int tamanho, TFila *const fila){
  fila->tamanho = tamanho;
  fila->quantidadeDeElementos = 0;
  fila->inicio = -1;
  fila->fim = -1;
  fila->array = malloc(fila->tamanho * sizeof(int)); // apontando para a primeira posição alocada
}
/*=========================================================
    Função que libera o espaco de memória usado pela fila
    Parametros: 
    	1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void liberarFila(TFila *const fila){
    free(fila->array);
    fila->tamanho = 0;
    fila->quantidadeDeElementos = 0;
    fila->inicio = 0;
    fila->fim = 0;
    fila->array = NULL;
}
/*=========================================================
    Função que verifica se a fila esta vazia
    Parametros: 
    	1 - fila - ponteiro para a struct com os dados da fila
	Retorno:
		!= 0 	- fila esta vazia
		0 		- fila não esta vazia
  =========================================================*/
int filaEstaVazia(TFila const *const fila){
    if(fila->quantidadeDeElementos == 0) return 1;
    
    return 0;
}
/*=========================================================
    Função que verifica se a fila esta cheia
    Parametros: 
    	1 - fila - ponteiro para a struct com os dados da fila
	Retorno:
		!= 0 	- fila esta cheia
		0 		-  fila não esta cheia
  =========================================================*/
int filaEstaCheia(TFila const *const fila){
    if(fila->quantidadeDeElementos == fila->tamanho) return 1;

    return 0;
}
/*=========================================================
    Função para mostrar a fila
    Parametros: 
    	1 - fila - ponteiro para a struct com os dados da fila
	Retorno:
		ponteiro para a string com os dados da fila
  =========================================================*/
char* mostrarFila(TFila const *const fila){
	char *str = malloc(256 * sizeof(char));

  if(filaEstaVazia(fila)){
    sprintf(str, "Fila = { }");
    return str;
  }

  sprintf(str, "Fila = { ");

  int i = fila->inicio;
  char strAux[10];
  int cont = 0;

  for(cont = 0; cont < fila->quantidadeDeElementos; cont++){
      sprintf(strAux, " %d ", fila->array[i]);
      strcat(str, strAux);
      i++;

      if(i == fila->tamanho) i = 0;
  }
  strcat(str, " }");
  
  return str;
}
/*=========================================================
    Função para incluir um elemento na fila
    Parametros: 
		1 - elemento a ser incluido na fila
    	2 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void enfileirar(int elemento, TFila *const fila){
    if(filaEstaCheia(fila)) return;
      fila->fim++; // incrementando o fim (andando)

      if(fila->fim >= fila->tamanho) fila->fim = 0; // se ele estourou a fila, ele é movido pra posição 0

      fila->array[fila->fim] = elemento; //guardando na posição
      fila->quantidadeDeElementos++; // aumentando o numero de elementos presentes na fila
}
/*=========================================================
    Função para retirar um elemento da fila
    Parametros: 
    	1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void desenfileirar(TFila *const fila){
    if(filaEstaVazia(fila)) return;
      fila->inicio++; /* mexendo no inicio (deixando o antigo inicio da fila de lado,
       como se estivesse liberando)*/
      
      if(fila->inicio >= fila->tamanho) fila->inicio = 0; /* se ele estourou a fila,
       ele é movido pra posição 0 */

// o inicio pode chegar no fim, mas o fim nao pode chegar no inicio

      fila->quantidadeDeElementos--; //diminui um elemento, já que o antigo inicio foi tirado da fila

      if(filaEstaVazia(fila)) fila->inicio = -1, fila->fim = -1; /* se a fila FICOU vazia,
       resetamos a posição de fim e inicio*/
}
/*=========================================================
    Função para acessar um elemento da fila
    Parametros: 
    	1 - fila - ponteiro para a struct com os dados da fila
	Retorno:
		elemento do inicio da fila
  =========================================================*/
int acessar(TFila const *const fila){
	if(filaEstaVazia(fila)) return 1;

  return fila->array[fila->inicio]; // retornando o elemento na posição inicio da fila neste array
}
