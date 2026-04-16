#include <stdio.h>
#include "listaArray.h"
#include <stdlib.h>
#include <time.h>
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
void liberarLista(TLista * const lista){
    free(lista->array);
    lista->tamanho = 0;
    lista->ocupacao = 0;
    lista->array = NULL;
}

/*=========================================================
    Função para mostrar a lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void mostrarLista(TLista const * const lista){
    if(listaEstaVazia(lista)){
        printf("Lista = { }\n");
        return;
    }

    printf("Lista = { ");

    int *p = lista->array;
    int *fim = lista->array + lista->ocupacao;

    while(p < fim){
        if(p == fim -1){
            printf("%d ", *p);
            break;
        }
        printf("%d, ", *p);
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
		0 		- lista não esta cheia
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
		0 		- lista não esta cheia
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
    if(listaEstaCheia(lista)){ 
        printf("Lista cheia!\n"); 
        return; 
    } //Guardo elementos no array na posicao de ocupação
    int * const p = lista->array; 
    *(p + lista->ocupacao) = elemento;

    printf("O elemento %d foi inserido no fim!\n", elemento);

    lista->ocupacao++;
}

/*=========================================================
    Função que acessa e retorna o elemento no fim da lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
    Retorno:
		- Elemento na posição ocupação - 1
  =========================================================*/
int acessarFimLista(TLista const * const lista){
    if(listaEstaVazia(lista)){
        printf("Lista vazia!\n");
        return -1;
    }
    int const * const p = lista->array + lista->ocupacao - 1;
    printf("Elemento no fim da lista: ");
    return *p;
}

/*=========================================================
    Função que retira um elemento no fim da lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void retirarFimlista(TLista * const lista){
    if(listaEstaVazia(lista)){
        printf("Lista Vazia!\n");
        return;
    }
    printf("O fim da lista foi retirado!\n");
    lista->ocupacao--;
}

/*=========================================================
    Função que insere um elemento no inicio da lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
        2 - elemento - elemento a ser inserido no inicio da lista
  =========================================================*/
void inserirInicioLista(TLista * const lista, int elemento){
    if(listaEstaCheia(lista)){ 
        printf("Lista Cheia!\n"); 
        return; 
    } //mover elementos uma casa pro lado
    int *aux = (lista->array + lista->ocupacao); 
    while(aux != lista->array){ 
        *aux = *(aux - 1); // to pegando o elemento da pos anterior 
        aux--; // andei com o ponteiro pra trás, até chegar no inicio 
    } 
    lista->ocupacao++; 
    *aux = elemento; // parou no inicio

    printf("O elemento %d foi inserido no inicio!\n", elemento);

}

/*=========================================================
    Função que acessa e retorna o elemento no inicio da lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
    Retorno:
      - Elemento na posição inicial
  =========================================================*/
int acessarInicioLista(TLista const * const lista){
    if(listaEstaVazia(lista)){
        printf("Lista vazia!\nTem Nada\n");
        return -1;
    }
    
    int const * const p = lista->array;
    printf("Elemento no inicio da lista: "); 
    return *p; // retornando elemento da pos 0
}

/*=========================================================
    Função que retira um elemento no inicio da lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void retirarIniciolista(TLista * const lista){
    if(listaEstaVazia(lista)){
        printf("Lista Vazia!\n");
        return; 
    } 
    int *aux = lista->array; 
    int *fim = (lista->array + lista->ocupacao - 1); 
    while(aux != fim){ 
        *aux = *(aux + 1); 
        aux++; 
    }
    printf("O inicio da lista foi retirado!\n");
    lista->ocupacao--; // recebe um valor abaixo do inicial
}

/*=========================================================
    Função que insere um elemento na posicao desejada da lista
    Parametros: 
        1 - lista - ponteiro para a struct com os dados da lista
        2 - posicao - posicao desejada da lista para receber o elemento
        3 - elemento - elemento a ser inserido na posicao desejada da lista
  =========================================================*/
void inserirPosicaoLista(TLista * const lista, int posicao, int elemento){
    if(listaEstaCheia(lista)){
        printf("Lista Cheia!\n"); 
        return;
    }
    // negativo ou ultrapassa ocupação(unica pos valida)
    if(posicao < 0 || posicao > lista->ocupacao){
        printf("Posicao invalida!\n");
        return;
    }

    int *aux = (lista->array + lista->ocupacao);
    while(aux > lista->array + posicao){
        *aux = *(aux - 1);
        aux--;
    }
    lista->ocupacao++;
    *aux = elemento;
    printf("\nElemento %d inserido na posicao %d\n", *aux, posicao);
}

