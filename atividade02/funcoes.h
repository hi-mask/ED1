typedef struct{
    int capacidade;
    int *array;
}SET;

int lerTamanho();

void criarConjunto(SET * const conjA);

void exibirConjunto(SET const * const conjA);

void realizarBusca(SET const * const conjA);