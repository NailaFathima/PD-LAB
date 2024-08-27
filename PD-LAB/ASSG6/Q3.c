#include <stdio.h>
#include <string.h>
int queue_full(char queue[][20] , int front , int rear , int size)
{
    if(((rear+1)%size) == front)
        return -1;
    else
        return 1;
}
int queue_empty(char queue[][20] , int front , int rear )
{
    if(front == -1 && rear == -1)
        return -1;
    else
        return 1;
}
void enqueue(char queue[][20] , int *front , int *rear , int size , char data[20])
{
    int check = queue_full(queue , *front , *rear , size);
    if(check==-1)
        printf("-1\n");
    else if (*front==-1 && *rear==-1)
    {
        *front = 0;
        *rear = 0;
        strcpy(queue[*rear],data);
    }
    else 
    {
        *rear = (*rear+1)%size;
        strcpy(queue[*rear],data);
    }
    return ;
}
void dequeue(char queue[][20] , int *front , int *rear , int size )
{
    int check = queue_empty(queue , *front , *rear);
    if(check==-1)
    {
        printf("-1\n");
    }
    else if(*front == *rear)
    {
        printf("%s\n",queue[*front]);
        *front = -1;
        *rear = -1;
    }
    else
    {
        printf("%s\n",queue[*front]);
        *front = (*front+1)%size;
        return;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    char queue[n][20];
    int front = -1;
    int rear = -1;
    /*
    i = performs ENQUEUE operation ; takes a string ; prints -1 if queue is full
    d = performs DEQUEUE operation ; -1 if queue is empty
    f = checks if QUEUE is full
    e = checks if queue is empty
    t = terminate
    */
    char ans;
    scanf(" %c",&ans);
    getchar();
    while(ans != 't')
    {
        if(ans=='i')
        {
            char data[20];
            gets(data);
            enqueue(queue , &front , &rear , n , data);
        }
        else if(ans=='d')
        {
            dequeue(queue , &front , &rear , n);
        }
        else if(ans=='f')
        {
            int check;
            check = queue_full(queue , front , rear , n);
            printf("%d\n" ,check);
        }
        else if(ans=='e')
        {
            int check;
            check = queue_empty(queue , front , rear);
            printf("%d\n" ,check);
        }
        scanf(" %c",&ans);
        getchar();
    }
    return 0;
}

