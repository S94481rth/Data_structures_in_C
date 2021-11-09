#include<stdio.h>
#define SIZE 10
int arr[SIZE];
int front = -1;
int rear = -1;
int isEmpty(){
   if(front == -1 && rear == -1){
       return 1;
   }
   else{
       return 0;
    }
}
int isFull(){
    if(rear == SIZE-1){
        return 1;
     }
    else {
        return 0;
     }
}
void enqueue(int a){
    if(isFull() == 1){
       printf("Queue is full");
    }
     else if(isEmpty()){
       front++;
       arr[++rear] = a;
    }
     else{
         arr[++rear] = a;
     }
 }
int dequeue(){
    if(isEmpty() == 1){
        printf("Queue is Empty");
    }
    else{
    return arr[front++];
    }
 }
 void display(){
  int i=0;
  for(i=front;i<=rear;i++){
     printf("%d  ",arr[i]);
   }
   printf("\n");
}
int main(){
  int choice,num,i=0,pop;
  printf("enter operation: \n");
  do{
  printf(" 1 to enqueue \n 2 to dequeue\n 3 to display \n 4 to exit\n");
  scanf("%d",&choice);
  switch (choice){
  case 1: 
  printf("Enter the number to be pushed: ");
  scanf("%d",&num);
  enqueue(num);
  break;
  case 2: 
  pop = dequeue();
  printf("popped element is %d\n",pop);
  break;
  case 3:
  display(); 
  break;
  case 4:
  exit(0);
  break;
    }
  }while(choice != 4);
return 0;
}