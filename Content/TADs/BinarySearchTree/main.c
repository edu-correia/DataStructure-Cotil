#include <stdio.h>
#include <stdlib.h>

struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
};

struct BstNode* insert(struct BstNode* root, int x){
    if(root == NULL){
        struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));
        newNode->data = x;
        newNode->left = newNode->right = NULL;
        root = newNode;
    }else if(x <= root->data){
        root->left = insert(root->left, x);
    }else{
        root->right = insert(root->right, x);
    }

    return root;
}

int search(struct BstNode* root, int x){
    if(root == NULL){
        return 0;
    }else if(root->data == x){ 
         return 1;
    }else if(x <= root->data){
        return search(root->left, x);
    }else{
        return search(root->right, x);
    }
}

struct BstNode* findMin(struct BstNode* root){
    while(root->left != NULL){
        root = root->left;
    }

    return root;
}

struct BstNode* delete(struct BstNode* root, int x){
    if(root == NULL) return root;
    if(x < root->data){
        root->left = delete(root->left, x);
    }else if(x > root->data){
        root->right = delete(root->right, x);
    }else{
        if(root->right == NULL && root->left == NULL){
            free(root);
            root = NULL;
        }else if(root->right == NULL){
            struct BstNode* temp = root;
            root = temp->left;
            free(temp);
        }else if(root->left == NULL){
            struct BstNode* temp = root;
            root = temp->right;
            free(temp);
        }else{
            struct BstNode* temp = findMin(root);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }

    return root;
}

int main(){
    struct BstNode* root = NULL;
    
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 23);
    root = insert(root, 28);
    root = insert(root, 27);
    root = delete(root, 25);
    int res = search(root, 25);
    printf("%s\n", (res == 1 ? "Found!" : "Not Found!"));
}