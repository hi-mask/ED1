typedef struct{
    int capacidade;
    int *array;
}SET;

int lerTamanho();

void criarConjunto(SET * const conjA);

void exibirConjunto(SET const * const conjA);

int lerElemento();

int realizarBusca(SET const * const conjA, int elemento);