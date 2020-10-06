#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main()
{
    NoFatia * fatias = inicializa();

    fatias = insere(fatias, 3, 'N');
    fatias = insere(fatias, 5, 'N');
    fatias = insere(fatias, 5, 'N');
    fatias = insere(fatias, 6, 'C');
    fatias = insere(fatias, 10, 'N');
    canoNoFinal(fatias);
    impFatias(fatias);

    printf("\nSalto máximo : %d\n", 6);
    printf("\nTem fase impossivel? %d\n", faseImpossivel(fatias, 6));
    return 0;
}