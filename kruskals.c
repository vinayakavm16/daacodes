#include <stdio.h>
#include <stdlib.h>

int i, j, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[10][10], parent[10];

int find(int);
int uni(int, int);

void main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999; // Represent no edge with a large number
            }
        }
    }

    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);//find function to get the root of the sets containing u and v.
        v = find(v);

        if (uni(u, v)) {//If u and v are in different sets (checked by uni(u, v)), includes this edge in the MST and prints it.
            printf("\n%d edge(%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999; // Mark the edge as visited
    }

    printf("\nMinimum cost = %d\n", mincost);
}

int find(int i) {// Traverses up the parent array until it finds the root of the set containing i.
    while (parent[i]) {
        i = parent[i];
    }
    return i;
}

int uni(int i, int j) {//. If i and j are in different sets, it unions them by setting parent[j] = i.
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}
