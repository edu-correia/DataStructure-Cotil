#include <stdio.h>
#include <stdlib.h>

void print(int *abc, int *a, int *b){
    for (int i = 0; i < 10; i++)
    {
        abc[i] = 0;
        printf("%d ", *(abc+i));
        // OU
        // printf("%d", abc[i]);
    }
    *a = 10;
    *b = 10;
}

int main(){
    int abc[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *a, *b;

    print(abc, a , b);
    printf("%d %d", *a, *b);
}