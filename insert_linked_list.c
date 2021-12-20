#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node *head = NULL; 
//push to beginning of linked list...
void in_front(int a){
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if(head == NULL){
        head = new_node;
        head -> data = a;
        head -> next = NULL;
    }
    else{
        new_node -> next = head;
        head = new_node;
        new_node -> data = a;
    }
}
//push to the end of the linked list...
void in_back(int a){
    struct node* new_node;
    new_node = malloc(sizeof(struct node));
    struct node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = new_node;
    temp = temp -> next;
    temp -> data = a;
    temp -> next = NULL;
}
//insert between nodes...
void in_between(int a, int position){
    struct node* temp = head;
    struct node *new_node, *prev;
    new_node = malloc(sizeof(struct node));
    for(int i=1;i<position;i++){
        prev = temp;
        temp = temp -> next;
    }
    
    prev -> next = new_node;
    new_node -> data = a;
    new_node -> next = temp;
}
void display(){
    struct node * temp = head;
    while(temp != NULL){
        printf("%d  ",temp -> data);
        temp = temp -> next;
    }
}
int main(){
    int choice,num;
    printf("Enter choice::");
    do{
        printf("\n1 to push in beginning \n2 to push in the end \n3 to push in between \n4 to display\n5 to quit\n ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
            printf("number to push in begining :: ");
            scanf("%d",&num);
            in_front(num);
            break;
            
            case 2:
            printf("number to push in end ::");
            scanf("%d",&num);
            in_back(num);
            break;
    
            case 3:
            printf("ENter the position to insert:: ");
            int pos;
            scanf("%d",&pos);
            printf("number to push inbetween ::");
            scanf("%d",&num);
            in_between(num,pos);
            break;
            
            case 4:
            display();
            break;
            
            case 5:
            break;
        }
    }while(choice != 5);
        
    return 0;
}
