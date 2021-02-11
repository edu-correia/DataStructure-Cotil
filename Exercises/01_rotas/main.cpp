#include <iostream>
#include <cmath>

using namespace std;


//Arquivo separado: "FUNCS.h"
struct cidade{
    char nome[50];
    int x;
    int y;
};

typedef struct cidade Cidade;

Cidade* cria(char * cityName, int cityX, int cityY){
    Cidade* abc = (cidade*) malloc(sizeof(cidade));

    strcpy(abc->nome, cityName);
    abc->x = cityX;
    abc->y = cityY;
    
    return abc;
}

void libera (Cidade* c){
    free(c);
}

void acessa (Cidade * c, float* x, float* y, char * nome){

}

void atribui (Cidade * c, float x, float y, char nome[50]){
    
    strcpy(c->nome, nome);
    c->x = x;
    c->y = y;
}

float distancia (Cidade * c1, Cidade * c2){
    int x1 = c1->x;
    int x2 = c2->x;
    int y1 = c1->y;
    int y2 = c2->y;

    float d = sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));

    return d;
}
//Arquivo separado: "FUNCS.h"


int main(){
    Cidade* cidades[6];
    int nElCidades = 6;
    float caminho = 0, total = 0;

    cidades[0] = cria("Cidade 1", 2, 2);
    cidades[1] = cria("Cidade 2", 10, 4);
    cidades[2] = cria("Cidade 3", 19, 8);
    cidades[3] = cria("Cidade 4", 16, 15);
    cidades[4] = cria("Cidade 5", 5, 19);
    cidades[5] = cria("Cidade 6", 8, 10);

    for(int i = 0; i < nElCidades; i++){
        if(i == (nElCidades-1)){
            caminho = distancia(cidades[i], cidades[0]);
        }else{
            caminho = distancia(cidades[i], cidades[i+1]);
        }

        total += caminho;
    }

    cout << total << endl;

    return 0;
}