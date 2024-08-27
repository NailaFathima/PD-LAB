#include <stdio.h>
int main()
{   
    //creating the unsorted array containing the isbn numbers
    int n;
    int isbn[1000];
    scanf("%d",&n);
    for(int i =0;i<n;i++)
    {
        scanf("%d",&isbn[i]);
    }
    //performing insertion sort
    int key,k;
    for(int j = 0;j<n;j++)
    {
        key = isbn[j];
        k = j-1;
        while(k>=0 && isbn[k]>key)
        {
            isbn[k+1] = isbn[k];
            k--;
        }
        isbn[k+1] = key;
    }
    //printing the array in sorted array
    for(int i =0;i<n-1;i++)
        printf("%d ",isbn[i]);
    printf("%d",isbn[n-1]);
    return 1;
}
