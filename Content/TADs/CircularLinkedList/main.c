#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if(head == NULL){
        newNode->next = newNode;
    }else{
        newNode->next = head->next;
        head->next = newNode;
    }
    head = newNode;

    return head;
}

struct Node* removeNode(struct Node* head){
    struct Node* prev = head;
    struct Node* temp = head;

    while(prev->next != head){
        prev = prev->next;
    }

    prev->next = head->next;
    head = prev;
    free(temp);

    return head;
}

void print(struct Node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    struct Node* head = NULL;

    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = removeNode(head);
    print(head);
}