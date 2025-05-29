#include <stdio.h>
#define MAX 100
int u[MAX], v[MAX], w[MAX];
int parent[MAX];
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort_edges(int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (w[j] > w[j+1]) {
                swap(&w[j], &w[j+1]);
                swap(&u[j], &u[j+1]);
                swap(&v[j], &v[j+1]);
            }
        }
    }
}
int main() {
    int n, e;
    int total_cost = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
    }
    for (int i = 0; i < n; i++)
        parent[i] = i;
    sort_edges(e);
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < e; i++) {
        int a = find(u[i]);
        int b = find(v[i]);
        if (a != b) {
            printf("%d - %d (weight: %d)\n", u[i], v[i], w[i]);
            total_cost += w[i];
            union_set(a, b);
        }
    }
    printf("Total cost of MST: %d\n", total_cost);
    return 0;
}
