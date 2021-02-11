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
        printf("%c", temp->data);
    }
}

int checkBalancedParentheses(char *string, int tam){
    struct Node* temp = NULL;
    for(int i = 0; i < tam; i++){
        if((string[i] == '(') || (string[i] == '[') || (string[i] == '{')){
            temp = push(temp, string[i]);
        }else if((string[i] == ')') || (string[i] == ']') || (string[i] == '}')){
            if((temp == NULL) || !((temp->data == '(') && (string[i] == ')') || (temp->data == '[') && (string[i] == ']') || (temp->data == '{') && (string[i] == '}'))){
                return 0;
            }else{
                temp = pop(temp);
            }
        }
    }

    return ((temp == NULL) ? 1 : 0);
}

int main(){
    int res = checkBalancedParentheses("[({})[]]", 8);
    printf("%s\n", ((res == 1) ? "Passou!" : "Nao passou!"));
}