#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node*head = NULL;

struct node* create(){
    struct node*new_node;
    new_node = malloc(sizeof(struct node));
    return new_node;
}

void push(int entry){
    int flag=0;
    struct node*new_node = create();
    new_node -> data = entry;
    if(head == NULL){
        new_node -> next = NULL;
        head = new_node;
    }
    else{
        struct node*temp = head;
        struct node*future = temp -> next;
        if(entry < (head -> data)){
            new_node -> next = head ;
            head = new_node;
            return;
        }
        else{
            while(entry > (future -> data)){
            temp = temp->next;
            future = future -> next;
            if(future == NULL){
                temp -> next == new_node;
                new_node -> next = NULL;
                return;
            }
        }
        new_node -> next = temp -> next;
        temp -> next = new_node;
        }
    }   
}

void display(){
    struct node*temp = head;
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> next; 
    }
    printf("\n");
}

int main(){
    int choice,entry;
    
    do{
        
        printf("Enter a choice\n");
        printf("1 to push element to list...\n");
        printf("2 to display list in sorted fashion\n");
        scanf("%d",&choice);
        switch (choice){
            
        case 1:
        printf("Enter number to add to linked list::\n");
        scanf("%d",&entry);
        push(entry);
        break;
        
        case 2:
        printf("Linked list in sorted order is displayed\n");
        display();
        break;
        
        }
    }while(choice != 3);
}
