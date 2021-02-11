#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    struct Node* next;
};

struct Node* push(struct Node* head, char x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = head;

    head = newNode;
    return head;
}

struct Node* pop(struct Node *head){
    struct Node* temp = head;
    head = temp->next;
    free(temp);

    return head;
}

void print(struct Node* head){
    struct Node* temp = head;
    for(temp; temp != NULL; temp = temp->next){
        printf("%c ", temp->data);
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    head = push(head, 'A');
    head = push(head, 'B');
    head = push(head, 'C');
    head = push(head, 'D');
    head = push(head, 'E');
    head = pop(head);
    head = pop(head);
    print(head);
}