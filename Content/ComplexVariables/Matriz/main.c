#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    float **md;

    int l = 5, c = 5;

    md = (float **)malloc(l * sizeof(float*));

    for(int i = 0; i < l; i++){
        md[i] = (float*)malloc(c * sizeof(float));
        memset(md[i], 0, sizeof(float) * c);
    }

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            scanf("%f", &md[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++)
            printf("%f ", md[i][j]);
        printf("\n");
    }
}