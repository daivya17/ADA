#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 5
int v;

int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;
    for (int u = 0; u < v; u++)
        if (!visited[u] && dist[u] <= min)
            min = dist[u], min_index = u;
    return min_index;
}

void printSolution(int dist[], int n) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < v; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < v - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;
        for (int w = 0; w < v; w++) {
            if (!visited[w] && graph[u][w] > 0 && dist[u] != INT_MAX && dist[u] + graph[u][w] < dist[w]) {
                dist[w] = dist[u] + graph[u][w];
            }
        }
    }
    printSolution(dist, v);
}

int main() {
    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &v);
    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int source;
    printf("Enter source node (0 to %d): ", v - 1);
    scanf("%d", &source);

    dijkstra(graph, source);
    return 0;
}
