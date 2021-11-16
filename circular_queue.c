#include<stdio.h>
#define SIZE 5
int arr[SIZE];
int front = -1;
int rear = -1;
int isFull(){
    if(front == rear + 1){
        return 1;
    }
    else if(rear == SIZE-1 && front == 0){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(){
    if(rear == -1 && front == -1){
        return 1;
    }
    else if(front == rear + 1 ){
        return 1;
    }
    else if(rear == SIZE-1 && front == 0){
        return 1;
    }
    else {
        return 0;
    }
}
void enqueue(int a){
    if(isFull() == 1){
        printf("Circular Queue is Full! \n");
    }
    else if(isEmpty()){
        front = 0;
        rear = (rear + 1)%SIZE;
        arr[rear] = a;
    }
    else {
          rear = (rear + 1)%SIZE;
          arr[rear] = a;
    }
}
void dequeue(){
    if(isEmpty() == 1){
        printf("Circular queue is Empty! \n");
    }
    else{
        int pop = arr[front]; 
        front = (front + 1) % SIZE;
        printf("Popped element is: %d \n",pop);
    }
}
void display(){
    if(rear < front){
    for(int i = front;  i <= rear + SIZE ; i++ ){
        int pls_work = i % SIZE;
        printf("%d ",arr[pls_work]);
    }
    printf("\n");
    }
    else{
        for(int i = front;  i <= rear ; i++ ){
        int pls_work = i % SIZE;
        printf("%d ",arr[pls_work]);
    }
    printf("\n%d %d \n",front, rear);
    }
}
int main(){
    int choice,num;
    do{
    printf("Enter the operation to be performed: \n");
    printf("1 to Enqueue\n2 to dequeue\n3 to display\n4 to exit:: ");
    scanf("%d",&choice);
    switch (choice){
    case 1:
    printf("Enter the element to be pushed:  ");
    scanf("%d",&num);
    enqueue(num);
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
  return 0;
  }
