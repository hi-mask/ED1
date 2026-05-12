#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

int main(void){
    TFila teste;
    inicializarFila(&teste);
    mostrarFila(&teste);
    enfileirar(&teste, 10);
    mostrarFila(&teste);
    enfileirar(&teste, 114);
    enfileirar(&teste, 91);
    enfileirar(&teste, 14);

    desenfileirar(&teste);
    acessarInicio(&teste);
    mostrarFila(&teste);

    liberarFila(&teste);
}