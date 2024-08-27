#include <stdio.h>
int main()
{
    int n;
    scanf("%d" , &n);
    //building the array
    int arr[n];
    for(int i =0;i<n;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<n-1;i++)
    {
        int large = -1;
        for(int j =i+1;j<n;j++)
        {
            if(arr[j]>arr[i]&&large==-1)
            {
                large = arr[j];
                continue;
            }
        }
        if(large!=-1)
        {
            printf("%d ",large);
        }
        else
        {
            printf("-1 ");
        }
    }
    printf("-1");
    return 0;
}
