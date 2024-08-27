#include <stdio.h>
#include <string.h>
int partition ( char arr[] , int p , int r)
{
    int x = arr[r];
    int i = p-1;
    char temp1,temp2;
    for(int j =p;j<=r-1;j++)
    {   char k = arr[j];
        if(k>=x)
        {
            i = i+1;
            temp1 = arr[i];
            arr[i] = arr[j];
            arr[j] = temp1;

        }
    }
    temp2 = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp2;
    int j = i+1;
    return(j);
}
void quicksort(char arr[] , int p, int r)
{
    if(p<r)
    {
        int q = partition(arr,p,r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);

    }
}

int main()
{   
    int n;
    char name[100];
    char duplicate[100];
    scanf("%d",&n);
    getchar();
    scanf("%[^\n]s",name);
    int len1 = sizeof(name)/sizeof(name[0]);
    int j =0;
    for(int i =0;i<len1;i++)
        if(name[i]!=' ' )
            {duplicate[j] = name[i];
            j++;}

    int len = strlen(duplicate);
    quicksort(duplicate , 0 , len-1);
    for(int i =0;i<len-1;i++)
        printf("%c ",duplicate[i]);
    printf("%c",duplicate[len-1]);
    return 1;
}

