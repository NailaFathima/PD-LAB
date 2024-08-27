#include <stdio.h>
int main()
{
    int n,m;  //n and m denote the number of days and sessions respectively
    scanf("%d %d",&n,&m);
    int arr[10000];  //array containing the time for each session
    for(int i =0;i<m;i++)
    {
        scanf("%d",&arr[i]);
    }
//the array containing the sequence and time for each session has been created successfully   
int lower;
int upper;
int mid;
int ctr;
lower = 0;
upper = 0;
for(int i=0;i<m;i++)
    {
        upper = upper + arr[i];
        if (arr[i] > lower) {
            lower = arr[i];
        }
    }
//defining the maximum limit as the sum of all terms (worst case possible when Anoop completes everything in single day)
ctr = upper;
int dayscount,totaltime;

while(lower<=upper)
{
    mid = (lower+upper)/2;
    dayscount = 1;
    totaltime = 0;
    for(int j = 0;j<m;j++)
    {   
        if(totaltime +arr[j]<=mid) //assuming the max time he can spend a day = mid
        {
            totaltime= totaltime + arr[j]; 
            //inspite of spending time for the prev sessions, if anoop hasnt reached the max limit , he could do a session more. 
            //If he has reached the max limit for the day then he will do the following session in the next day
        }
        else
        {
            totaltime = arr[j];
            dayscount = dayscount +1;
        }
    }
    if(dayscount<=n) //if Anoop completes the sessions in days lesser than the given number of days, 
    //then the max limit for each day should be decreased so that it takes more days for him to complete the sessions
    //we assign the maximum of the particular iteration to ctr variable ; so that the values could be compared in the subsequent iterations
    {
        ctr = mid;
        upper = mid-1;
    }
    else //if he takes more days to complete than the desired days, the maximum limit should be increased. 
    //(since mid = (lower+upper)/2) ; increasing the lower would inc the max limit)
    {
        lower = mid + 1;
    }
}
printf("%d",ctr);
return 1;
}
