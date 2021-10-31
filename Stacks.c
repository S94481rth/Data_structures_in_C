#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int arr[SIZE];
int top = -1;
int isEmpty()
{
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
} 
int isFull()
{
    if(top == SIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void push(int k)
{
    arr[++top] = k;
} 
int pop()
{
    return (arr[top--]);
}
int main()
{
    int entry,num,elem;
    do{
    printf("Enter the operation to be performed: \n");
    printf("1 for push to stack\n");
    printf("2 to pop from stack\n");
    printf("3 to display stack \n");
    printf("4 to exit\n");
    scanf("%d",&entry);
    switch (entry)
      {
      case 1:
      printf("Enter the number to be pushed: ");
      scanf("%d",&num);
      push(num);
      break;
      case 2:
      elem = pop();
      printf("popped number is %d \n",elem);
      break;
      case 3:
      for(int i=0; i<= top ; i++)
       {
          printf(" %d  ",arr[i]);
        }
        printf("\n");
      break;
      case 4:
      exit(0);
      break;
      }
    }
    while(entry != 4);
    return 0;
}





