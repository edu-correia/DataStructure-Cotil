/*
RA - NOME

*/
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
    Lista *l1, *l2,*l3;
    int vetor[5] = {5,4,3,2,1};


    l1=inicializa();
    l2=inicializa();
    l3=inicializa();

    l1 = insere(l1, 1);
    l1 = insere(l1, 12);
    l1 = insere(l1, 13);
    l1 = insere(l1, 5);
    l1 = insere(l1, 17);
    l1 = insere(l1, 3);

    //printf("Lista 1 - ORIGINAL\n");
   //imprime(l1);

    /*printf("Lista 1 - SEPARADA\n");
    imprime(l1);
    l2=separa(l1,5);
    imprime(l1);
    imprime(l2);*/

    /*
    printf("1) Lista 2 - SEPARADA NO ELEMENTO 5\n");
    imprime(l1);
    printf("1) Lista 2 - FILHA DE Lista 1\n");
    imprime(l2);
    */
/*
    printf("2) Lista 1 - REMONTADA COM Lista 2\n");
    l1 = concatena(l1,l2);
    imprime(l1);*/

/*
    l3 = constroi(5,vetor);
    printf("3) Lista 3 - MONTADA A PARTIR DE UM VETOR\n");
    imprime(l3);
    */

    l1 = retira_prefixo(l1,3);
    printf("4) Lista 1 - RETIRADOS 2 PRIMEIROS ELEMENTOS\n");
    imprime(l1);

    return 0;
}
