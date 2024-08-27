#include <stdio.h>
#include <string.h>
int stack_empty(char stack[] , int top)
{
    if(top==-1)
        return -1;
    else
        return 1;
}
int stack_full(char stack[] , int top , int size)
{
    if(top==size-1)
        return -1;
    else
        return 1;
}
void peek(char stack[], int top)
{   
    int check = stack_empty(stack , top);
    if(check==-1)
    {    
        printf("-1\n");
        return ;
    }
    else
    {
        printf("%c\n",stack[top]);
        return;
    }
}
int pop(char stack[] , int top)
{
    int check = stack_empty(stack , top);
    if (check==-1)
    {    printf("-1\n");
        return -1;
    }
    else
    {
        printf("%c\n" , stack[top]);
        top--;
        return top;
    }
}
int push(char stack[] , int top , int size, char data)
{
    int check = stack_full(stack,top,size);
    if(check == -1)
    {
        printf("-1\n");
        return top;
    }
    else
    {
        top = top+1;
        stack[top] = data;
        return top;
    }
}
void display(char stack[] , int top)
{
    for (int i =0 ;i<=top;i++)
        printf("%c", stack[i]);
}
int main()
{
    int size;
    scanf("%d" , &size);
    getchar();
    char stack[size];
    int top = -1;

    /*
    i = performs PUSH operation ; prints -1 if stack is full
    d = performs POP operation ; prints -1 if stack is empty
    p = performs PEEK operation ; prints -1 if stack is empty
    t = TERMINATE
    */

char ans;
scanf(" %c" , &ans);
getchar();
while(ans != 't')
{
    if (ans=='i')
    {
        char data;
        scanf("%c",&data);
        top = push(stack , top , size , data);
    }
    else if(ans=='d')
    {
        top = pop(stack,top);
    }
    else if(ans=='p')
    {
        peek(stack , top);
    }
    else if(ans == 's')
    {
        display(stack , top);
    }
    scanf(" %c" , &ans);
    getchar();
}
return 0;
}
