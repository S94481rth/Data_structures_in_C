//concatenate two linked lists...
#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* head2 = NULL;
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
void push2(int a){
    struct node * new_node;
    new_node = malloc(sizeof(struct node));
    if(head2 == NULL){
        head2 = new_node;
        head2 -> data = a;
        head2 -> next = NULL;
    }
    else{
        new_node -> next = head2;
        new_node -> data = a;
        head2 = new_node;
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


void display2(){
    struct node* temp = head2;
    while(temp != NULL){
        printf("%d ",temp-> data);
        temp = temp -> next;
    }
    printf("\n \n");
}

void concatenate(){
    struct node* temp = head;
    
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    
    temp -> next = head2;
}

int main(){
    for(int i=5;i>0;i--){
        push(i);
    }
    for(int i=10;i>5;i--){
        push2(i);
    }
    display();
    display2();
    concatenate();
    display();
    
    return 0;
}
