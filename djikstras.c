#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10

void dijkstra(int n, int cost[MAX_VERTICES][MAX_VERTICES], int src) {
    int i, j, u, dis[MAX_VERTICES], vis[MAX_VERTICES], min;

    for(i = 0; i < n; i++) {
        dis[i] = INT_MAX;
        vis[i] = 0;
    }
    dis[src] = 0;

    for(i = 0; i < n - 1; i++) {
        min = INT_MAX;

        for(j = 0; j < n; j++) {
            if(!vis[j] && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        vis[u] = 1;

        for(j = 0; j < n; j++) {
            if(!vis[j] && cost[u][j] != -1 && dis[u] + cost[u][j] < dis[j]) {
                dis[j] = dis[u] + cost[u][j];
            }
        }
    }

    printf("Shortest path from vertex %d:\n", src + 1);
    for(i = 0; i < n; i++) {
        if(dis[i] == INT_MAX) {
            printf("%d -> %d = No path\n", src + 1, i + 1);
        } else {
            printf("%d -> %d = %d\n", src + 1, i + 1, dis[i]);
        }
    }
}

int main() {
    int n, src, i, j, cost[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use -1 for no direct edge):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0) {
                cost[i][j] = -1;
            }
        }
    }

    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(n, cost, src);

    return 0;
}
