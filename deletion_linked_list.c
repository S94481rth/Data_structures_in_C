#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head = NULL;

void push(int a){
    if(head == NULL){
        struct node* new_node;
        new_node = malloc(sizeof(struct node)); 
        head = new_node;
        new_node -> next = NULL;
        new_node -> data = a;
    }
    else{
        struct node* new_node;
        new_node = malloc(sizeof(struct node));
        new_node -> next = head;
        new_node -> data = a;
        head = new_node;
    }
}
 
void del_beg(){
    if(head == NULL){
        printf("Empty!!!");
    }
    else{
        struct node* temp = head;
        head = head -> next;
        free(temp);
    }
} 
 
void del_end(){
    if(head == NULL){
        printf("Empty!!!");
    }    
    else{
        struct node* temp = head;
        struct node* prev;
        while(temp -> next != NULL){
            prev = temp; 
            temp = temp -> next; 
        }
        prev -> next = NULL;
        free(temp);
    }
} 

void del_bw(int position){
    struct node* temp = head;
    struct node* prev;
    for(int i = 0 ; i < position - 1 ; i++){
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = temp -> next;
    free(temp);
}
void display(){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
}
int main(){
    int choice,pos;
    for(int i=0;i<=10;i++){
    push(i);
    }
    printf("Initial linked list :: \n");
    display();
    do{
    printf("\nEnter your choice :: \n");
    printf("1 to delete at beginning::\n");
    printf("2 to delete at end::\n");
    printf("3 to delete in between ::\n");
    scanf("%d",&choice);
    switch (choice){
        case 1:
        del_beg();
        display();
        break;
        
        case 2:
        del_end();
        display();
        break;
        
        case 3:
        printf("Enter the position to delete :: ");
        scanf("%d",&pos);
        del_bw(pos);
        display();
        break;
        
        case 4:
        break;
      }
    }while(choice != 4);
    return 0;
}



