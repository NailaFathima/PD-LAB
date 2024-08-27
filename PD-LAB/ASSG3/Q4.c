#include <stdio.h>
int main()
{   
    //creating the unsorted array
    int n,k;
    int arr[1000];
    scanf("%d %d",&n,&k);
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    //performing selection sort to sort in descending order
    int max,pos,temp;
    for(int i = 0;i<n;i++)
    {
        max = arr[i];
        pos = i;
        for(int j = i+1;j<n;j++)
        {
            if (max<arr[j])
            {
                max = arr[j];
                pos = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
    //printing the k-th top elements
    for(int i =0;i<k-1;i++)
    printf("%d ",arr[i]);
    printf("%d",arr[k-1]);
    return 1;
}
