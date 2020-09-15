/*
RA - NOME

*/
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

Lista * inicializa()
{
    return NULL;
}

int vazia (Lista* l)
{
    return l==NULL;
 }

 Lista * criaNo(int v)
 {
     Lista * aux;
     aux=(Lista *) malloc(sizeof(Lista));

     if(aux!=NULL)
     {
         aux->info = v;
         aux->prox = NULL;
     }

     return aux;
 }

 Lista* insere (Lista* l, int i)
 {
      Lista * novo = criaNo(i);
      novo->prox = l;
      return novo;
 }

void imprime (Lista* l)
{
    Lista * p;
    if(vazia(l)){
        printf("Lista vazia!");
    }
    else{
        printf(" | ");
        for(p=l; p!=NULL; p=p->prox)
        {
            printf("%d | ",p->info);
        }
        printf("\n");
    }
}

Lista * separa(Lista * l, int n){
    Lista * p;
    Lista * l2;
    for(p = l; p!=NULL; p = p->prox){
        if(p->info == n){
            l2 = p->prox;
            p->prox = NULL;
            break;
        }
    }

    return l2;
}

Lista * concatena (Lista * l1, Lista* l2){
    Lista * p;
    for(p = l1; l1!=NULL; l1 = l1->prox){
        if(l1->prox == NULL){
            l1->prox = l2;
            break;
        }
    }

    return p;
}

Lista * constroi (int n, int* v){
    Lista * p;
    for(int i = n-1; i >= 0; i--){
        p = insere(p, v[i]);
    }

    return p;
}

Lista * retira_prefixo (Lista * l, int n){
    for(int i = 0; i < n; i++){
        l = l->prox;
        if(vazia(l)) break;
    }

    return l;
}
