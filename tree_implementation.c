#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BST{
    int data;
    struct BST* left;
    struct BST* right;
}node;

void preorder(node* root){
    if(root != NULL){
        printf("%d ",root -> data);
        preorder(root->left);
        preorder(root-> right);
    }
}

void postorder(node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
    
}

void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root -> right);
    }
    
}

node* create(){
    int entry;
    node* temp;
    temp = (node*)malloc(sizeof(node));
    printf("Enter number to add : ");
    scanf("%d",&entry);
    temp -> data = entry;
    temp -> right = NULL;
    temp -> left = NULL;
    
    return temp;
}

void insert(node* root, node* temp){
    if(root -> data > temp -> data){
        if(root -> left != NULL){
            insert(root -> left, temp);
        }
        else{
            root -> left = temp;
        }
    }
    if(root -> data < temp -> data){
        if(root -> right != NULL){
            insert(root -> right, temp);
        }
        else{
            root -> right = temp;
        }
    }
}

int main(){
    int choice,data;
    node* root = NULL;
    node* temp;
    do{
        temp = create();
        if(root == NULL){
            root = temp;
        }
        else{
            insert(root,temp);
        }
        printf("Enter choice(y=1/n=0)");
        scanf("%d",&choice);
    }while(choice == 1);
    
    printf("preorder :: \n");
    preorder(root);
    printf("\n");
    printf("inorder :: \n");
    inorder(root);
    printf("\n");
    printf("postorder :: \n");
    postorder(root);
    printf("\n");
}


