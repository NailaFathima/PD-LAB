#include<stdio.h>
void func(int n) //function definition
{
    if (n==1)
        printf("%d ",1);
    else if(n>1)
        {
        func(n-1);  //recursive call
        printf("%d ",n);
        }
}
main()
{
    int num;
    scanf("%d",&num);  //taking input
    func(num-1);      //calling the function
    printf("%d",num);

}
