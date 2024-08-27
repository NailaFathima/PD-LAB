/*Alice and Bob were studying trigonometric functions and they planned to code a program to
compute an approximate value of sin(x) for given a value of x. They decided to use the following
Taylor’s series of sin(x) for computing the same.
Given x and n, compute the sine of x using the series. The computation should use all terms in
the series, whose degree of x is less than or equal to n.
Note 1 : Convert x to radian value x = x ∗ (3.1415/180)
Note 2: Restrict the precision of the output to 4 decimal places.*/
#include<stdio.h>
int fact(int num)  //function to calculate factorial
{
    int fact = 1;
    while(num)
        {
            fact = fact*num;
            num--;
        }
    return fact;
}
float power(float x1,int n) //function to calculate x1 raised to power n
{
    float prod = 1;
    for(int i = 1;i<=n;i++)
        prod = prod*x1;
    return prod;        //returns a float value
}
void main()
{
float x;
float term;
int n,factorial;
float xpower;
scanf("%f",&x);
scanf("%d",&n);
x = x*(3.1415/180);  //converting x to radians
float sinx = 0;
for(int i =1;i<=n;i = i+2)
{
    factorial = fact(i);
    xpower = power(x,i);
    term = xpower/factorial;
    int a = i/2;
    if (a%2 == 1)  //if the term is an even term (terms counting starting from 1)
        sinx = sinx - term;
    else
        sinx = sinx + term;   // if the term is an odd term
}
printf("%.4f",sinx); //.4f so that only 4 decimal places are printed
}
