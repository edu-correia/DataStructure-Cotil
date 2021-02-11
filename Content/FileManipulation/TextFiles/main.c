#include <stdio.h>
#include <stdlib.h>

int continueProcess(){
    int res;
    printf("Deseja continuar?\nDigite 0 para 'Nao' e 1 para 'Sim'.\n");
    scanf("%d", &res);
    return res;
}

int showData(){
    FILE *arq;
    char name[101];
    int ra, result;

    arq = fopen("teste.txt", "rt");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }

    system("cls");
    printf("Dados armazenados:\n\n");
    while((result = fscanf(arq, "%d %s", &ra, name) != EOF)){
        printf("%d\t%s\n", ra, name);
    }
    printf("\n");

    fclose(arq);

    return continueProcess();
}

int addData(){
    FILE *arq;
    int ra, result;
    char name[101];

    system("cls");
    printf("Digite o RA e o nome do aluno:\n");
    printf("RA: ");
    scanf("%d", &ra);
    printf("Nome: ");
    scanf("%s", name);

    arq = fopen("teste.txt", "at");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }

    result = fprintf(arq, "\n%d %s", ra, name);

    if(result == EOF) printf("Erro ao gravar os dados!");
    else printf("Dados gravados com sucesso!\n\n");

    fclose(arq);

    return continueProcess();
}

int deleteData(){
    FILE *arq;

    system("cls");
    if(continueProcess() == 0){
        return 0;
    }

    arq = fopen("teste.txt", "wt");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }else{
        printf("Dados excludos com sucesso!\n\n");
    }

    fclose(arq);

    return continueProcess();
}

int main(){
    int input = 100;

    while(input != 0){
        system("cls");
        printf("===========================\n");
        printf("Escolha uma opcao: \n");
        printf("1 - Visualizar os dados armazenados.\n");
        printf("2 - Adicionar um registro.\n");
        printf("3 - Excluir todos os RAs armazenados.\n");
        printf("===========================\n\n");
        printf("Opcao: ");
        scanf("%d", &input);

        switch (input){
            case 1:
                input = showData();
                break;
            case 2:
                input = addData();
                break;
            case 3:
                input = deleteData();
                break;
            case 0: 
                exit(0);
                break;
            default:
                printf("Valor inválido!\n");
                break;
        }
    }
}