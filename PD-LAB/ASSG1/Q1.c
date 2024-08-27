//Eve needs to find the frequency of a given character in a given string. Write a C programming
//code to help Eve implement it. Note that the characters are not case-sensitive. (i.e. Both upper
//and lowercase is considered to be the same character.)
#include <stdio.h>
#include <string.h>
void main()
{

    char str[100]; 
    char str1[100];
    char galph, alph;
    int n;
    gets(str); //getting input from user
    scanf("%c",&galph); 
    n = strlen(str);
    if (galph >= 'a') //element given is lower case
    {
        for(int i=0;i<n;i++) //converting the input string to uniform lower case
    {
        if(str[i] < 'a' && str[i]!= ' ')
            str[i] = str[i] + 32;
    }
    }
    else //element given is upper case
    {
        for(int i=0;i<n;i++) //converting the input string to uniform upper case
    {
        if(str[i] >= 'a' && str[i]!= ' ')
            str[i] = str[i] - 32;
    }
    } //both the given string and the element to be found are of same case
    int count = 0;
    for (int i = 0;i<n;i++)
    {
        if (str[i]== galph)
        count += 1; //calculating the frequency of the element
    }
    printf("%d",count);
}
