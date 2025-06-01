#include <stdio.h>
#define max 9999

int n;

/*void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }
    printPath(parent, parent[j]);
    printf("%d ", j);
}*/

void dijkstra(int graph[n][n], int src) {
    int dist[10], vis[10], parent[10];

    for (int i = 0; i < n; i++) {
        dist[i] = max;
        vis[i] = 0;
        //parent[i] = -1;  // No parent yet
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1, min = max;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && dist[v] < min) {
                min = dist[v];
                u = v;
            }
        }

        if (u == -1) break; // No reachable vertex remaining

        vis[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!vis[v] && graph[u][v] && dist[v] > dist[u] + graph[u][v]) {
                dist[v] = dist[u] + graph[u][v];
                //parent[v] = u; // Set u as parent of v
            }
        }
    }

    printf("Node\tDistance\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t", i, dist[i]);
        //printPath(parent, i);
        printf("\n");
    }
}

int main() {
    printf("Enter no of nodes: ");
    scanf("%d", &n);
    int graph[n][n];
    printf("Enter adj matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int src;
    printf("Enter src: ");
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}
