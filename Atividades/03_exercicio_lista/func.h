#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

/*
RA - NOME

*/
struct lista{
    int info;
    struct lista * prox;
};

typedef struct lista Lista;

Lista * inicializa();
int vazia (Lista* l);
void imprime (Lista* l);
Lista* insere (Lista* l, int i);

Lista * separa(Lista * l, int n);
Lista * concatena (Lista * l1, Lista* l2);
Lista * constroi (int n, int* v);
Lista * retira_prefixo (Lista * l, int n);

#endif // FUNC_H_INCLUDED
