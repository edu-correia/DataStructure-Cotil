#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct inscricao{
    char inscr[6];
    char nome[30];
    float nota;
};

typedef struct inscricao Inscricao;

void imprime(Inscricao vet[], int nEl) {
    for(int i = 0; i < nEl; i++){
        printf("%s \t\t %s \t\t %5.2f \n", vet[i].inscr, vet[i].nome, vet[i].nota);
    }
    printf("======================================\n");
}

int comp_nota (const void *x, const void *y) {
    int pri = ((struct inscricao *)x)->nota;
    int seg = ((struct inscricao *)y)->nota;
    return (seg - pri);
}

int comp_nome (const void *a, const void *b) {
    return strcmp (((struct inscricao *)a)->nome,((struct inscricao *)b)->nome);
}

int comp_inscr (const void *a, const void *b) {
    return strcmp (((struct inscricao *)a)->inscr,((struct inscricao *)b)->inscr);
}

void main(){
    Inscricao vInsc[5];

    strcpy(vInsc[0].inscr, "1");
    strcpy(vInsc[0].nome, "Joao");
    vInsc[0].nota = 7.2;

    strcpy(vInsc[1].inscr, "3");
    strcpy(vInsc[1].nome, "Maria");
    vInsc[1].nota = 9.0;

    strcpy(vInsc[2].inscr, "4");
    strcpy(vInsc[2].nome, "Pedro");
    vInsc[2].nota = 6.5;

    strcpy(vInsc[3].inscr, "5");
    strcpy(vInsc[3].nome, "Ana");
    vInsc[3].nota = 8.5;

    strcpy(vInsc[4].inscr, "2");
    strcpy(vInsc[4].nome, "Jorge");
    vInsc[4].nota = 4.0;

    //Imprime normal
    imprime(vInsc, 5);

    // Por Ordem de Nota
    qsort(vInsc, 5, sizeof(struct inscricao), comp_nota);
    imprime(vInsc, 5);

    // Por Ordem de Nome
    qsort(vInsc, 5, sizeof(struct inscricao), comp_nome);
    imprime(vInsc, 5);

    // Por Ordem de Inscrição
    qsort(vInsc, 5, sizeof(struct inscricao), comp_inscr);
    imprime(vInsc, 5);
}