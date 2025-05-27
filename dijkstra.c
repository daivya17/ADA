#include<stdio.h>
#define max 9999
int n;
void dijkstra(int graph[n][n],int src){
    int dist[10],vis[10];
    for(int i=0;i<n;i++){
        dist[i] = max;
        vis[i] = 0;
    }
    dist[src] = 0;
    for(int count = 0;count <n-1;count++){ //findmin()
        int u = -1,min = max;
        for(int v=0;v<n;v++){
            if(!vis[v] && dist[v]<min){
                min = dist[v];
                u=v;
            }
        }
        vis[u] = 1; //main
        for(int v=0;v<n;v++){
            if(!vis[v] && graph[u][v] && dist[v] > dist[u]+graph[u][v]){
                dist[v] = dist[u]+graph[u][v];
            }
        }
    }
    printf("Node DIstance from src %d\n",src); //display()
    for(int i=0;i<n;i++){ 
        printf("%d\t%d\n",i,dist[i]);
    }
}
int main(){
    printf("enter no of nodes:");
    scanf("%d",&n);
    int graph[n][n];
    printf("enter adj matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    int src;
    printf("enter src:");
    scanf("%d",&src);
    dijkstra(graph,src);
    return 0;
}
