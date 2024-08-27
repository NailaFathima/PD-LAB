//We are given an input string str of length n, which is transformed into a fancy string f ancystr. The
//fancy string f ancystr is created by repeating the i-th element in the string str, i times consecutively
//for 1 ≤ i ≤ n. Design a program to identify the character that appears the most number of times
//in this fancy string f ancystr. For example, if the given input string str is ‘bbbcca’, the fancy
//string is ‘bbbbbbcccccccccaaaaaa’. Thus the character that appears the most number of times in
//the fancy string f ancystr is ‘c’. If multiple characters have the same frequency, print the character
//that appears first in the input string. Assume that all the string indexing starts at 1.
//Note 1: While computing the frequency the characters are considered to be case-sensitive. (That
//is lower and upper case characters are considered to be different characters.)
#include<stdio.h>
#include<string.h>
main()
{
    char str[100];
    gets(str); //taking the input string
    int n;
    n = strlen(str);
    char chr;
    char fancystr[100];
    for(int i = 0;i<n;i++) // loop to create fancy string
    {
        chr = str[i];
        for(int j=1;j<=i+1;j++)
        {
            static int fancyindex = 0;
            fancystr[fancyindex] = chr;
            fancyindex++;
        }
    }
    //fancy string successfully created
 
    char chcount[100];
    int count1[100];
    int flen;
    char fchr;
    flen = strlen(fancystr);
    for(int k =0;k<flen;k++)
    {   int count =0;
        static int a =0;
        fchr = fancystr[k];
        for(int j =0;j<flen;j++)
        {
            if (fchr == fancystr[j])
            count = count+1;
        }
        chcount[a] = fchr;          //chcount creates an array whose elements are the individual characters
        count1[a] = count; a++;     //count creates an array whose elements give the frequencies of each character present in chcount
    }
    int chlen = strlen(chcount);
    int  end = chlen -1; 
    chcount[end] = '\0';
    //two arrays chcount and count1 (whose corresponding elements give the char and its count) have been created
    char maxch;
    int max;
    max = count1[0];
    maxch = chcount[0];
    for(int h = 0;h<chlen;h++) //getting the index of the max element in count1 array
    {
        if(count1[h]> max)
        {    
            max = count1[h];
            maxch = chcount[h]; 
            //the index of the max element in  coun1 array would give the character with maximum frequencies in chcount array
        }
    }
    printf("%c",maxch);
}

