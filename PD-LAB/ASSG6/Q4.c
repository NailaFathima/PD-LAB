#include <stdio.h>
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i =0;i<n;i++)
        scanf("%d",&arr[i]);
    int dup[k];
    int j;
    for(j=0;j<k;j++)
        dup[j] = arr[j];
    j = j-1;
    int i=0;
    while(j>=0)
    {
        arr[i] = dup[j];
        i++;
        j--;
    }
    for(int i =0;i<n-1;i++)
        printf("%d ",arr[i]);
    printf("%d",arr[n-1]);
    return 0;
}
