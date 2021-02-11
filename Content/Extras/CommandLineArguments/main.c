#include <stdio.h>
#include <stdlib.h>

int main(int argc, int *argv[]){
    if(argc >= 2){
        for(int i = 1; i < argc; i++){
            printf("%s\n", argv[i]);
        }
    }else{
        printf("Você não passou nenhum argumento!");
    }
}