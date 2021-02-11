//Prova de Estrutura de Dados
//Nome: Eduardo Henrique dos Santos Correia
//RA: 19120
//Data: 30/09/2020

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

NoFatia * inicializa(){
    return NULL;
}

NoFatia * criaNovaFatia(int h, char t){
    NoFatia * aux = (NoFatia *) malloc(sizeof(NoFatia));
    aux->altura = h;
    aux->tipo = t;
    aux->prox = NULL;
    return aux;
}

NoFatia * insere(NoFatia * l, int h, char t){
    NoFatia * nova = criaNovaFatia(h, t);
    NoFatia * aux=l;
    if(aux!=NULL){
        while(aux->prox!=NULL){
            aux=aux->prox;
        };
        aux->prox=nova;
    }else{
        l=nova;
    }

     return l;
}

void impFatias(NoFatia * l){
    NoFatia * aux = l;

    while(aux != NULL){
        printf("%d - %c \n", aux->altura, aux->tipo);
        aux = aux->prox;
    }
}

void canoNoFinal(NoFatia* fatias){
    NoFatia * aux;

    for(aux = fatias; aux != NULL; aux = aux->prox){
        if(aux->prox == NULL){
            if(aux->tipo == 'N'){
                aux->prox = insere(aux->prox, aux->altura, 'C');
            }
        }
    }
}

int faseImpossivel(NoFatia* fatias, int puloMaximo){
    NoFatia * aux;

    for(aux = fatias; aux != NULL; aux = aux->prox){
        if(aux->altura > puloMaximo) return 1;
    }

    return 0;
}