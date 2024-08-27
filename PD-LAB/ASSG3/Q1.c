#include <stdio.h>
int main()
{   
    //creating the unsorted array
    int n;
    float sizes[1000];
    scanf("%d",&n);
    for(int i =0;i<n;i++)
    {
        scanf("%f",&sizes[i]);
    }
    int x,d;
    scanf("%d",&x);
    scanf("%d",&d);

    //performing insertion sort
    float key;
    int k;
    int count =0;
    for(int j = n-x;j<n;j++)
    if(count<d){   //sorting takes place only for 'd' times
    {
        key = sizes[j];
        k = j-1;
        while(k>=0 && sizes[k]>key)
        {
            sizes[k+1] = sizes[k];
            k--;
        }
        sizes[k+1] = key;
        count++;
    }}
//printing the array in sorted array
for(int i =0;i<n-1;i++)
    printf("%.2f ",sizes[i]);
printf("%.2f",sizes[n-1]);
return 1;
}
