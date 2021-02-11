#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

// Porque usar um PONTEIRO?
// • Quando vc cria um nó em uma função que não seja a main, quando vc acaba de executar essa função, a memória usada na função será apagada.

struct Node* insertBegin(struct Node* head, int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL){
        head = newNode;
        return head;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* insertEnd(struct Node* head, int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL){
        head = newNode;
        return head;
    }

    struct Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    newNode->prev = temp;
    temp->next = newNode;

    return head;
}

void print(struct Node* head){
    for(head; head != NULL; head = head->next){
        printf("%d", head->data);
    }
    printf("\n");
}

void reversePrint(struct Node* head){
    while(head->next != NULL){
        head = head->next;
    }

    for(head; head != NULL;head = head->prev){
        printf("%d", head->data);
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    head = insertBegin(head, 2);
    head = insertBegin(head, 3);
    head = insertBegin(head, 4);
    head = insertBegin(head, 5);
    head = insertEnd(head, 6);
    head = insertEnd(head, 7);
    print(head);
    reversePrint(head);
}