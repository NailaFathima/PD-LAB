#include <stdio.h>
int main()
{
    //creating the array
    int n;
    int arr[1000];
    scanf("%d",&n);
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    //doing binary search
    int low,high,mid;
    low = 0;
    high = n-1;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid]) 
        //if the element to the right as well as to the left of arr[mid] are lesser than arr[mid]
        //then arr[mid] is the peak element
        {   
            if(mid!=0 && (mid+1)!=n)
            {
                printf("%d" , arr[mid]);
                break;
            }
            else
            {
                printf("%d" , arr[mid]);
                break;
            }
        }
        else if(arr[mid-1]<arr[mid] && arr[mid+1]>arr[mid])
        //if the element to the left is smaller than arr[mid] but the element to the right is bigger than arr[mid]
        //the the lower limit of the array should be made to mid + 1
        //so that we get to check the other side of the array for the peak element
        {
            low = mid+1;
        }
        else
        //if the element to the left is bigger that arr[mid] but the element to the right is smaller than arr[mid]
        //the upper limit of the array must be changed to mid -1
        //so that we get to check the left side of the array
        {
            high = mid-1;
        }

    }
return 1;
}
