#include <stdio.h>
//a,b: Nodes that are being connected by the minimum edge.
//u, v: Nodes in the current minimum edge.
int a, b, u, v, n, i, j, ne = 1;//ne: Number of edges in the MST, starting from 1.
int visited[10] = {0}, min, mincost = 0, cost[10][10];
/*visited[10] = {0}: Array to track which nodes have been visited, initialized to 0.
min: Stores the minimum edge cost found.
mincost = 0: Accumulates the total cost of the MST
cost[10][10]: Adjacency matrix to store the cost of edges between nodes.*/
void main() 
{
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999; // Use a large value to represent infinity i.e suppose there is no edge b/w 2 nodes then its cost u would have given 0 so replace it with 999            }
        }
    }
    }
    printf("\n");
    visited[1] = 1; // Start from the first node
    

    while (ne < n) { // Loop until we include n-1 edges in the MST
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {//Loop through all nodes to compare edge costs.
                if (cost[i][j] < min) {//Checks if the current edge cost is less than the previously found minimum cost.
                    if (visited[i] != 0) {//this line not there in kruskal
                        min = cost[i][j];
                        a = u = i;//Updates nodes a and b with the current minimum edge.
                        b = v = j;
                    }
                }
            }
        }

        if (visited[u] == 0 || visited[v] == 0) {//Checks if either end of the edge is not visited.
            printf("\nEdge %d: (%d -> %d) cost: %d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = 999; // Mark this edge as visited by setting its cost to infinity
    }//end of while loop

    printf("\nMinimum cost = %d\n", mincost);
}
