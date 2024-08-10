#include <stdio.h>
#include <string.h>
int i, j, m, n, LCS_table[20][20];
char S1[20] = "ACADB", S2[20] = "CBDA", b[20][20];
void lcsAlgo() 
{
m = strlen(S1);
n = strlen(S2);
 for (i = 0; i <= m; i++)
 LCS_table[i][0] = 0;
 for (i = 0; i <= n; i++)
 LCS_table[0][i] = 0;
//initialize the first row and first column to zero
 for (i = 1; i <= m; i++)
 for (j = 1; j <= n; j++)//then Nested loops to fill the LCS_table.
{
 if (S1[i - 1] == S2[j - 1]) // Checks if the characters at the current positions in S1 and S2 are the same.
 {
 LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;//If they are the same, update the LCS_table to add 1 to the value from the previous diagonal cell.
 }
 else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1]) //If the characters are not the same  and  If the value from the cell above is greater or equal, copy it.
 {
 LCS_table[i][j] = LCS_table[i - 1][j];
 } 
 else
 {
 LCS_table[i][j] = LCS_table[i][j - 1];///If the characters are not the same  and  If the value from the cell to the left is big  copy it.
 }
}
//Constructing the LCS from the Table
int index = LCS_table[m][n];//pointing to bottom right corner and has the no of elements in lcs solution
char lcsAlgo[index + 1];//Declares a character array to store the LCS, with one extra space for the null terminator.
lcsAlgo[index] = '\0';//Sets the last character of lcsAlgo to the null terminator.
int i = m, j = n;// Sets i and j to the lengths of S1 and S2.
while (i > 0 && j > 0)// Loops until either i or j reaches 0.
{
 if (S1[i - 1] == S2[j - 1])//If the characters at the current positions are the same:
 {
 lcsAlgo[index - 1] = S1[i - 1];// Adds the character to the LCS.
 i--;//Moves diagonally
 j--;// up in 
 index--;//the table
 }
 else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
 i--;// If the value from the cell above is greater, move up.

 else
 j--;//Otherwise, move left.
 }
 printf("S1 : %s \nS2 : %s \n", S1, S2);
 printf("LCS: %s", lcsAlgo);
}
int main()
{
 lcsAlgo();
 printf("\n");
}