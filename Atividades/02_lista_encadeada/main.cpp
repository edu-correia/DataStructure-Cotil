//Nome: Eduardo Correia
//Turma: 2INFD
//RA: 19120
//Matéria: Estrutura de Dados
//Assunto: Tipos Abstratos de Dados(TAD)
//Criado em: 25/08/2020
//Última vez modificado: 25/08/2020

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct lista {
    int x;
    int y;
    char nome[50];
    struct lista* ant;
    struct lista* prox;
};

typedef struct lista Lista;

Lista* inicializa (void){
    return NULL;
}

Lista* insere (Lista* l, int x, int y, char * nome){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->x = x;
    novo->y = y;
    strcpy(novo->nome, nome);
    novo->prox = l;
    novo->ant = NULL;

    if(l != NULL){
        l->ant = novo;
    }

    return novo;
}

float distancia(Lista * l1, Lista * l2){
    int x1 = l1->x;
    int y1 = l1->y;
    int x2 = l2->x;
    int y2 = l2->y;

    float d = sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));

    return d;
}

void imprime (Lista* l){
    Lista* p;
    Lista* a;
    float total = 0;

    for (p = l; p != NULL; p = p->prox){
        if(p->prox == NULL){
            a = p;
        }
    }

    for (p = a; p != NULL; p = p->ant){
        if(p->ant == NULL){
            total+= distancia(p, a);
            cout << "Distancia da [" << p->nome << "] ate a [" << a->nome << "]  =  " << distancia(p, a) << "km" << endl;
            cout << "====================================================" << endl;
            cout << "Distancia total = "<< total << endl;
            cout << "====================================================" << endl;
            return;
        }
        total+= distancia(p, p->ant);
        cout <<  "Distancia da [" << p->nome << "] ate a [" << p->ant->nome << "]  =  " << distancia(p, p->ant) << "km" << endl;
    }
}

int main()
{
    Lista* l; 
    l = inicializa();
    l = insere(l, 2, 2, "CIDADE UM"); 
    l = insere(l, 10, 4, "CIDADE DOIS");
    l = insere(l, 19, 8, "CIDADE TRES");
    l = insere(l, 16, 15, "CIDADE QUATRO");
    l = insere(l, 5, 19, "CIDADE CINCO");
    l = insere(l, 8, 10, "CIDADE SEIS");

    cout << fixed << setprecision(2);
    
    imprime(l);
    
    return 0;
}