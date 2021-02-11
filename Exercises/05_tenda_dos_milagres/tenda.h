struct no {
    int senha;
    struct no* prox;
};
typedef struct no No;

struct fila {
    No* ini;
    No* fim;
};
typedef struct fila Fila;

Fila* cria (void); //
void insere (Fila* f); //
int retira (Fila* f); //
int vazia (Fila* f);
void libera (Fila* f);
void imprime (Fila* f); //
void clear (void);
int conta(Fila *f); //