#include <stdio.h>
#include <stdlib.h>

int a[20][20], visited[20], reached[20], q[20], n;
int f = 0, r = -1;  // Front and Rear pointers for the queue

void dfs(int v) {
    int i;
    visited[v] = 1;  // Marks the current node v as visited by setting visited[v] to 1

    for (i = 0; i < n; i++) {
        if (a[v][i] && !visited[i]) {  // If there is an edge between node v and node i and if node i has not been visited
            printf("%d-->%d\n", v, i);
            dfs(i);
        }
    }
}

void bfs(int v) {
    int i;
    q[++r] = v;  // Enqueue the starting node
    reached[v] = 1;  // Marks node v as visited

    while (f <= r) {  // Continues as long as there are nodes in the queue (f is less than or equal to r)
        int no = q[f++];  // Dequeue a node
        printf("%d ", no);
        for (i = 0; i < n; i++) {
            if (a[no][i] && !reached[i]) {  // If there is an edge and the node has not been reached
                q[++r] = i;  // Enqueue the adjacent node
                reached[i] = 1;
            }
        }
    }
}

int main() {
    int start, choice;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        reached[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    printf("Choose the algorithm:\n1. DFS\n2. BFS\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("DFS Traversal starting from node %d:\n", start);
            dfs(start);
            break;
        case 2:
            printf("BFS Traversal starting from node %d:\n", start);
            f = 0; r = -1;  // Initialize the queue pointers
            bfs(start);
            break;
        default:
            printf("Invalid choice!\n");
            exit(0);
    }

    return 0;
}
