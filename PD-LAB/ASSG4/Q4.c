#include <stdio.h>
int selection_sort(int arr1[1000],int len,int energy);
int main()
{   
    //creating the unsorted array
    int n,energy;
    int arr[1000];
    scanf("%d",&n);
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&energy);
    selection_sort(arr,n,energy);
    return 1;
}
int selection_sort(int arr1[1000],int len,int energy)
{
    //performing selection sort 
    int min,max,pos,temp;
    int count = 0;
    for(int i = 0;i<len;i++)
    {   if(i%2==0 && count < energy) //if the index is an even index then the kth smallest term would be placed
        {
            min = arr1[i];
            pos = i;
            for(int j = i+1;j<len;j++)
            {
                if (min>arr1[j])
                {
                    min = arr1[j];
                    pos = j;
                }
            }
            if(arr1[i]!=arr1[pos]) //if the elements to be swapped are not same then count gets incremented
                count++;
            temp = arr1[i];
            arr1[i] = arr1[pos];
            arr1[pos] = temp;
        }
        else if(i%2==1 && count<energy) //if the index is an odd index , then the kth largest term would be placed
        {
            max = arr1[i];
            pos = i;
            for(int j = i+1;j<len;j++)
            {
                if (max<=arr1[j])
                {
                    max = arr1[j];
                    pos = j;
                }
            }
            if(arr1[i]!=arr1[pos]) //if the elements to be swapped are not same then count gets incremented
                count++;
            temp = arr1[i];
            arr1[i] = arr1[pos];
            arr1[pos] = temp;
        }
    }
    //printing the sorted array
    for(int i =0;i<len-1;i++)
        printf("%d ",arr1[i]);
    printf("%d",arr1[len-1]);
    return 1;
}
