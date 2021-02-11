#include <stdio.h>
#include <stdlib.h>

#define TAMVETOR 10

void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {

        for (j = 0; j < n - k; j++) {

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
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
    bubble_sort(arr, TAMVETOR);
    print(arr, TAMVETOR);
}