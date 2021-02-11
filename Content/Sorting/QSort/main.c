#include <stdio.h>
#include <stdlib.h>

#define TAMVETOR 10

int compareIntegers(const void *a, const void *b){
    int valueA = *(int*)a; // Pega a variável "a" e transforma em ponteiro de int(*int) e então acessa o valor dela e coloca na variável "valueA".
    int valueB = *(int*)b; //Mesma coisa da linha de cima

    if(valueA == valueB) return 0; // Se os números forem iguais a função retorna 0.
    else if(valueA < valueB) return -1; // Se A for menor que B a função retorna -1.
    else return 1; //Se A for maior que B a função retorna 1.
}

void print(int vetor[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(){
    int arr[TAMVETOR] = {1, 5, 9, 10, 3, 4, 2, 8, 7, 6};

    print(arr, TAMVETOR);

    qsort(arr, TAMVETOR, sizeof(int), compareIntegers);

    print(arr, TAMVETOR);
}