#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 1000
int stack_empty(int stack[] , int top)
{
    if(top==-1)
        return 0;
    else
        return 1;
}
int stack_full(int stack[] , int top , int size)
{
    if(top==size-1)
        return 0;
    else
        return 1;
}
int pop(int stack[] , int *top)
{
    int check = stack_empty(stack , *top);
    if (check!=0)
    {
        int a =  stack[*top];
        *top = *top - 1;
        return a;
    }
    else
    {
        return NULL;
    }
    
}
int push(int stack[] , int top , int size, int data)
{
    int check = stack_full(stack,top,size);
    if(check == 0)
    {
       //printf("stack is full\n");
        return top;
    }
    else
    {
        top = top+1;
        stack[top] = data;
        return top;
    }
}
void postfix_eval(char postfix[])
{   

    int a = 0;
    int b = 0;
    int top = -1;
    int stack[1000];
    char *token = strtok(postfix , " ");
    while(token != NULL)
    {   
        if(strcmp(token,"+") !=0 && strcmp(token,"-")!=0 && strcmp(token,"*")!=0 && strcmp(token,"/")!=0)
            top = push(stack , top , 1000 , atoi(token));
        else
        {
            a = pop(stack , &top);
            b = pop(stack , &top);
            //if(a!=NULL && b!=NULL)
            //{
                if(strcmp(token,"+")==0)
                {   
                    int sum = b+a;
                    top = push(stack , top , 1000 , sum);

                }
                else if(strcmp(token,"-")==0)
                {
                    top = push(stack , top , 1000 , b-a);
                }
                else if(strcmp(token,"*")==0)
                {
                    top = push(stack ,top , 1000 , b*a);
                }
                else if(strcmp(token,"/")==0)
                {   if(a!=0)
                        top = push(stack,top,1000, (float)b/a);
                    else
                    {
                        printf("-1"); //division by zero
                        return;
                    }
            
                }
            //}
            //else
            //{
                //printf("-1");
                //return;
            //}
        }
        token = strtok(NULL , " ");
    }
    int result = pop(stack , &top);
    printf("%d",result);
    return;
}

int main()
{
    //int result;
    char postfix[1000];
    scanf("%[^\n]s",postfix);
    postfix_eval(postfix);
    //printf("%d",result);
    return 0;
}

