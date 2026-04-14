
#ifndef PILHA_H
#define PILHA_H

struct NO{
    int dado;
    struct NO * proximo;
};

typedef struct{
    int tamanho;
    struct NO * topo;
}TPilha;

// métodos: inicializar pilha
/*=========================================================
    Função para inicializar a pilha
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void inicializarPilha(TPilha * const pilha);

/*=========================================================
    Função que verifica se a pilha está vazia
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
    Retorno:
        != 0   - pilha está vazia
        0      - pilha não está vazia
  =========================================================*/
int pilhaEstaVazia(TPilha const * const pilha);

/*=========================================================
    Função para acessar o topo da pilha
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
    Retorno:
        valor do elemento no topo da pilha
  =========================================================*/
int acessarPilha(TPilha const * const pilha);

/*=========================================================
    Função para inserir um elemento na pilha
    Parametros: 
        1 - pilha    - ponteiro para a struct com os dados da pilha
        2 - elemento - valor a ser inserido na pilha
  =========================================================*/
void empilhar(TPilha * const pilha, int elemento);

/*=========================================================
    Função para remover um elemento da pilha
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void desempilhar(TPilha * const pilha);
/*=========================================================
    Função que libera o espaço de memória usado pela pilha
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void liberarPilha(TPilha * const pilha);

/*=========================================================
    Função para mostrar os elementos da pilha
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void mostrarPilha(TPilha const * const pilha);

#endif