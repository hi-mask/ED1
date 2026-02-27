typedef struct{
    int capacidade;
    int *array;
}SET;

int lerTamanho();

void criarConjunto(SET * const conjA);

void exibirConjunto(SET const * const conjA);

int lerElemento();

int realizarBusca(SET const * const conjA, int elemento);

void ordenarConjunto(SET const * const conjA);

void copiarConjunto(SET * const conjCopia, SET const * const conjOriginal);

int realizarBuscaBinaria(SET const * const conj, int elemento);