#include <stdio.h>
#include <math.h>
int main()
{   
    //creating the unsorted array containing the float numbers
    int n;
    float arr[1000];
    scanf("%d",&n);
    for(int i =0;i<n;i++)
    {
        scanf("%f",&arr[i]);
    }
    //performing insertion sort
    float key;
    int k;
    for(int j = 1;j<n;j++)
    {
        key = arr[j];
        k = j-1;
        while(k>=0 && arr[k]>key)
        {
            arr[k+1] = arr[k];
            k--;
        }
        arr[k+1] = key;
    }
    //printing the array in sorted array
    for(int i =0;i<n-1;i++)
        printf("%.2f ",arr[i]);
    printf("%.2f",arr[n-1]);
    return 1;
}