/*=========================================================
    Função que acessa e retorna o elemento na posicao desejada da lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
        2 - posicao - posicao desejada da lista a ser exibida
  =========================================================*/
int acessarPosicaoLista(TLista const * const lista, int posicao){
    if(listaEstaVazia(lista)){
        printf("Lista vazia!\n");
        return -1;
    }

    if(posicao < 0 || posicao >= lista->ocupacao){
        printf("Posicao invalida!\n");
        return -1;
    }

    int const * const p = lista->array + posicao;
    printf("Elemento na posicao %d: ", posicao);
    return *p;
}

/*=========================================================
    Função que retira um elemento na posicao desejada da lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
        2 - posicao - posicao desejada da lista a ser retirada
  =========================================================*/
void retirarPosicaoLista(TLista * const lista, int posicao){
    if(listaEstaVazia(lista)){
        printf("Lista vazia!\n");
        return;
    }
    if(posicao < 0 || posicao >= lista->ocupacao){
        printf("Posicao invalida!\n");
        return;
    }

    int *aux = (lista->array + posicao);
    int *fim = (lista->array + lista->ocupacao - 1);
    while(aux != fim){
        *aux = *(aux + 1);
        aux++;
    }
    lista->ocupacao--;
    printf("\nElemento retirado na posicao %d\n", posicao);
}

/*=========================================================
    Função que retira um elemento em uma posicao aleatoria da lista
    Parametros: 
    	1 - lista - ponteiro para a struct com os dados da lista
    Retorno:
		!= 0 	- Sucesso na remoção
		0 		- lista esta vazia, falha na remoção
  =========================================================*/
int removerAleatoriamente(TLista * const lista){ // FUNÇÃO FEITA PELA MAL INTERPRETAÇÃO
    if(listaEstaVazia(lista)){
        return 0; // deu erro
    }
    int posAleatoria = rand() % lista->ocupacao;

    int *aux = (lista->array + posAleatoria);
    int *fim = (lista->array + lista->ocupacao - 1);
    while(aux != fim){
        *aux = *(aux + 1);
        aux++;
    }
    lista->ocupacao--;
    printf("Elemento removido na posicao aleatoria: %d\n", posAleatoria);

    return 1; // deu certo
}

/*=========================================================
    Função que busca um elemento na lista e retorna sua posição
    Parametros: 
        1 - lista - ponteiro para a struct com os dados da lista
        2 - elemento - valor a ser buscado na lista
    Retorno:
        >= 0   - posição do elemento na lista
        -1     - elemento não encontrado
  =========================================================*/
int realizarBusca(TLista const * const lista, int elemento){
    int posAchada = -1;
    int *aux = lista->array;
    int *fim = lista->array + lista->ocupacao;
    int i = 0;

    while(aux < fim){
        if(*aux == elemento && posAchada == -1){
            posAchada = i;
        }
        aux++;
        i++;
    }

    return posAchada;

}

/*=========================================================
    Função que remove um elemento da lista
    Parametros: 
        1 - lista - ponteiro para a struct com os dados da lista
        2 - elemento - valor a ser removido da lista
    Retorno:
        != 0   - sucesso na remoção
        0      - lista vazia ou elemento não encontrado
  =========================================================*/
int removerElementoQualquer(TLista * const lista, int elemento){
    if(listaEstaVazia(lista)){
        return 0;
    }

    int pos = realizarBusca(lista, elemento);

    if(pos == -1){
        printf("\nO elemento %d nao esta na lista!\n", elemento);
        return 0;
    }

    retirarPosicaoLista(lista, pos);
    return 1; // deu certo

}

int inserirOrdenadamente(TLista * const lista, int elemento){
    if(listaEstaCheia(lista)){
        return 0; // deu erro
    }
    int *aux = lista->array;
    int *fim = lista->array + lista->ocupacao;
    int pos = 0;

    if(listaEstaVazia(lista)){
        *aux = elemento;
        printf("\nElemento inserido na posicao: 0\n");
        lista->ocupacao++;
        return 1;
    }

    while(aux < fim && *aux < elemento){
        aux++;
        pos++;
    }

    inserirPosicaoLista(lista, pos, elemento);
    return 1; // deu certo
} 