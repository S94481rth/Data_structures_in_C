//implementation of doubly linked list...
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};

/*
void push_end(int item);
void push_between(int item, int position);
void delete_beg();
void delete_end();
void delete_between(int position);
*/

struct node*head = NULL;

void push_beg(int item){
    struct node* new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(head == NULL){
        head = new_node;
        new_node -> data = item;
        new_node -> next = NULL;
        new_node -> prev = NULL;
    }
    else{
        new_node -> next  = head;
        new_node -> prev = NULL;
        new_node -> data = item;
        head -> prev = new_node;
        head = new_node;
    }
}
 
void push_end(int item){
    struct node* new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(head == NULL){
        head = new_node;
        new_node -> data = item;
        new_node -> next = NULL;
        new_node -> prev = NULL;
    }
    else{
        struct node*temp = head;
        while(temp -> next != NULL){
            temp = temp-> next;
        }
        temp-> next = new_node;
        new_node -> prev = temp;
        new_node -> data = item;
        new_node -> next = NULL;
    }
} 
 
void push_between(int item, int position){
    struct node* new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(head == NULL){
        head = new_node;
        new_node -> data = item;
        new_node -> next = NULL;
        new_node -> prev = NULL;
    }
    else{
        struct node*temp =head;
        for(int i=1;i<position-1;i++){
             temp = temp-> next;
             
             if(temp == NULL){
                 printf("\nInvalid\n");
             }
        }   
        new_node -> data = item;
        new_node -> prev = temp;
        new_node-> next = temp -> next;
        temp -> next -> prev = new_node;
        temp -> next = new_node;
        
    }
} 
 
void delete_beg(){
    if(head == NULL){
        printf("Invalivd");
    }
    else{
        struct node* temp = head;
        head -> next -> prev = NULL;
        head = head -> next;
        free(temp);
    }
}
 
void delete_end(){
    struct node*temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> prev -> next = NULL;
    free(temp);
}

void delete_between(int position){
    struct node*temp = head;
    if(position == 1){
        delete_beg();
    }
    else{
        for(int i=1;i<position;i++){
            temp = temp -> next;
        }
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        temp -> next = NULL;
        temp -> prev = NULL;
        free(temp);
    }
}
void display_beg(){
    struct node*temp = head;
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
} 

void display_end(){
    struct node*temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> prev;
    }
    printf("\n");
}
int main(){
    int choice,entry,position;
    printf("Enter your choice\n");
    
    do{
        printf("\n1 to push in beginning \n2 to push in the end\n");
        printf("3 to push in-between\n4 to delete at beginning\n");
        printf("5 to delete at end\n6 to delete in between\n");
        printf("7 to display from start\n8 to display from end\n");
        scanf("%d",&choice);
        switch (choice){
        case 1:
        printf("Enter number :: ");
        scanf("%d",&entry);
        push_beg(entry);
        break;
        
        case 2:
        printf("enter number :: ");
        scanf("%d",&entry);
        push_end(entry);
        break;
        
        case 3:
        printf("Enter number :: ");
        scanf("%d",&entry);
        printf("Enter position::");
        scanf("%d",&position);
        push_between(entry,position);
        break;
        
        case 4:
        delete_beg();
        break;
        
        case 5:
        delete_end();
        break;
        
        case 6:
        printf("Enter position::");
        scanf("%d",&position);
        delete_between(position);
        break;
        
        case 7:
        display_beg();
        break;
        
        case 8:
        display_end();
        break;
        }
    }while(choice != 0);
    
}
