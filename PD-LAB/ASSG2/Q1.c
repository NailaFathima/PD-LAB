#include <stdio.h>
int binary_search(int arr[1000000],int len,int k); //function declaration
int main()
{
    //creating the array
    int n;
    int array[1000000];
    scanf("%d",&n); //getting the length of the array
    for(int i =0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    //array created successfully
    //searching for the kth element
    int k;
    scanf("%d",&k);
    binary_search(array,n,k);
    return 1; 
}
// binary search
int binary_search(int arr[1000000],int len,int k)
{   int low = 0;
    int high = len-1;
    int mid,ctr = 0;
    int less,a;
    while (low<=high)
    {
        mid = (low+high)/2;
        ctr = arr[mid] - mid -1; //counter variable(ctr) to keep an account of how many elements are missing till mid
        if (arr[high] == high+1) //all the elements are present in the array are contigous i.e no elements are missing
        //hence we return -1 to exit out of the main function (hence the loop)
        {
            printf("-1");
            return 1;
        }
        if (ctr<k) 
        // no elements are missing till mid or maybe the number of elements missing are less than k
        // so we tend to move the subarray to the right so that more array cells can be probed to find the missing element
            low = mid + 1; 
        else if(ctr>k)
        //number of elements missing are more than k
        //so we tend to move the subarray to the left so that lesser number of array cells can be probed to find the exact kth missing element
        
            high = mid -1;
        
        else
        //if the number of missing elements are exactly equal to k
        {
            if(mid>0 && arr[mid-1]-mid ==k)
            {
                high = mid-1;
                continue;
            }
            else
            {
                printf("%d",arr[mid]-1);
                return 1;
            }
        }
    }
    if(high<0)
    {
       printf("%d",k);
       return 1;
    }
less = arr[high]-high -1;
k = k-less;
if(arr[high]+k <= arr[len-1])
{
    printf("%d",arr[high]+k);
}
else
{
    printf("-1");
}
return 1;
}

