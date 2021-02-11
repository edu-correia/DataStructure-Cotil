#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    // Cria um bloco na memória chamado temp: 
    //Tipo_da_estrutura* nome = ()funcao_de_pedir_espaco_na_memoria(tipo_da_estrutura_para_informar_o_tamanho);
    temp->data = x; //Armazena o valor passado no nó temporário
    temp->next = head; // Passa a referenciar o primeiro item da lista. DETALHE: SE TEMP FOR O PRIMEIRO ITEM DA LISTA ELE DEVOLVE "NULL", SENÃO ELE DEVOLVE O ENDEREÇO DO PRIMEIRO ITEM.
    head = temp; // Vira o primeiro item da lista, ou seja, toda vez que alguém referenciar a cabeça da lista, será redirecionado a este item.
    return head; //Devolve a lista modificada depois da inserção
}

struct Node* insertSpecific(struct Node* head, int x, int pos){
    //Primeira parte, cria um novo bloco de memória
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = x;
    temp1->next = NULL;

    // Insere x no começo, caso a posição é igual a 1.
    // Se a posição for 1, faz a mesma coisa que a função de insert() padrão
    if(pos == 1){
        temp1->next = head;
        head = temp1;
        return head;
    }

    struct Node* temp2 = head; // Faz uma "cópia" da cabeça da lista 
    for(int i = 0; i < pos-2; i++){ //Faz um Loop For para achar o nó da lista em que se encontra a posição passada pelo usuário. 
        temp2 = temp2->next;
    } // Porque (-2) na condição? Você tem que desconsiderar que a lista começa no zero, mas o número passado pelo usuário não e o programa também tem que encontrar a posição anterior para poder fazer os links. 
    temp1->next = temp2->next; // O novo nó redireciona para o próximo nó na lista depois do nó que vai vir antes dele.
    temp2->next = temp1; // O nó achado no loop(nó que vai vir antes do novo nó) aponta para o novo nó.
    return head; // Retorna a cabeça da lista já modificada
}

struct Node* deleteSpecific(struct Node* head, int pos){
    struct Node* temp1 = head;

    if(pos == 1){
        head = temp1->next;
        free(temp1);
        return head;    
    }

    for(int i = 0; i < pos-2; i++){ 
        temp1 = temp1->next;
    }

    struct Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    return head;
}

struct Node* reverseList(struct Node* head){
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;

    while(current != NULL){
        next = current->next; 
		current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

	return head;
}

void printRecursive(struct Node* head){
    if(head == NULL) return;

    printf("%d ", head->data);
    printRecursive(head->next);
}

void reversePrintRecursive(struct Node* head){
    struct Node* temp = reverseList(head);
    printRecursive(temp); 

    // OU

    // if(head == NULL) return;
    // reversePrintRecursive(head->next);
    // printf("%d ", head->data);
}

void printAll(struct Node* head){
    struct Node* temp = head; //Faz uma "cópia"(mas não duplica a memória) da cabeça para poder manipular a lista. 
    while(temp != NULL){ //Verifica se o item da lista não é NULL, ou seja, verifica se não é último
        printf("%d ", temp->data); //Printa o dado dentro do bloco temporário
        temp = temp->next; // Anda mais uma casa dentro da lista
    }
}

int main(){
    int n, i , x; //Criação de variáveis de apoio ao código
    struct Node* head = NULL; // Criando a cabeça do código e a definindo como NULL, ou seja, declarando que a lista está vazia
    printf("How many numbers?\n"); // Pergunta quantidade de números
    scanf("%d", &n); // Lê a quantidade digitada pelo usuário
    for(i = 0; i < n; i++){ // Loop For com base no número digitado pelo usuário
        printf("Enter a number: "); //Pergunta um número
        scanf("%d", &x); // Pega o número digitado pelo usuário
        head = insert(head, x); // Passa  para a função insert(), o atual estado da cabeça da lista e o número a ser inserido, essa função devolve o estado final da lista, após a inserção.
    }
    head = insertSpecific(head, 1, 1); // Lista: 1
    head = insertSpecific(head, 2, 2); // Lista: 1, 2
    head = insertSpecific(head, 3, 1); // Lista: 3, 1, 2
    head = insertSpecific(head, 4, 4); // Lista: 3, 1, 2, 4
    head = deleteSpecific(head, 4);
    printAll(head); // Executa a função printAll() que printa todos os dados da lista
    head = reverseList(head);
    printf("\n=====================\n");
    printAll(head);
}