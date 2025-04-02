#include <stdio.h>
#include <limits.h> // For INT_MAX

#define MAX 10 // Max number of vertices

int cost[MAX][MAX], vt[MAX], et[MAX][2], vis[MAX];
int sum = 0, x = 0, e = 0, n;

void prims();

int main() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 999 for no connection):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
        vis[i] = 0;
    }

    prims();

    printf("\nEdges of the Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        printf("%d - %d\n", et[i][0], et[i][1]);
    }
    printf("Total weight of MST = %d\n", sum);

    return 0;
}

void prims() {
    int min, u, v, k, m;

    // Start from the first vertex
    vt[x] = 0;
    vis[0] = 1;

    for (int s = 0; s < n - 1; s++) {
        min = INT_MAX; // Use large number as infinity
        for (int j = 0; j <= x; j++) {
            k = vt[j];

            for (m = 0; m < n; m++) {
                if (!vis[m] && cost[k][m] < min) {
                    min = cost[k][m];
                    u = k;
                    v = m;
                }
            }
        }

        vt[++x] = v;
        et[e][0] = u;
        et[e][1] = v;
        e++;
        vis[v] = 1;
        sum += min;
    }
}
