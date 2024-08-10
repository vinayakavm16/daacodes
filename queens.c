#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[30],count=0;// Declares an array a of size 30 to hold the column positions of the queens.
//Declares and initializes a counter count to count the number of solutions found.
int place(int pos) //Checks if a queen can be placed at column position a[pos] in row pos.
{
int i;
for (i=1;i<pos;i++) //Iterates through previous rows to check for conflicts.
{
if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos))))//Checks if the current queen conflicts with any previous queens.
// It checks if they are in the same column or on the same diagonal.
 return 0;
}
return 1;// indicating that the position is valid.
}
void print_sol(int n) //Prints the current solution to the console.
{
int i,j;
count++;
printf("\n\nSolution #%d:\n",count);
for (i=1;i<=n;i++) 
{
for (j=1;j<=n;j++) 
{
if(a[i]==j)
 printf("Q\t"); //Checks if there's a queen in the position (i, j).
 else
 printf("*\t");
}
printf("\n");
}
}

void queen(int n) //   Attempts to solve the N-Queens problem for an n x n board
{
int k=1;// Starts with the first row.
a[k]=0;//Initializes the first queen's position. 
while(k!=0) //Continues until all rows have been processed.
{
  a[k]=a[k]+1;// Moves the queen to the next column.
  while((a[k]<=n)&&!place(k))//Moves the queen to the next valid column if the current one is not valid.
  a[k]++;
  if(a[k]<=n) //Checks if the queen is within the board limits.
  {
    if(k==n)//If all queens are placed, prints the solution.
    print_sol(n); 
    else //Moves to the next row.
    {
    k++;
    a[k]=0;
    }
 } 
 else
   k--;
}
}
int main() 
{
int n;
printf("Enter the number of Queens\n");
scanf("%d",&n);
queen(n);
printf("\nTotal solutions=%d",count);
return 0;
}