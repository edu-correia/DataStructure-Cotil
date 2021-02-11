#include <stdlib.h>
#include <iostream>
using namespace std;

struct no
{
	int info;
	struct no * prox;
	struct no * ant;
};

struct lista{
    struct no * iniLista;
    struct no * fimLista;
} ;

typedef struct no No;
typedef struct lista Lista;

Lista * inicializa()
{
    Lista * l = (Lista *) malloc(sizeof(No));

	l->iniLista=NULL;
	l->fimLista=NULL;
	return l;
}

/* função busca: busca um elemento na lista */
No * busca (Lista * l, int v)
{
	No * p = l->iniLista;
	do
	{
	  if(p->info == v) return p; //achou
	  p=p->prox;
	}while(p!=l->iniLista);
 	return NULL;       /* não achou o elemento */
}

void insere(Lista * l, int v)
{
	No * Novo = (No *) malloc(sizeof(No));
	Novo->info = v;
	if(l->iniLista==NULL)
	{
		Novo->prox = Novo->ant = Novo;
		l->iniLista=Novo;
		l->fimLista=Novo;
	}
	else
	{
		Novo->prox=l->iniLista;
		Novo->ant=l->fimLista;
		l->fimLista->prox = Novo;
		l->fimLista=Novo;
		l->iniLista->ant = Novo;
	}

}

void imprimeAsc(Lista * l)
{
	No * p=l->iniLista;
	do
	{
	  cout << p->info << endl;
	  p=p->prox;
	}while(p!=l->iniLista);
}

void imprimeDesc(Lista * l)
{
	No * p=l->fimLista;
	if(p==NULL) return;
	do
	{
	  cout << p->info << endl;
	  p=p->ant;
	}while(p!=l->fimLista);
}

/* função retira: retira elemento da lista */
Lista * retira (Lista * l, int v)
{
	No* p = busca(l,v);
	if (p == NULL){
		return l;   /* não achou o elemento: retorna lista inalterada */
	}
	/* retira elemento do encadeamento */
	if (l->iniLista == p)
		l->iniLista = p->prox;
	else
		p->ant->prox = p->prox;

	if (p->prox != NULL)
	   	p->prox->ant = p->ant;

	free(p);
   	return l;
}

int menorDistancia(Lista * l, int p1, int p2){
    int count1 = 0, count2 = 0;

    No * start = busca(l, p1);
    No * n1;
    No * n2;

    n1 = start;
    n2 = start;


    while(true){
        count1++;
        count2--;

        if(n1->prox->info == p2){
            return count1;
        }

        n1 = n1->prox;

        if(n2->ant->info == p2){
            return count2;
        }

        n2 = n2->ant;
    }
}

int main()
{
	Lista * lista;
    int dist=0;

	lista = inicializa();
	insere(lista,8);
	insere(lista,43);
	insere(lista,84);
	insere(lista,93);
	insere(lista,24);
	insere(lista,52);
	insere(lista,12);
	insere(lista,67);
	insere(lista,78);
	insere(lista,20);
	imprimeAsc(lista);

	cout << endl << endl;
    cout << "Menor distancia entre 84 e 20 = ";
    dist=menorDistancia(lista,84,20);
    if( dist<0)
        cout << "Antihorario! ("<<dist<<")" << endl;
    else
        cout <<"Horario! ("<<dist<<")"<<endl;

    cout << "Menor distancia entre 84 e 12 = ";
    dist=menorDistancia(lista,84,12);
    if( dist<0)
        cout << "Antihorario! ("<<dist<<")" << endl;
    else
        cout <<"Horario! ("<<dist<<")"<<endl;

	return 0;
}

