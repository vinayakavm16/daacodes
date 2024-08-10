#include<stdio.h>
#include<string.h>
void main()
{
    int table[126];/*shift table*/
    char t[100],p[25];/*Arrays to store the input text (t) and the pattern (p).*/
    int n,i,j,k,m,flag=0;/*flag to indicate if the pattern was found (initialized to 0, meaning not found).*/
    printf("enter text:");
    scanf("%s",t);
    n=strlen(t);
    printf("enter pattern:");
    scanf("%s",p);
    m=strlen(p);
    for(i=0;i<126;i++)
    table[i]=m;/*Sets the initial shift value for each character to the length of the pattern (m)*/
    for(j=0;j<m-1;j++)
    table[p[j]]=m-1-j;/* Updates the shift value for the character p[j] in the table. The shift value is calculated as m - 1 - j (distance from the end of the pattern).*/
    i=m-1;/*Sets the initial index i to start at the end of the pattern.*/
    while(i<=n-1)/* Loops until the end of the text.*/
    {//////indirectly mjkgjhyfjyguytdf p[m-1-k]==t[m-1-k]*****
        k=0;/*initialize k to 0, which is used to compare characters.*/
        while(k<m-1 && p[m-1-k]==t[i-k])/*Compares characters of the pattern with the text from the end of the pattern.*/
        k++;/*Increments k as long as the characters match.*/
        if(k==m)
        {
            printf("position of pattern is %d\n",i-m+2);
            flag=1;
            break;
        }
        else
        i=i+table[t[i]];
    }
    if(!flag)
    printf("pattern is not found in given text");
}