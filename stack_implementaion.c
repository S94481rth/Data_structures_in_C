//lifo stacks implementation...
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct node{
    int data;
    struct node* next;
};

struct node * head = NULL;

void push(int a){
    struct node* new_node;
    new_node = malloc(sizeof(struct node));
    
    if(head == NULL){
        head = new_node;
        head -> data = a;
        head -> next = NULL;
    }
    else{
        new_node -> data = a;
        new_node -> next = head;
        head = new_node;
    }
}

void pop(){
    struct node*temp =head;
    head = head -> next;
    free(temp);
}

void display(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}


int main(){
    int choice,entry;
    do{
    printf("Enter your choice :: \n");
    printf("1 to push:: \n2 to pop:: \n3 to display:: \n4 to exit:: ");
    scanf("%d",&choice);
        switch (choice){
            case 1:
            printf("Enter element to push:: ");
            scanf("%d",&entry);
            push(entry);
            break;
            
            case 2:
            pop();
            break;
            
            case 3:
            display();
            break;
            
            case 4:
            break;
            
        }
    }while(choice != 4);
}


