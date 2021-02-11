//Aluno 1: Eduardo Correia - 19120
//Aluno 2: Gianni Labella - 19124

#include <stdio.h>

#include <stdlib.h>

#include "tenda.h"

Fila * cria(void) {
    Fila * l = (Fila *) malloc(sizeof(No));

    l->ini = NULL;
    l->fim = NULL;
    return l;
}

int conta(Fila *f) {
    No * aux = f->ini;
    int count = 1;

    if (f->ini == NULL)
    {
        return 0;
    }

    while (aux != f->fim)
    {
        count++;
        aux = aux->prox;
    }
    
    return count;
}

void insere(Fila* f) {
    No * novo = (No *) malloc(sizeof(No));

    if (f->ini == NULL)
    {
        novo->senha = 1;
        novo->prox = NULL;
        f->ini = novo;
        f->fim = novo;
    }
    else
    {
        novo->senha = (f->fim->senha + 1);
        novo->prox = NULL;
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int retira (Fila* f){
    No * p = f->ini;
    f->ini = p->prox;

    return p->senha;
}

void imprime (Fila* f){
    No * aux = f->ini;

    do
    {
        printf("%d\n", aux->senha);
        aux = aux->prox;
    }
    while (aux != NULL);
}

void clear (void){
    system("cls");
}

int vazia (Fila* f) {
    return f->ini == NULL;
}

void libera (Fila* f) {
    No * aux = f->ini;

    do
    {
        free(aux);
        aux = aux->prox;
    }
    while (aux != NULL);
    
    free(f->ini);
    free(f->fim);
    free(f);
}