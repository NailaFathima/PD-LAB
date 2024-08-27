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
void postfix_to_infix(char postfix[] , char infix[], int top , int n)
{
    int i , j =0;
    char symbol , next;
    char a;
    char stack[1000];
    //int count = 0;
    for(i=0;i<n;i++)
        {
            symbol = postfix[i];
            switch(symbol)
            {
                case '+':
                case '-':
                case '*':
                case '/':
                {
                	if(postfix[i-1] != '+' && postfix[i-1] != '-' && postfix[i-1] != '*' && postfix[i-1] != '/')
                    	{
                    	    	a = pop(stack , &top);
                        	top = push(stack , top , 1000 , symbol);
                        	top = push(stack , top , 1000 , a);
                        	//count++;
                        	
                    	}
                    	else
                    	{
				int count = 0;
				for(int n = i-1;n>=0;n--)
					if(postfix[n] == '+' || postfix[n] == '-' || postfix[n] == '*' || postfix[n] == '/')
						count++;
				char buffer [2*count+1];
				int btop = -1;
				for(int bcount = 0; bcount < 2*count+1 ; bcount++)
					btop = push(buffer , btop , 1000 , pop(stack , &top));
				top = push(stack , top , 1000 , symbol);
				while(btop!=-1)
					top = push(stack,top,1000,pop(buffer,&btop));
			}
			break;
		}
				
                default:
                    {
                        top = push(stack , top , 1000 , symbol);
                        break;
                    }
            }
        }
        //for(int i=1;i<count;i++)
            //printf("(");
        for(int i =0;i<strlen(stack);i++)
            printf("%c",stack[i]);
}
int main()
{
    int top = -1;
    int size;
    scanf("%d",&size);
    getchar();
    char postfix[100];
    char infix[100];
    gets(postfix);
    int n = strlen(postfix);
    postfix_to_infix(postfix , infix , top,n );
    return 0;
}