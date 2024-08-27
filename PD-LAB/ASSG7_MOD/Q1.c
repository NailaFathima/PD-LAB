#include <stdio.h>
#include <string.h>
#include <math.h>
int stack_empty(char stack[] , int top)
{
    if(top==-1)
        return 0;
    else
        return 1;
}
int stack_full(char stack[] , int top , int size)
{
    if(top==size-1)
        return 0;
    else
        return 1;
}
char pop(char stack[] , int *top)
{
    int check = stack_empty(stack , *top);
    if (check!=-1)
    {
        char a =  stack[*top];
        *top = *top - 1;
        return a;
    }
    
}
int push(char stack[] , int top , int size, char data)
{
    int check = stack_full(stack,top,size);
    if(check == 0)
    {
        printf("stack is full\n");
        return top;
    }
    else
    {
        top = top+1;
        stack[top] = data;
        return top;
    }
}
int precedence (char symbol)
{
    switch(symbol)
    {
        case '#':
        case '%':
            return 10;
        case '/':
        case '*':
            return 7;
        case '+':
        case '-':
            return 9;
        case '^':
            return 6;
        default:
            return 0;
    }
}
void infix_to_postfix(char infix[] , char postfix[], int top , int n)
{
    int i , j =0;
    char symbol , next;
    char stack[n];
    for(i=0;i<n;i++)
        {
            symbol = infix[i];
            switch(symbol)
            {
                case '(':
                    top = push(stack , top , n , symbol);
                    break;

                case ')':
                    while((next=pop(stack,&top)) != '(')
                        //strcat(postfix , next);
                        //j++;
                        postfix[j++] = next;
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                case '#':
                    while(stack_empty(stack , top) && (precedence(stack[top])>=precedence(symbol)))
                        postfix[j++] = pop(stack , &top);
                    top = push(stack , top , n , symbol);
                    break;
                case ' ':
                    //postfix[j++] = symbol;
                    break;
                default:
                    postfix[j++] = symbol;
                    break;
            }
        }
        //postfix[j++] = ' ';
        while(stack_empty(stack , top))
        {
            postfix[j++] = pop(stack , &top);
            //postfix[j++] = ' ';
        }
        postfix[j] = '\0';
}
void print_exp(char postfix[] , int n)
{
    int num;
    num = strlen(postfix);
    for(int i =0 ; i<num-1 ; i++)
        printf("%c ",postfix[i]);
    printf("%c",postfix[num-1]);
}
int main()
{
    int top = -1;
    //int size;
    //scanf("%d" , &size);
    //int n = 2*size;
    char infix[1000];
    char postfix[1000];
    //getchar();
    gets(infix);
    int n = strlen(infix);
    infix_to_postfix(infix , postfix , top,n );
    print_exp(postfix , n);
    return 0;
}