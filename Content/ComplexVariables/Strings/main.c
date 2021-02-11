#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGS 5

int findString(char m[][101], int tamM, char *s){
    for(int i = 0; i < tamM; i++){
        if(strcmp(m[i], s) == 0) return i+1;
    }
    return 0;
}

int main(){
    char strs[STRINGS][101];
    char keyWord[101];

    printf("Digite %d strings:\n", STRINGS);
    for(int i = 0; i < STRINGS; i++)
        gets(strs[i]);

    printf("Agora digite uma string para ser achada: ");
        gets(keyWord);

    int res = findString(strs, STRINGS, keyWord);
    printf("%s %d\n", (res > 0 ? "Palavra encontrada! Posição: " : "Palavra não encontrada!"), res);
}