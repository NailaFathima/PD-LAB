#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define max 1000

typedef struct exptree
{
    char data;
    struct exptree* left;
    struct exptree* right;
} exptree;

typedef struct stack_node
{
    exptree* data;
    struct stack_node* next;
}stack_node;

typedef struct stack
{
    stack_node* top;
} stack;

typedef struct sstack
{
    double arr[max];
    int top;
};

void initializestack(struct sstack *s)
{
    s->top = -1;
}

void pushss(struct sstack *s , double op)
{
    if(s->top < max-1)
    {
        s->top = s->top + 1;
        s->arr[s->top] = op;
    }
}

double popss(struct sstack *s)
{
    if(s->top >=0)
    {
        return s->arr[s->top--];
    }
    else
        return 0.0;
}
int stack_empty(float stack[] , int top)
{
    if(top==-1)
        return 0;
    else
        return 1;
}
int stack_full(float stack[] , int top , int size)
{
    if(top==size-1)
        return 0;
    else
        return 1;
}
float pop(float stack[] , int *top)
{
    int check = stack_empty(stack , *top);
    if (check!=0)
    {
        float a =  stack[*top];
        *top = *top - 1;
        return a;
    }
}
int push(float stack[] , int top , int size, float data)
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

    float a = 0;
    float b = 0;
    int top = -1;
    float stack[1000];
    char *token = strtok(postfix , " ");
    while(token != NULL)
    {   
        if(strcmp(token,"+") !=0 && strcmp(token,"-")!=0 && strcmp(token,"*")!=0 && strcmp(token,"/")!=0)
            top = push(stack , top , 1000 , atoi(token));
        else
        {
            a = pop(stack , &top);
            b = pop(stack , &top);
                if(strcmp(token,"+")==0)
                {   
                    float sum = b+a;
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
                        printf("N\n"); //division by zero
                        return;
                    }
                }
        }
        token = strtok(NULL , " ");
    }
    float result = pop(stack , &top);
    printf("%.2f\n",result);
    return;
}

int precedence (char symbol)
{
    switch(symbol)
    {
        case '^':
            return 3;
        case '/':
        case '*':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int operator_check(char symbol)
{
    if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/')
        return 1;
    else
        return 0;
}
void pushll(stack* stack , exptree* data)
{
    stack_node* newnode = malloc(sizeof(stack_node));
    newnode->data = data;
    newnode->next = stack->top;
    stack->top  = newnode;
}

exptree* popll(stack* stack)
{
    if(stack->top==NULL)
        return NULL;
    else
        {
            stack_node* temp = stack->top;
            stack->top = stack->top->next;
            exptree* data = temp->data;
            free(temp);
            return data;
        }
}

exptree* createnode(char data)
{
    exptree* newnode = malloc(sizeof(exptree));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

exptree* buildexptree(char* postfix)
{
    stack* stack = malloc(sizeof(stack));
    stack->top = NULL;

    for(int i=0; postfix[i]!='\0';i++)
        {
            if(operator_check(postfix[i]))
            {
                exptree* newnode = createnode(postfix[i]);
                newnode ->right = popll(stack);
                newnode ->left = popll(stack);
                pushll(stack,newnode);
            }
            else
            {
                pushll(stack,createnode(postfix[i]));
            }
        }
    return popll(stack);
}

void postorder(exptree* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        //printf("%c ",root->data);
    }
}

int height(exptree* root)
{
    if(root==NULL)
    {
        return -1;
    }
    else
    {
        int leftheight = height(root->left);
        int rightheight = height(root->right);

        if(leftheight > rightheight)
            return leftheight+1;
        else
            return rightheight+1;
    }
}

int minlength(exptree* root)
{
    if(root == NULL)
        return 0;
    else
    {
        int leftminlength = minlength(root->left);
        int rightminlength = minlength(root->right);

        if(leftminlength<rightminlength)
            return leftminlength+1;
        else
            return rightminlength+1;
    }
}

void infix_to_postfixxx(char infix[] , char postfix[])
{
    struct sstack sstack;
    initializestack(&sstack);
    int i,j =0;
    for(i=0;infix[i]!='\0';++i)
    {
        if(infix[i]==' ')
        {
            continue;
        }
        else if (isdigit(infix[i]))
        {
            while(infix[i]!=' '&& infix[i]!='\0')
            {   
                //printf("%c\n",infix[i]);
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            i--;
        }

        else if(operator_check(infix[i]))
        {
            while(sstack.top>=0 && sstack.arr[sstack.top] != '(' && precedence(sstack.arr[sstack.top]) >= precedence(infix[i]))
            {
                postfix[j++] = popss(&sstack);
                postfix[j++] = ' ';
            }
            pushss(&sstack,infix[i]);
        }

        else if(infix[i] == '(')
        {
            pushss(&sstack,infix[i]);
        }

        else if(infix[i] == ')')
        {
            while(sstack.top>=0 && sstack.arr[sstack.top]!='(')
            {
                postfix[j++] = popss(&sstack);
                postfix[j++] = ' ';
            }
            if(sstack.top >= 0 && sstack.arr[sstack.top]=='(')
            {
                popss(&sstack);
            }
        }
    }
    while(sstack.top >= 0)
    {
        postfix[j] = popss(&sstack);
        j = j+1;
    }

    postfix[j] = '\0';
    printf("%s\n",postfix);
    return;
   
}
int main()
{
    
    char infix[1000];
    scanf("%[^\n]s",infix);
    stack* operatorstack = malloc(sizeof(stack));
    operatorstack->top = NULL;

    char postfix[1000];
    int j =0;

    infix_to_postfixxx(infix,postfix);
    exptree* root = buildexptree(postfix);
    postfix_eval(postfix);
    printf("%d\n" , height(root));
    printf("%d\n"  , minlength(root));
    return 0;
}

