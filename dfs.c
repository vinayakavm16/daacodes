#include<stdio.h>
#include<conio.h>
int a[20][20],visited[20],n;/* visited array keeps track of which nodes have been visited 
and variable 'n' stores the number of nodes in the graph.*/
void dfs(int v)/*v, which is the starting node */
{
    int i;
    visited[v]=1;/*Marks the current node v as visited by setting visited[v] to 1*/
   
    for(i=0;i<n;i++)
    {
        if(a[v][i] && !visited[i])/* if there is an edge between node v and node i) and
         if node i has not been visited (!visited[i])*/
        {
            printf("%d-->%d\n",v,i);
            dfs(i);
        }
    }
}
int main()
{
    int start;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    printf("adjacency matrix\n");
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        for(int j=0;j<n;j++)
        
            scanf("%d",&a[i][j]);
    }
        printf("enter starting node:");
        scanf("%d",&start);
        dfs(start);
}