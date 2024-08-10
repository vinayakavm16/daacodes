#include<stdio.h>
#include<conio.h>
int a[20][20],visited[20],n;
void dfs(int v)
{
    int i;
    visited[v]=1;
    for(i=0;i<n;i++)
    {
        if(a[v][i] && !visited[i])
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