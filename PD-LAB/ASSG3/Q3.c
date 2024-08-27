#include <stdio.h>
int selection_sort(int arr1[1000],int len);
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
    selection_sort(arr,n);
    return 1;
}
int selection_sort(int arr1[1000],int len)
{
    //performing selection sort to sort in descending order
    int max,pos,temp;
    for(int i = 0;i<len;i++)
    {
        max = arr1[i];
        pos = i;
        for(int j = i+1;j<len;j++)
        {
            if (max<arr1[j])
            {
                max = arr1[j];
                pos = j;
            }
        }
        temp = arr1[i];
        arr1[i] = arr1[pos];
        arr1[pos] = temp;
    }
    //printing the array in sorted order
    for(int i =0;i<len-1;i++)
        printf("%d ",arr1[i]);
    printf("%d",arr1[len-1]);
    return 1;
}
