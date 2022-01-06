//reverse a linked list...
#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

void push(int a){
    struct node * new_node;
    new_node = malloc(sizeof(struct node));
    if(head == NULL){
        head = new_node;
        head -> data = a;
        head -> next = NULL;
    }
    else{
        new_node -> next = head;
        new_node -> data = a;
        head = new_node;
    }
}

void display(){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ",temp-> data);
        temp = temp -> next;
    }
    printf("\n \n");
}

void reverse(){
    struct node* prev =head;
    struct node* temp = head -> next;
    struct node* post = temp-> next;
    
    while(post != NULL){
        temp->next = prev;
        prev = temp;
        temp = post;
        post = post -> next; 
    }
    temp ->  next = prev;
    head -> next = NULL;
    
    head = temp;
}

int main(){
    for(int i=0;i< 10;i++){
        push(i);
    }
    display();
    
    reverse();
    display();
    
    
    return 0;
}
