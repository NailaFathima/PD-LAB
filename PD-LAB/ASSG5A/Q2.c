#include <stdio.h>
int main()
{
    //creating the unsorted array
    int n;
    int arr[1000];
    scanf("%d",&n);
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    //performing insertion sort
    int key,i;
    for(int j =0;j<n;j++)
    {
        key = arr[j];
        i = j-1;
        while(i>=0 && arr[i]>key)
        {
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }

    for(int k =0;k<n-1;k++)
        printf("%d ",arr[k]);
    printf("%d",arr[n-1]);
    return 1;
}
