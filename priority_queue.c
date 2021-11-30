#include<stdio.h>
#define SIZE 50
int queue[SIZE];
int front=-1,rear=-1;

int isFull(){
    if(rear == SIZE){
        return 1;
    }
    else {
        return 0;
    }
} 
int isEmpty(){
    if(rear == -1 && front == -1){
        return 1;
    }
    else if(front == rear+1){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(int a){
    if(isFull() == 1){
        printf("Is Full\n");
    }
    else if(isEmpty() == 1 ){
        front = 0;
        queue[++rear] = a;
    }
    else{
        queue[++rear] = a;
    }
}
int dequeue(){
    if(isEmpty() == 1){
        printf("Empty Queue\n");
    }
    else{
        return queue[front++];
    }
}
display(){
    for(int i=front ;i <= rear ; i++ ){
        printf("%d ",queue[i]);
    }
    printf("\n");
}
void sort(int arr[]){
     
    for(int i=0;i<=rear;i++){
        int largest = arr[i],index=i;
        for(int j=i;j<=rear;j++){
            if(arr[j] > largest){
                largest = arr[j];
                index = j;
            }
        }
        int temp = queue[index];
        queue[index]  = queue[i] ;
        queue[i] = temp; 
    }
}
int main(){
    int choice,num;
    do{
    printf("Enter the operation to be performed :: \n");
    printf("1 to enqueue :\n");
    printf("2 to dequeue :\n");
    printf("3 to display :\n");
    printf("4 to exit :\n");
    scanf("%d",&choice);
    switch (choice){
        case 1: 
        printf("Enter the number to enqueue ::  ");
        scanf("%d",&num);
        enqueue(num);
        sort(queue);
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
