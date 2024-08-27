#include <stdio.h>
#include <math.h>
int no_of_digits(int arr[],int n) //calculating the masximum no. of digits present
{
    int max = arr[0];
    for(int i =0;i<n;i++)  //we first calculate the max elememt 
        if(arr[i]>max)
            max = arr[i];
    int count = 0;
    while(max>0) //and check the digits in the maximum element
    {
        count++;
        max = max/10;
    }
    return(count);
}
void printarray(int arr[],int n) //function to print the array
{
    for(int i =0;i<n-1;i++)
        printf("%d ",arr[i]);
    printf("%d",arr[n-1]);
}
void insertionsort(int arr[] , int n,int power) 
{
    int key,k,key2;
    int deno = pow(10,power);
    for(int j = 0;j<n;j++)
    {   
        key = arr[j];
        key2 = ((arr[j]/deno)%10);
        k = j-1;
        //in the first iteration we compare the ones digit ; in the second iteration we compare the tens digit and so on
        while(k>=0 && ((arr[k]/deno)%10)>((key/deno)%10))
        {
            arr[k+1] = arr[k];
            k--;
        }
        arr[k+1] = key;
    }
}
void radixsort(int arr[],int n)  
{
    int times = no_of_digits(arr,n); //the loop runs as many times as the number of digits in maximum element
    for(int j = 0;j<times;j++)
        insertionsort(arr,n,j); //any stable sort can be coupled with radix sort to sort the elements
                                //here I have used insertion sort
}
int main()
{
    int n;
    int arr[100];
    scanf("%d",&n);
    for(int k = 0;k<n;k++) //taking the input array
        scanf("%d",&arr[k]);
    radixsort(arr,n);
    printarray(arr,n);
    return 1;
}
