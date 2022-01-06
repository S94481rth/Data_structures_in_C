//fifo queue implementation...
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

void enqueue(int a){
    struct node* new_node;
    new_node = malloc(sizeof(struct node));
    
    if(head == NULL){
        head = new_node;
        head -> data = a;
        head -> next = NULL;
    }
    
    else{
        struct node* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = new_node;
        new_node -> data = a;
        new_node -> next = NULL;
    }
}

void dequeue(){
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
    printf("1 to enqueue:: \n2 to dequeue:: \n3 to display:: \n4 to exit:: ");
    scanf("%d",&choice);
        switch (choice){
            case 1:
            printf("Enter element to push:: ");
            scanf("%d",&entry);
            enqueue(entry);
            break;
            
            case 2:
            dequeue();
            break;
            
            case 3:
            display();
            break;
            
            case 4:
            break;
            
        }
    }while(choice != 4);
}


