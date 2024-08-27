#include<stdio.h>
int main()
{
    int n; //getting the length of the array
    scanf("%d",&n);
    int arr[1000];
    for (int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]); //creating the array
    }
    //creating a two-dimensional array where each row would consist of the element and its corresponding index in the original array
    //so that we can sort the two dimensional array in the ascending order of the 0th element in each sub array and
    //still have the hold over its index in the original array
    int nestedarr[n][2];
    for(int j = 0;j<n;j++)
    {
        nestedarr[j][0] = arr[j];
        nestedarr[j][1] = j;
    }
    //sorting the nested array in the increasing order of the 0th elements
    // applying selection sort 
    int min;
    int temp,temp1;
    for(int k =0;k<n;k++)
    {
        min = k;
        for(int p =k+1;p<n;p++)
        {
            if(nestedarr[p][0] < nestedarr[k][0])
            {
                min = p;
            }
        }
        if(min!=k)
        {   
            temp = nestedarr[k][0];
            nestedarr[k][0] = nestedarr[min][0];
            nestedarr[min][0] = temp;

            temp1 = nestedarr[k][1];
            nestedarr[k][1] = nestedarr[min][1];
            nestedarr[min][1] = temp1;
        }
    }
    //apply binary search to the sorted array
    int secno;
    scanf("%d",&secno);
    int low,high,mid,flag,comp;
    comp = 0;
    low = 0;
    high = n-1;
    while(low<=high)
    {   comp = comp+1;
        mid = (low+high)/2;
        if (nestedarr[mid][0]==secno)
        {   
            printf("%d",nestedarr[mid][1]);
            flag = 1;
            break;
        }
        else if(secno<nestedarr[mid][0])
        {  
            high = mid-1;
        }
        else
        {   
            low = mid+1;
        }
    }
    if(flag == 0)
    {
        printf("-1");
    }
    return 1;
}
