#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 9//Defines V as 9, representing the number of vertices in the graph.
int minDistance(int dist[], bool sptSet[])// Function to find the vertex with the minimum distance value among the set of vertices not yet included in the shortest path tree.
{
int min = INT_MAX, min_index;
for (int v = 0; v < V; v++)//loop throgh all the vertices 
if (sptSet[v] == false && dist[v] <= min)// Checks if the vertex v is not yet included in the shortest path tree and 
//if its distance is less than or equal to the current minimum
min = dist[v], min_index = v;
return min_index;
}
void printSolution(int dist[])
{
printf("Vertex \t\t Distance from Source\n");
for (int i = 0; i < V; i++)
printf("%d \t\t\t\t %d\n", i, dist[i]);
}
void dijkstra(int graph[V][V], int src)
{
int dist[V]; //int dist[V]: Array to hold the shortest distances from the source vertex to each vertex.
bool sptSet[V];// Array to keep track of vertices included in the shortest path tree
for (int i = 0; i < V; i++)
dist[i] = INT_MAX, sptSet[i] = false;//Initialize all the distances to INT_MAX and all the vertices are not yet included in the shortest path tree
dist[src] = 0;
for (int count = 0; count < V - 1; count++) // Loop to find the shortest path for all vertices.
{
int u = minDistance(dist, sptSet);
sptSet[u] = true;
for (int v = 0; v < V; v++)
if (!sptSet[v] && graph[u][v]&& dist[u] != INT_MAX&& dist[u] + graph[u][v] < dist[v])//graph[u][v]checksifthereisdirect edge between the current vertex u and vertex v
dist[v] = dist[u] + graph[u][v];                                                     //dist[u] != INT_MAX:checks if the distance to the current vertex u is not infinity, 
}                                                                                    //i.e meaning u is reachable from the source.
printSolution(dist);
}
int main()
{
int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
 { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
 { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
 { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
 { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
 { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
 { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
 { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
 { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
 };
dijkstra(graph, 0);
return 0;
}
