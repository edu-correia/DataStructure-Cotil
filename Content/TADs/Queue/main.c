#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Queue{
    struct Node* head;
    struct Node* tail;
};

struct Queue* create(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->head = NULL;
    q->tail = NULL;

    return q;
}

struct Queue* enqueue(struct Queue* q, int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if((q->head == NULL) && (q->tail == NULL)){
        q->head = q->tail = temp;
        return q;
    }else{
        q->tail->next = temp;
        q->tail = temp;
    }

    return q;
}

struct Queue* dequeue(struct Queue* q){
    struct Node* temp = q->head;

    if((q->head == NULL) && (q->tail == NULL)){
        return q;
    }else if(q->head == q->tail){
        q->head = q->tail = NULL;
    }else{
        q->head = temp->next;
    }
    free(temp);

    return q;
}

void print(struct Queue* q){
    struct Node* temp = q->head;
    for(temp; temp != NULL; temp = temp->next){
        printf("%d ", temp->data);
    }
    printf("\n");
}

int main(){
    struct Queue* q = create();

    q = enqueue(q, 2); 
    q = enqueue(q, 4); 
    q = enqueue(q, 6);
    q = enqueue(q, 8);
    q = enqueue(q, 10);
    q = dequeue(q);
    print(q);
}