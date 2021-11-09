#include<stdio.h>
#include<ctype.h>
#define SIZE 50
char stack[SIZE];
int top = -1;
void push(char k)
{  
      stack[++top] = k;
}
int pop()
{
return (stack[top--]);
}
int priority(char a)
{
    if(a == '^')
      {
          return 3;
       }
    else if(a == '*' || a == '/')
     {
        return 2;
     }
     else if(a == '+' || a == '-')
     {
        return 1;
      }
     else
      { 
        return 0; 
       }
}
int main()
{
     char infix[50];
     char postfix[50],ch,elem;
    printf("Enter the infix expression: ");
    scanf("%s",infix); 
    int i=0,k=0;
    push('#');
     while((ch=infix[i++]) != '\0')
       {
           if(ch == '(')
           {
               push(ch);
           }
          else if(isalnum(ch))
            {
              postfix[k++] = ch;
            }
            else if(ch == ')')
            {
                while(stack[top] != '(')
                {  
                    postfix[k++] = pop();
                }
                elem = pop();
            }
          else
            {
              while( priority(ch) <= priority(stack[top]) )
               {
                 postfix[k++] = pop();
               }
                push(ch);
            }
       }
  while(stack[top] != '#')
     {
        postfix[k++] = pop();
     }           
     postfix[k] = '\0';
     printf("\n the psotfix expression is %s \n",postfix);
     printf("\n %c",elem);
     return 0;
}
