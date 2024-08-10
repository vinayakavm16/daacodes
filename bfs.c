#include <stdio.h>

int a[20][20], reached[20], q[20], n;
int f = 0, r = -1;  // Front and Rear pointers for the queue

void bfs(int v) {
    int i;
    q[++r] = v;  // Enqueue the starting node
    reached[v] = 1;/*Marks node v as visited.*/

    while (f <= r) {//continues as long as there are nodes in the queue (f is less than or equal to r).
         int no = q[f++];  // Dequeue a node
                           //Removes a node from the front of the queue (f) and assigns it to no.
                           //  Increments the front index f.
        printf("%d ", no);
        for (i = 0; i < n; i++) {
            if (a[no][i] && !reached[i]) {
                q[++r] = i;  // Enqueue the adjacent node i.e Adds the adjacent node i to the queue and increments the rear index r.
                reached[i] = 1;
            }
        }
    }
}

int main() {
    int start;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        reached[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    // Initialize the queue pointers
    f = 0;
    r = -1;

    bfs(start);

    return 0;
}
